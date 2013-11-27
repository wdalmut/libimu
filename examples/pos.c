#include <stdio.h>
#include <stdlib.h>

#include "accel.h"

int main(void)
{
    accel_t t;

    accel_init();
    accel_on();
    while(1) {
        accel_get(&t);
        printf("x: %3.5f y: %3.5f z: %3.5f", t.x, t.y, t.z);
        printf("\r");
    }

    return EXIT_SUCCESS;
}
