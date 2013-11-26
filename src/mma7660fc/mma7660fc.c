#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
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
#define _I2C_DEV_PORTNAME "/dev/i2c-0"

/**
 * Initialize the peripheral
 *
 * Open the port and configure the slave address
 */
void mma7660fc_init(void)
{
    int i2cdev = open(_I2C_DEV_PORTNAME, O_RDWR);
    if (i2cdev == -1)
    {
        //TODO handle errors
    }

    if (ioctl(i2cdev, I2C_SLAVE, MMA7660_ADDR) < 0)
    {
        //TODO handle errors
    }
}

void mma7660fc_on(void)
{

}

void mma7660fc_get(accel_t *data)
{
    data->x = 1;
    data->y = 1;
    data->z = 2;
}

void mma7660fc_off(void)
{

    close(i2cdev);
}

