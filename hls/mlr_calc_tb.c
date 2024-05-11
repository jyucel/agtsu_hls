/**
 * @file mlr2_tb.c
 * @brief Test bench for the machine learning component predicting ice cream sales using multiple linear regression.
 *
 * @details
 * This test bench is designed to validate the functionality of the multiple linear regression component
 * implemented in mlr_calc.h. The test bench compares the predicted ice cream sales from the component
 * against expected values calculated directly within the test bench.
 *
 * - **Functionality**: Computes ice cream sales prediction using both the component function and a direct calculation.
 * - **Comparison**: Compares the results from the component against the predicted values from the direct calculation. The features provided
 *                   comes from the real data. The actual value is 206.
 * - **Validation**: The test bench validates the component by ensuring the results match within an acceptable error margin.
 * 
 *
 * @note This project is part of the Ingenjörsuppgift course at AGSTU.
 * 
 * @date 2024-05-11
 * @version 1.0
 * @auth John Yucel
 */

#include <stdio.h>
#include "mlr_calc.h"

/**
 * @brief Computes ice cream sales using a direct calculation based on given features.
 *
 * @param sample A pointer to an array of feature values (temperature, wind speed, rain, and price).
 * @param result_tb A pointer to the float where the computed result will be stored.
 */
void mlr_tb(float* sample, float* result_tb) {
    const float coefficients[FEATURES_SIZE] = {5.7431, -8.6601, 0.1176, 17.3460};
    const float intercept = -6.4097;
    *result_tb = intercept;
    for (int i = 0; i < FEATURES_SIZE; i++) {
        *result_tb += coefficients[i] * sample[i];
    }
}

int main() {
    
    float features_tb[4] = {24.29623859987456, 1.657108910650813, 318.88886525770835, 3};  // Real value is 206

    float result_tb;  // Declare result_tb
    mlr_tb(features, &result_tb);  // Pass the address of result_tb to mlr_tb
    float predicted_sales = mlrc(features);
  
    printf("Predicted (float)    : Ice Cream Sales: %lf\n", result_tb); 
    printf("Predicted (component): Ice Cream Sales: %lf\n", predicted_sales);
    printf("Error (compared to float): %lf (%lf%%)\n", 
       (result_tb - predicted_sales), 
       ((result_tb - predicted_sales) / result_tb) * 100);

    return 0;
}
