import rospy

import time

from collections import deque

class Publisher(object):
    def __init__(self):
        self.publishers = {}
        self.queue = deque()

    def add_publisher(self, alias, publisher):
        self.publishers[alias] = publisher

    def publish(self):
        while len(self.queue) > 0:
            alias, msg = self.queue.popleft()
            print "publishing " + alias + ":" + str(msg)
            self.publishers[alias].publish(msg)

    def append(self, alias, msg):
        self.queue.append((alias, msg))
