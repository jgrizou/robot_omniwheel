import os
import pty
import telnetlib
import threading


class SerialToTelnet(threading.Thread):
    def __init__(self, master, telnet):
        threading.Thread.__init__(self)
        self.daemon = True

        self.master = master
        self.telnet = telnet

    def run(self):
        while True:
            msg = os.read(self.master, 1)
            print "STT : "+ msg
            self.telnet.write(msg)


class TelnetToSerial(threading.Thread):
    def __init__(self, master, telnet):
        threading.Thread.__init__(self)
        self.daemon = True

        self.master = master
        self.telnet = telnet

    def flush(self):
        self.telnet.write("\n")
        print self.telnet.read_until("\n")

    def run(self):
        while True:
            msg = self.telnet.read_some()
            print "TTS : " + msg
            os.write(self.master,msg)



if __name__ == "__main__":

    master, slave = pty.openpty()
    s_name = os.ttyname(slave)
    print s_name

    tn = telnetlib.Telnet('192.168.0.10',2000)

    push = SerialToTelnet(master, tn)
    pull = TelnetToSerial(master, tn)

    push.start()
    pull.start()

    import time
    time.sleep(1)

    import serial
    ser = serial.Serial(port=s_name,baudrate=57600)

#    pull.flush()
    push.join()
    pull.join()

#    while True:
#        msg = raw_input("Type your message : ")
#        ser.write(msg + '\n')
#        print ser.readline()




