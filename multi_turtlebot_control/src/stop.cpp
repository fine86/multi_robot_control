#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char **argv){
	ros::init(argc, argv, "linear_control_publish");
	ros::NodeHandle nh;

	ros::Publisher turtle_1_pub = nh.advertise<geometry_msgs::Twist>("/turtlebot_1/cmd_vel", 1000);
	ros::Publisher turtle_2_pub = nh.advertise<geometry_msgs::Twist>("/turtlebot_2/cmd_vel", 1000);
	ros::Publisher turtle_3_pub = nh.advertise<geometry_msgs::Twist>("/turtlebot_3/cmd_vel", 1000);

	ros::Rate loop_rate(10);

	geometry_msgs::Twist msg_1, msg_2, msg_3;

	while(ros::ok()){
		msg_1.linear.x = 0;
		msg_2.linear.x = 0;
		msg_3.linear.x = 0;

		turtle_1_pub.publish(msg_1);
		turtle_2_pub.publish(msg_2);
		turtle_3_pub.publish(msg_3);

		ros::spinOnce();
		loop_rate.sleep();
	}

	msg_1.linear.x = 0;
	msg_2.linear.x = 0;
	msg_3.linear.x = 0;

	turtle_1_pub.publish(msg_1);
	turtle_2_pub.publish(msg_2);
	turtle_3_pub.publish(msg_3);

	ros::spinOnce();
}
