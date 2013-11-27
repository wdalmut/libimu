#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#include "mma7660fc.h"

#include "../accel.h"

/**
 * Global pointer to the device
 */
int i2cdev;

/**
 * The port name
 */
#define _I2C_DEV_PORTNAME "/dev/i2c-1"

/**
 * Initialize the peripheral
 *
 * Open the port and configure the slave address
 */
void mma7660fc_init(void)
{
    i2cdev = open(_I2C_DEV_PORTNAME, O_RDWR);
    if (i2cdev == -1)
    {
        //TODO handle errors
    }
}

void mma7660fc_on(void)
{
    uint8_t buffer[2];

    buffer[0] = MMA7660_MODE;
    buffer[1] = MMA7660_ACTIVE;
    ioctl(i2cdev, I2C_SLAVE, MMA7660_ADDR);
    write(i2cdev, buffer, 2);
}

void mma7660fc_get(accel_t *data)
{
    uint8_t buffer[11];

    ioctl(i2cdev, I2C_SLAVE, MMA7660_ADDR);
    read(i2cdev, buffer, 11);

    data->x = mma7660fc_convert(buffer[0]);
    data->y = mma7660fc_convert(buffer[1]);
    data->z = mma7660fc_convert(buffer[2]);
}

void mma7660fc_off(void)
{
    close(i2cdev);
}

double mma7660fc_convert(uint8_t value)
{
    if ((value & 0x60) > 0) {
        value = ((~value + 1) & 0x1F); //ca2
    }

    double value_f = ((double)value) * 0.047; // accel

    return value_f;
}

