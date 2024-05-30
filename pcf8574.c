#include <linux/i2c-dev.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#define I2C_ADDR 0x21
#define LED_ON  0x1F
#define LED_OFF 0xFF
#define BUTTON_1 0xFE
#define BUTTON_2 0xFD
#define BUTTON_3 0xFB
#define BUTTON_4 0xF7
#define BUTTON_5 0xEF

int main (void) {
    int value;
    int fd; 
   
    fd = open("/dev/i2c-1", O_RDWR);
    if (fd < 0) {
        printf("Error opening file: %d\n", strerror(errno));
        return 1;
    }   
    if (ioctl(fd, I2C_SLAVE, I2C_ADDR) < 0) {
        printf("ioctl error: %d\n", strerror(errno));
        return 1;
    }   
    while(1)
    {   
        // value = LED_ON;
        // if( write( fd , &value, 1 ) != 1) {
        //     printf("Error writing file: %d\n", strerror(errno));
        // }    
        // printf("value = %x\n", value);
        // sleep(1); 

        // value = LED_OFF;
        // if( write( fd , &value, 1 ) != 1) {
        //     printf("Error writing file: %d\n", strerror(errno));
        // }    
        // printf("value = %x\n", value);
        // sleep(1); 

        value = 0;
        if (read(fd, &value, 1) != 1) {
            printf("Error reading file: %d\n", strerror(errno));
        }
        printf("Button value = %x\n", value);
        sleep(1);
    }
    return 0;
}