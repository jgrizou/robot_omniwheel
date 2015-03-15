import time
import serial

# configure the serial connections (the parameters differs on the device you are connecting to)
ser = serial.Serial(
    port='/dev/ttyUSB0',
    baudrate=9600,
    parity=serial.PARITY_ODD,
    stopbits=serial.STOPBITS_TWO,
    bytesize=serial.SEVENBITS
)

ser.open()
ser.isOpen()

out = ''

while 1 :
    try:
        time.sleep(0.001)
        while ser.inWaiting() > 0:
            out += ser.read(1)

        if out != '' and out[-1] == '\n':
            print ">>" + out[:-2]
            out = ''

    except KeyboardInterrupt:
        ser.close()
        break
