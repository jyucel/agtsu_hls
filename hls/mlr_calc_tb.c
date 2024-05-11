#include <stdio.h>
#include "mlr_calc.h"


void mlr_tb(float* sample, float* result_tb) {
   
    const int num_features = 4;
    const float coefficients[num_features] = {5.7431, -8.6601, 0.1176, 17.3460};
    const float intercept = -6.4097;
     *result_tb = intercept;
    for (int i = 0; i < num_features; i++) {
        *result_tb += coefficients[i] * sample[i];
    } 
}


int main() {
    float features[4] = {
        24.296,1.657,318.889,3.000  // Real value is 206
    };

    
    float features_tb[4] = {
        24.29623859987456,1.657108910650813,318.88886525770835,3  // Real value is 206
    };

    float result_tb;  // Declare result_tb
    mlr_tb(features_tb, &result_tb);  // Pass the address of result_tb to mlr_tb
    float predicted_sales = mlrc( features);

    printf("Predicted (float)    : Ice Cream Sales: %lf\n", result_tb); 
    printf("Predicted (component): Ice Cream Sales: %lf\n", predicted_sales);
    printf("Error (compared to float): %lf (%lf%%)\n", 
       (result_tb - predicted_sales), 
       ((result_tb - predicted_sales) / result_tb) * 100);

    return 0;
}
