
#include "misc.h"
#include <math.h>

int massRadius(double m) {
    int rad = (int)(2 * log(4.0 * m + 1.0));

    if (rad < 1)
        rad = 1;
    if (rad > 64)
        rad = 64;

    // TODO spthick
    return rad /*+ spthick/2*/;
}

int sphereSize(int rad) {
    rad = (25 + (2 * rad)) / 2;
    if (rad < 15)
        rad = 15;
    int size = 0;
    if (rad * 2 >= 30)
        size = ((rad * 2) - 30) / 10;
    if (size > 4)
        size = 4;
    return size;
}

int sphereRadius(int size) {
    return (size * 10 + 30) / 2;
}
