#!/usr/bin/env python
import termios, fcntl, sys, os
import contextlib
import rospy
import math
import tf
import time
import numpy as np
from std_msgs.msg import *
from nav_msgs.msg import *
from sensor_msgs.msg import *
from geometry_msgs.msg import *
from rosgraph_msgs.msg import *
import redis

r = redis.Redis(
    host='localhost',
    port=6379)

class Redis_Converter():
    def __init__(self):
        self.sub = []
        for topic in ["x_set","y_set","z_set","yaw_set","roll_set","pitch_set"]:
            self.sub.append(rospy.Subscriber(rospy.get_param("~"+topic),Float64, self.set_callback, callback_args=topic, queue_size=1))
    def set_callback(self,msg,topic_name):
        r.set(topic_name,msg)

def main():
    rospy.init_node('Redis_Converter')
    m = Redis_Converter()
    rospy.spin()

if __name__ == "__main__":
    main()
