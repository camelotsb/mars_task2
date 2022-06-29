#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>
#include <std_msgs/Bool.h>
#include <iomanip>

void sensorDataRecieved(const geometry_msgs::Twist& msg) {
    float k=msg.linear.x;
    ros::NodeHandle r;
    ros::Publisher e_pub= r.advertise<std_msgs::Bool>("epath",1000);
    std_msgs::Bool de;
    
    if (k>5)
    {
        ROS_INFO_STREAM("The rover is safe to proceed: 1");
        de.data=true;
        e_pub.publish(de);
    }
    else{
        ROS_INFO_STREAM("Danger !! the rover will collide in "<<msg.linear.x<<"centimeters.");
        
        de.data=false;
        e_pub.publish(de);
    }
}

int main(int argc,char **argv){

    ros::init(argc,argv,"subscribe_to_sensor");
    ros::NodeHandle nh;

    ros::Subscriber sub=nh.subscribe("randomsensor",1000,&sensorDataRecieved);
    ros::spin();
}
