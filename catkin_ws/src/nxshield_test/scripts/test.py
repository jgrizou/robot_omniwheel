#!/usr/bin/env python
import rospy
from std_msgs.msg import Empty
from std_msgs.msg import UInt16
from std_msgs.msg import Bool

motor_a1_speed_pub = rospy.Publisher('motor_a1_speed', UInt16)
motor_a1_brake_pub = rospy.Publisher('motor_a1_brake', Empty)
led_on_pub = rospy.Publisher('led_on', Empty)
led_off_pub = rospy.Publisher('led_off', Empty)

rospy.init_node("test")

def callback(data):
    push = data.data
    if push:
        print "button pushed"
        motor_a1_speed_pub.publish(UInt16(100))
        led_on_pub.publish(Empty())
    else:
        print "button released"
        motor_a1_brake_pub.publish(Empty())
        led_off_pub.publish(Empty())


if __name__ == "__main__":
    rospy.Subscriber("pushed", Bool, callback)
    rospy.spin()
