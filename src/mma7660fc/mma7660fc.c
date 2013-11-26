#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#include "../accel.h"

void mma7660fc_init(void)
{

}

void mma7660fc_on(void)
{

}

void mma7660fc_get(accel_t *data)
{
    data->x = 1;
    data->y = 1;
    data->z = 1;
}

void mma7660fc_off(void)
{

}

