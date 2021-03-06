/**** Bruno DATO M1 EEA ISTR Université Paul Sabatier Toulouse III 2016 ****/

#include <ros/ros.h>
#include "baxter_right_arm.h" 

#include "std_msgs/Bool.h"

#include "baxter_core_msgs/JointCommand.h"
#include "sensor_msgs/JointState.h"
#include "baxter_core_msgs/SolvePositionIK.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Quaternion.h"

#define PI 3.1416

// Constructeur
Baxter_right_arm::Baxter_right_arm(ros::NodeHandle noeud) 
{
	//Pub
	pub_joint_cmd = noeud.advertise<baxter_core_msgs::JointCommand>("/robot/limb/right/joint_command", 1);

	//Sub
	sub_joint_states = noeud.subscribe("/robot/joint_states", 1, &Baxter_right_arm::Callback_joint_states,this);

	//Srv
	client_inverse_kinematics = noeud.serviceClient<baxter_core_msgs::SolvePositionIK>("/ExternalTools/right/PositionKinematicsNode/IKService");

	// commande en mode position
	msg_JointCommand.mode = baxter_core_msgs::JointCommand::POSITION_MODE;
	//POSITION_MODE / VELOCITY_MODE / TORQUE_MODE / RAW_POSITION_MODE pour changer le mode

	// Initialisation du message de commande des angles
  	msg_JointCommand.names.push_back("right_s0");
  	msg_JointCommand.names.push_back("right_s1");
  	msg_JointCommand.names.push_back("right_e0");
  	msg_JointCommand.names.push_back("right_e1");
  	msg_JointCommand.names.push_back("right_w0");
  	msg_JointCommand.names.push_back("right_w1");
  	msg_JointCommand.names.push_back("right_w2");
	
	msg_JointCommand.command.resize(msg_JointCommand.names.size());

	// Angles en position 0
	for(size_t i = 0; i < msg_JointCommand.names.size(); i++) msg_JointCommand.command[i] = 0.0;


	// Initialisation capteurs //

	jointState.position.resize(17);
	jointState.velocity.resize(17);
	jointState.effort.resize(17);

	for(size_t i = 0; i < 17; i++)
	{
		jointState.position[i]=0;
		jointState.velocity[i]=0;
		jointState.effort[i]=0;
	}

}


// Destructeur
Baxter_right_arm::~Baxter_right_arm()
{
}


// Callbacks

void Baxter_right_arm::Callback_joint_states(const sensor_msgs::JointState& msg)
{
	jointState = msg ;
	//std::cout<<msg<<std::endl;
}





// Envoie des commandes

void Baxter_right_arm::Update()
{
	pub_joint_cmd.publish(msg_JointCommand);
}



// Commande bras

void Baxter_right_arm::Position(float right_s0, float right_s1, float right_e0, float right_e1, float right_w0, float right_w1, float right_w2)
{
	// commande en mode position
	msg_JointCommand.mode = baxter_core_msgs::JointCommand::POSITION_MODE;
	
	msg_JointCommand.command[0] = right_s0;
	msg_JointCommand.command[1] = right_s1;
	msg_JointCommand.command[2] = right_e0;
	msg_JointCommand.command[3] = right_e1;
	msg_JointCommand.command[4] = right_w0;
	msg_JointCommand.command[5] = right_w1;
	msg_JointCommand.command[6] = right_w2;
}

void Baxter_right_arm::Position(float angle,int num)
{
	for(size_t i = 2; i < 8; i++) msg_JointCommand.command[i-2] = jointState.position[i];
	msg_JointCommand.command[num] = angle;
}




// Vague

void Baxter_right_arm::Position_sinu(float position,float compteur)
{
	float d[3] ;

	for(size_t i = 1; i <= 3; i++) d[i-1] = sin(compteur+(i*2*PI/3))/5;
	
	Baxter_right_arm::Position(0-0.7*sin(0.1*(compteur-PI)), -position-0.5+0.2*d[0], +0, +position+0.4-1.6*d[1], -0, +position-5*d[2], -0);
}



void Baxter_right_arm::IK(float x, float y, float z, float psy, float teta, float phi)
{
	baxter_core_msgs::SolvePositionIK srv;
	sensor_msgs::JointState JointState ;

	geometry_msgs::PoseStamped PoseStamped;

	PoseStamped.pose.position.x = x ;
	PoseStamped.pose.position.y = y ;
	PoseStamped.pose.position.z = z ;

	//c1=cos(psy/2)
	//c2=cos(teta/2)
	//c3=cos(phi/2)

	//s1=sin(psy/2)
	//s2=sin(teta/2)
	//s3=sin(phi/2)

	PoseStamped.pose.orientation.x = (sin(psy/2)*sin(teta/2)*cos(phi/2)) - (cos(psy/2)*cos(teta/2)*sin(phi/2)) ;
	PoseStamped.pose.orientation.y = (sin(psy/2)*cos(teta/2)*cos(phi/2)) - (cos(psy/2)*sin(teta/2)*sin(phi/2)) ;
	PoseStamped.pose.orientation.z = (cos(psy/2)*sin(teta/2)*cos(phi/2)) - (sin(psy/2)*cos(teta/2)*sin(phi/2)) ;
	PoseStamped.pose.orientation.w = (cos(psy/2)*cos(teta/2)*cos(phi/2)) - (sin(psy/2)*sin(teta/2)*sin(phi/2)) ;

	//std::cout<<PoseStamped.pose.orientation.x<<std::endl;
	//std::cout<<PoseStamped.pose.orientation.y<<std::endl;
	//std::cout<<PoseStamped.pose.orientation.z<<std::endl;
	//std::cout<<PoseStamped.pose.orientation.w<<std::endl;

	PoseStamped.header.seq = 0 ;
	PoseStamped.header.stamp.sec = 0 ;
	PoseStamped.header.frame_id = "base" ;

	srv.request.pose_stamp.resize(1);
	srv.request.pose_stamp[0] = PoseStamped;
	srv.request.seed_mode  = srv.request.SEED_AUTO;

	if (client_inverse_kinematics.call(srv)) 
	{	
		//std::cout<<srv.response<<std::endl;
		msg_JointCommand.command = srv.response.joints[0].position;
	}
	else {ROS_ERROR("Failed to call service IK");}
}



