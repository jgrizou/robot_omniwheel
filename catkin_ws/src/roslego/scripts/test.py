#!/usr/bin/env python
import rospy
from std_msgs.msg import UInt16
from std_msgs.msg import Empty

import sys
import time
import numpy as np

import legoros
import omni

rospy.init_node("roslego")

P = omni.Platform()

B1 = legoros.Button(1)
B2 = legoros.Button(2)

Bat = legoros.Battery()

Ahrs = legoros.AHRS()

Trigger = legoros.EndLoop()

set_loop_delay_pub = rospy.Publisher('set_loop_delay', UInt16)

goal_yaw = 0.0

def event_B1(state):
    if state:
        print "button 1 pushed"
        set_loop_delay_pub.publish(20)
    else:
        print "button 1 released"
        set_loop_delay_pub.publish(200)

B1.add_callback(event_B1)

def event_B2(state):
    if state:
        print "button 2 pushed"
        P.rotate_unlimited(1, 50)
    else:
        print "button 2 released"
        P.stop()

B2.add_callback(event_B2)


def LoopAction():
    delta_yaw = goal_yaw - Ahrs.yaw
    P.rotate_unlimited(np.sign(delta_yaw), abs(delta_yaw)/4)

Trigger.add_callback(LoopAction)

# to investigate, the use of a service would be perfect here (an empty service would do)
#force_all_publish_pub = rospy.Publisher('force_all_publish', Empty)
#force_all_publish_pub.publish(Empty())


while not rospy.is_shutdown():

    print Bat.millivolts
    print Ahrs.get_ahrs_value()

    time.sleep(1)

