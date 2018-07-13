/** Cartesian to Polar coordinates */
#include <cmath>

void polar(float x, float y, float *r, float *theta) {
    *r = sqrt(x * x + y * y);
    *theta = atan2(y, x);
}
