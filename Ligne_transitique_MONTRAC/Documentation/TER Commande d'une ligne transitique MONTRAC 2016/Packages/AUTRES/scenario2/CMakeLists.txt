cmake_minimum_required(VERSION 2.8.3)
project(scenario1)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend and a run_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependencies might have been
##     pulled in transitively but can be declared for certainty nonetheless:
##     * add a build_depend tag for "message_generation"
##     * add a run_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
 add_message_files(
   FILES
   EntreesSorties.msg
#   Message2.msg
 )

## Generate services in the 'srv' folder
 add_service_files(
   FILES
   DemandeTrajet.srv
   Etat_API.srv
)

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   std_msgs
 )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES scenario1
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
	${catkin_INCLUDE_DIRS}
	/usr/local/include/
)

## Declare a cpp library
# add_library(scenario1
#   src/${PROJECT_NAME}/scenario1.cpp
# )

## Declare a cpp executable
# add_executable(scenario1_node src/scenario1_node.cpp)

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
# add_dependencies(scenario1_node scenario1_generate_messages_cpp)

## Specify libraries to link a library or executable target against
# target_link_libraries(scenario1_node
#   ${catkin_LIBRARIES}
# )

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS scenario1 scenario1_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_scenario1.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)

#add_executable(code_serv src/code_serv.cpp)
#add_dependencies(code_serv scenario1_gencpp)
#target_link_libraries(code_serv ${catkin_LIBRARIES} modbus)

#add_executable(code_client src/code_client.cpp)
#add_dependencies(code_client scenario1_gencpp)
#target_link_libraries(code_client ${catkin_LIBRARIES} modbus)

add_executable(publisher_zone1 src/publisher_zone1.cpp)
add_dependencies(publisher_zone1 scenario1_gencpp)
target_link_libraries(publisher_zone1 ${catkin_LIBRARIES} modbus)

add_executable(API_listener src/API_listener.cpp)
add_dependencies(API_listener scenario1_gencpp)
target_link_libraries(API_listener ${catkin_LIBRARIES})

add_executable(Test_aiguillage src/Test_aiguillage.cpp)
add_dependencies(Test_aiguillage scenario1_gencpp)
target_link_libraries(Test_aiguillage ${catkin_LIBRARIES} modbus)

add_executable(service_etat_API src/service_etat_API.cpp)
add_dependencies(service_etat_API scenario1_gencpp)
target_link_libraries(service_etat_API ${catkin_LIBRARIES} modbus)

add_executable(client_etat_API src/client_etat_API.cpp)
add_dependencies(client_etat_API scenario1_gencpp)
target_link_libraries(client_etat_API ${catkin_LIBRARIES} )

add_executable(API1 src/API1.cpp)
add_dependencies(API1 scenario1_gencpp)
target_link_libraries(API1 ${catkin_LIBRARIES} )

add_executable(commande src/commande.cpp)
add_dependencies(commande scenario1_gencpp)
target_link_libraries(commande ${catkin_LIBRARIES} )


