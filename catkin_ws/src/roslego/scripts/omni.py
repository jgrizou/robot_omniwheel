import numpy as np

import legoros

#         M1              0/360
#         |                 |
#         |                 |
# M3 -----------M4   270----------90
#         |                 |
#         |                 |
#         M2               180

class Platform(object):
    def __init__(self):
        self.M1 = legoros.Motor(1)
        self.M2 = legoros.Motor(2)
        self.M3 = legoros.Motor(3)
        self.M4 = legoros.Motor(4)

    def compute_command_from_angle(self, radian, max_speed):
        cos_value = np.cos(np.pi / 2. - radian)
        sin_value = np.sin(np.pi / 2. - radian)
        speed = np.array([cos_value, cos_value, sin_value, sin_value]) * max_speed
        direction = np.array([1, -1, 1, -1] * np.sign(speed))
        direction = direction == 1
        return np.round(np.abs(speed)), direction

    def run_seconds(self, seconds, radian, max_speed):
        speed, direction = self.compute_command_from_angle(radian, max_speed)
        self.M1.run_seconds(seconds, speed[0], direction[0])
        self.M2.run_seconds(seconds, speed[1], direction[1])
        self.M3.run_seconds(seconds, speed[2], direction[2])
        self.M4.run_seconds(seconds, speed[3], direction[3])

    def run_unlimited(self, radian, max_speed):
        speed, direction = self.compute_command_from_angle(radian, max_speed)
        self.M1.run_unlimited(speed[0], direction[0])
        self.M2.run_unlimited(speed[1], direction[1])
        self.M3.run_unlimited(speed[2], direction[2])
        self.M4.run_unlimited(speed[3], direction[3])

    def stop(self):
        self.M1.stop()
        self.M2.stop()
        self.M3.stop()
        self.M4.stop()

    def rotate(self, wheel_degree, speed=50):
        if wheel_degree > 0:
            direction = 1
        else:
            direction = 0

        degree = int(abs(wheel_degree))

        self.M1.run_degrees(degree, speed, direction)
        self.M2.run_degrees(degree, speed, direction)
        self.M3.run_degrees(degree, speed, direction)
        self.M4.run_degrees(degree, speed, direction)


    def rotate_unlimited(self, direction, speed=50):
        if direction < 0:
            direction = 0
        self.M1.run_unlimited(speed, direction)
        self.M2.run_unlimited(speed, direction)
        self.M3.run_unlimited(speed, direction)
        self.M4.run_unlimited(speed, direction)


if __name__ == "__main__":

    import rospy
    from std_msgs.msg import UInt16

    import time
    import legoros

    import numpy as np

    rospy.init_node("roslego")
    set_loop_delay_pub = rospy.Publisher('set_loop_delay', UInt16)
    set_loop_delay_pub.publish(50)

    P = Platform()

    Bat = legoros.Battery()

    duration = 0.2
    fraction = 16
    speed = 50

    print Bat.millivolts
    time.sleep(1)

    for i in range(2*fraction):
        P.run_unlimited(i * np.pi / fraction, speed)
        print Bat.millivolts
        time.sleep(duration)

    P.stop()
    time.sleep(duration)
    P.stop()
