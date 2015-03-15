import rospy
from std_msgs.msg import Empty
from std_msgs.msg import Bool
from std_msgs.msg import Int32
from std_msgs.msg import UInt16
from roslego.msg import motor_action
from roslego.msg import ahrs

class EndLoop(object):
    def __init__(self):
        self.callback_list = []
        rospy.Subscriber("end_publishing", Empty, self.callback_callbacks)

    def callback_callbacks(self, data):
        [c() for c in self.callback_list]

    def add_callback(self, callback):
        self.callback_list.append(callback)


class AHRS(object):
    def __init__(self):
        self.yaw = 0.0
        self.pitch = 0.0
        self.roll = 0.0
        rospy.Subscriber("ahrs_value", ahrs, self.callback_ahrs)

    def callback_ahrs(self, data):
        self.yaw = data.yaw
        self.pitch = data.pitch
        self.roll = data.pitch

    def get_ahrs_value(self):
        return (self.yaw, self.pitch, self.roll)

class Motor(object):
    def __init__(self, motor_id):
        self.motor_id = motor_id
        self.position = None
        rospy.Subscriber("motor_{}_position".format(motor_id), Int32, self.callback_position)
        self.motor_action_pub = rospy.Publisher('motor_action', motor_action)

    def callback_position(self, data):
        self.position = data.data

    def run_degrees(self, degrees, speed=100, direction=1):
        if speed == 0: #temporary until better solution found
            self.motor_action_pub.publish(motor_action(self.motor_id, 6, 0, 0, False))
        else:
            self.motor_action_pub.publish(motor_action(self.motor_id, 1, degrees, speed, direction))

    def run_rotations(self, rotations, speed=100, direction=1):
        if speed == 0: #temporary until better solution found
            self.motor_action_pub.publish(motor_action(self.motor_id, 6, 0, 0, False))
        else:
            self.motor_action_pub.publish(motor_action(self.motor_id, 2, rotations, speed, direction))

    def run_seconds(self, seconds, speed=100, direction=1):
        if speed == 0: #temporary until better solution found
            self.motor_action_pub.publish(motor_action(self.motor_id, 6, 0, 0, False))
        else:
            self.motor_action_pub.publish(motor_action(self.motor_id, 3, seconds, speed, direction))

    def run_tachometer(self, tachometer, speed=100, direction=1):
        if speed == 0: #temporary until better solution found
            self.motor_action_pub.publish(motor_action(self.motor_id, 6, 0, 0, False))
        else:
            self.motor_action_pub.publish(motor_action(self.motor_id, 4, tachometer, speed, direction))

    def run_unlimited(self, speed=100, direction=1):
        if speed == 0: #temporary until better solution found
            self.motor_action_pub.publish(motor_action(self.motor_id, 6, 0, 0, False))
        else:
            self.motor_action_pub.publish(motor_action(self.motor_id, 5, 0, speed, direction))

    def stop(self):
        self.motor_action_pub.publish(motor_action(self.motor_id, 6, 0, 0, False))


class Button(object):
    def __init__(self, button_id):
        self.button_id = button_id

        self.state = None
        rospy.Subscriber("button_{}_state".format(button_id), Bool, self.callback_state)

        self.callbacks = []

    def callback_state(self, data):
        self.state = data.data
        for c in self.callbacks:
            c(self.state)

    def add_callback(self, function):
        self.callbacks.append(function)

class Battery(object):
    def __init__(self):
        self.millivolts = None
        rospy.Subscriber("battery_voltage", UInt16, self.callback_voltage)

    def callback_voltage(self, data):
        self.millivolts = data.data








