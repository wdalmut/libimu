#include <stdio.h>
#include <stdlib.h>

struct accel {
    double x;
    double y;
    double z;
};
typedef struct accel accel_t;

void accel_init(void);
void accel_on(void);
void accel_get(accel_t *);
void accel_off(void);

