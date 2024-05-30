import os
import time
import fcntl

I2C_ADDR = 0x20
LED_ON = 0xEF
LED_OFF = 0xFF
I2C_SLAVE = 0x0703

value = LED_OFF

# Open the I2C device
fd = os.open("/dev/i2c-1", os.O_RDWR)
if fd < 0:
    print(f"Error opening file: {os.strerror(fd)}")
    exit(1)

# Set the I2C slave address
try:
    fcntl.ioctl(fd, I2C_SLAVE, I2C_ADDR)
except IOError as e:
    print(f"ioctl error: {os.strerror(e.errno)}")
    os.close(fd)
    exit(1)

# Loop to toggle the LED
while True:
    if value == LED_ON:
        value = LED_OFF
    else:
        value = LED_ON
    
    result = os.write(fd, bytes([value]))
    if result != 1:
        print(f"Error writing file: {os.strerror(errno.errorcode[result])}")
    
    time.sleep(1)

# Close the file descriptor (this part will never be reached in the current loop)
os.close(fd)
