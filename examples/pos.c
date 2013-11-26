#include <stdio.h>
#include <stdlib.h>

#include "accel.h"

int main(void)
{
    accel_t t;

    accel_get(&t);

    printf("%lf, %lf, %lf\n", t.x, t.y, t.z);

    return EXIT_SUCCESS;
}
