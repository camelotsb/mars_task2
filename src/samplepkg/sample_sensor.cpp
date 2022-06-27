#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>

int main(int argc,char **argv){
    ros::init(argc,argv,"publish_rand_sensor");
    ros::NodeHandle nh;

    ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("randomsensor",1000);

    srand(time(0));

    ros::Rate rate(2);

    while(ros::ok()){
        geometry_msgs::Twist msg;
        msg.linear.x=(double(rand())/double(RAND_MAX))*100;

        pub.publish(msg);

            ROS_INFO_STREAM("sending the randsensor data:" <<" distance= "<<msg.linear.x);

            rate.sleep();
    }

}