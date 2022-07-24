#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>
#include <std_msgs/Bool.h>
#include <iomanip>
#include <iostream>

std_msgs::Bool vp;

void collisiond(const geometry_msgs::Twist& d){
    if (d.linear.x>5){
        vp.data=1;
    }
    else{
        vp.data=0;
    }
}

int main(int argc,char **argv){
    vp.data=1;
    ros::init(argc,argv,"subscribe_to_sensor");
    ros::NodeHandle nh;
    ros::Publisher pub=nh.advertise<std_msgs::Bool>("epath",1000);
    ros::Subscriber sub=nh.subscribe<geometry_msgs::Twist>("randomsensor",1000,&collisiond);
    while(ros::ok())
    {
        pub.publish(vp);
        ros::spinOnce();
    }
    return 0;   
}


