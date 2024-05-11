#include "HLS/hls.h"
//#include "HLS/ac_fixed.h"
//#include "HLS/ac_fixed_math.h"

/* Coefficients:
   (Intercept)    -6.4097    
   x1              5.7431 
   x2             -8.6601 
   x3             0.11761 
   x4              17.346 
*/
//#define FEATURES_SIZE 4




// Avalon slave component
hls_avalon_slave_component
component float mlrc(hls_avalon_slave_memory_argument (FEATURES_SIZE*sizeof(float)) float* features) {
    // Initialize result with intercept
    float result = -6.410;
    // Feature array
    const float coefficients[FEATURES_SIZE] = {5.743000, -8.660000, 0.118000, 17.346000};
#pragma unroll
    // Compute the linear combination
    for (int i = 0; i < FEATURES_SIZE; i++) {
        result += (coefficients[i] * features[i]);
    }

    // Return the computed result
    return result;
}
