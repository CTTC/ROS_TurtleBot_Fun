#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include <math.h>



int main(int argc, char **argv)
{
	ros::init(argc, argv, "talker");
	ros::NodeHandle n;
	ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("cmd_vel_mux/input/navi",10);
	ros::Rate loop_rate(5);

	geometry_msgs::Twist moveCmd;
	moveCmd.linear.x = 0.2;

	geometry_msgs::Twist turnCmd;
	turnCmd.angular.z = 45 * M_PI /  180;

	int count = 0;
	while (ros::ok())
	{
		ROS_INFO("Going Straight");
		for (int x = 0; x < 10; x++)
		{
			chatter_pub.publish(moveCmd);
			loop_rate.sleep();
		}
		ROS_INFO("Turning");
		for (int y = 0; y < 10; y++)
		{
			chatter_pub.publish(turnCmd);
			loop_rate.sleep();
		}
		count++;
		if (count == 4)
		{
			count = 0;
		}
		if (count = 0) 
		{
			ROS_INFO("TurtleBot should be close to the original starting position (but it's probably way off");
		}
	}
	return 0;
}
