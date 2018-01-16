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
        for topics in rospy.get_published_topics():
            try:
                exec("self.sub.append(rospy.Subscriber('%s',%s, self.topic_callback, callback_args='%s', queue_size=1))" % (topics[0],topics[1].split("/")[1],topics[0]))
            except:
                print("Topic type {0} does not exist".format(topics[1].split("/")[1]))
    def topic_callback(self,msg,topic_name):
        r.set(topic_name,msg)

def main():
    rospy.init_node('Redis_Converter')
    m = Redis_Converter()
    rospy.spin()

if __name__ == "__main__":
    main()
