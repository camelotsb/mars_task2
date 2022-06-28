#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>
#include <iomanip>

void sensorDataRecieved(const geometry_msgs::Twist& msg) {
    float k=msg.linear.x;
    if (k>5)
    {
        ROS_INFO_STREAM("The rover is safe to proceed: 1");
    }
    else{
        ROS_INFO_STREAM("Danger !! the rover will collide in "<<msg.linear.x<<"centimeters, change path");
    }
}

int main(int argc,char **argv){

    ros::init(argc,argv,"subscribe_to_sensor");
    ros::NodeHandle nh;

    ros::Subscriber sub=nh.subscribe("randomsensor",1000,&sensorDataRecieved);
    ros::spin();
}