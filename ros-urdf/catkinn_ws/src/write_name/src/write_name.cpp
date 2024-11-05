#include <ros/ros.h>
#include <std_msgs/Float64.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "write_name_controller");
    ros::NodeHandle nh;
    ros::Publisher joint_pub = nh.advertise<std_msgs::Float64>("/write_name/joint_position", 10);
    ros::Rate loop_rate(10);

    while (ros::ok()) {
        std_msgs::Float64 msg;
        msg.data = 1.0;  // example position
        joint_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
