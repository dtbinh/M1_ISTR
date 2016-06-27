// Generated by gencpp from file vrep_common/simRosSetFloatSignal.msg
// DO NOT EDIT!


#ifndef VREP_COMMON_MESSAGE_SIMROSSETFLOATSIGNAL_H
#define VREP_COMMON_MESSAGE_SIMROSSETFLOATSIGNAL_H

#include <ros/service_traits.h>


#include <vrep_common/simRosSetFloatSignalRequest.h>
#include <vrep_common/simRosSetFloatSignalResponse.h>


namespace vrep_common
{

struct simRosSetFloatSignal
{

typedef simRosSetFloatSignalRequest Request;
typedef simRosSetFloatSignalResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct simRosSetFloatSignal
} // namespace vrep_common


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::vrep_common::simRosSetFloatSignal > {
  static const char* value()
  {
    return "4f2e9ccc881d859d0bc9a087fe7a0075";
  }

  static const char* value(const ::vrep_common::simRosSetFloatSignal&) { return value(); }
};

template<>
struct DataType< ::vrep_common::simRosSetFloatSignal > {
  static const char* value()
  {
    return "vrep_common/simRosSetFloatSignal";
  }

  static const char* value(const ::vrep_common::simRosSetFloatSignal&) { return value(); }
};


// service_traits::MD5Sum< ::vrep_common::simRosSetFloatSignalRequest> should match 
// service_traits::MD5Sum< ::vrep_common::simRosSetFloatSignal > 
template<>
struct MD5Sum< ::vrep_common::simRosSetFloatSignalRequest>
{
  static const char* value()
  {
    return MD5Sum< ::vrep_common::simRosSetFloatSignal >::value();
  }
  static const char* value(const ::vrep_common::simRosSetFloatSignalRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::vrep_common::simRosSetFloatSignalRequest> should match 
// service_traits::DataType< ::vrep_common::simRosSetFloatSignal > 
template<>
struct DataType< ::vrep_common::simRosSetFloatSignalRequest>
{
  static const char* value()
  {
    return DataType< ::vrep_common::simRosSetFloatSignal >::value();
  }
  static const char* value(const ::vrep_common::simRosSetFloatSignalRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::vrep_common::simRosSetFloatSignalResponse> should match 
// service_traits::MD5Sum< ::vrep_common::simRosSetFloatSignal > 
template<>
struct MD5Sum< ::vrep_common::simRosSetFloatSignalResponse>
{
  static const char* value()
  {
    return MD5Sum< ::vrep_common::simRosSetFloatSignal >::value();
  }
  static const char* value(const ::vrep_common::simRosSetFloatSignalResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::vrep_common::simRosSetFloatSignalResponse> should match 
// service_traits::DataType< ::vrep_common::simRosSetFloatSignal > 
template<>
struct DataType< ::vrep_common::simRosSetFloatSignalResponse>
{
  static const char* value()
  {
    return DataType< ::vrep_common::simRosSetFloatSignal >::value();
  }
  static const char* value(const ::vrep_common::simRosSetFloatSignalResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // VREP_COMMON_MESSAGE_SIMROSSETFLOATSIGNAL_H