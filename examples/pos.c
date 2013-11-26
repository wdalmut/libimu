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
        printf("%c %3.5f %c %3.5f %c %3.5f", 'x', t.x, 'y', t.y, 'z', t.z);
        printf("\r");
    }

    return EXIT_SUCCESS;
}
