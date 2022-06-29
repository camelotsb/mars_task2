#include <ros/ros.h>
#include <stdlib.h>
#include <std_msgs/Bool.h>
#include <iomanip>

void emergencyBreakData(const std_msgs::Bool& msg)
{  
    bool k =msg.data ;
    ROS_INFO_STREAM("..");
    if(k)
    {
        ROS_INFO_STREAM("..");
    }
    else
    {
        ROS_INFO_STREAM("making new path plan");
    }
    
}

int main(int argc, char **argv )
{
    ros::init(argc,argv,"subscribe_to_emergency");
    ros::NodeHandle nh;

    ros::Subscriber sub=nh.subscribe("epath",1000,&emergencyBreakData);
    ros::spin();
}