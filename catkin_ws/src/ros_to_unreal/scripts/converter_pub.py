#!/usr/bin/env python
import termios, fcntl, sys, os
import contextlib
import rospy
import math
import tf
import time
import numpy as np
from nav_msgs.msg import Odometry
import redis

r = redis.Redis(
    host='localhost',
    port=6379)

class Redis_Converter():
    def __init__(self):
        self.pub = rospy.Publisher(rospy.get_param("~odometry"),Odometry,queue_size=1)


    def update_ros(self):
        odom = Odometry()
        odom.pose.pose.position.x = float(r.get('x_pos'))
        odom.pose.pose.position.y = float(r.get('y_pos'))
        odom.pose.pose.position.z = float(r.get('z_pos'))

        quaternion = tf.transformations.quaternion_from_euler(float(r.get("roll_pos")), float(r.get("pitch_pos")), float(r.get("yaw_pos")))
        #type(pose) = geometry_msgs.msg.Pose
        odom.pose.pose.orientation.x = quaternion[0]
        odom.pose.pose.orientation.y = quaternion[1]
        odom.pose.pose.orientation.z = quaternion[2]
        odom.pose.pose.orientation.w = quaternion[3]

        odom.twist.twist.linear.x = float(r.get("x_vel"))
        odom.twist.twist.linear.y = float(r.get("y_vel"))
        odom.twist.twist.linear.z = float(r.get("z_vel"))

        odom.twist.twist.angular.x = float(r.get("roll_vel"))
        odom.twist.twist.angular.y = float(r.get("pitch_vel"))
        odom.twist.twist.angular.z = float(r.get("yaw_vel"))
        odom.header.stamp = rospy.get_rostime()
        self.pub.publish(odom)


def main():
    rospy.init_node('Redis_Converter')
    m = Redis_Converter()
    # rospy.spin()
    r = rospy.Rate(40)
    while(not rospy.is_shutdown()):
        m.update_ros()
        r.sleep()

if __name__ == "__main__":
    main()
