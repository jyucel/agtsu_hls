#ifndef MLR_CALC_H
#define MLR_CALC_H
#include "HLS/hls.h"
#include "HLS/ac_fixed.h"
#include "HLS/ac_fixed_math.h"

//typedef ac_fixed<20, 10, true,AC_RND_CONV> ac_20_10_t;  // Appropriate type for coefficients
const int num_features = 4;
component float mlrc( float* features);

#endif // MLR_CALC_H
