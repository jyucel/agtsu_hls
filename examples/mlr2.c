/**
 * @file mlr2.c
 * @brief Machine learning component for predicting ice cream sales using multiple linear regression.
 *
 * @details
 * This component predicts ice cream sales based on four features: temperature, rainfall, advertising, sunny hours and price.
 * It is implemented in C and synthesized using the Intel® High-Level Synthesis (HLS) tool.
 * 
 * - **Implementation**: The component is designed as an Avalon slave.
 * - **Features**: Utilizes temperature, rainfall, advertising, and sunny hours as input features.
 * - **Testing**: A testbench is used to validate the component by comparing the predicted ice cream sales against the expected values.
 * 
 * @note This project is part of the Ingenjörsuppgift course HLS at AGSTU.
 * 
 * @date 2024-05-11
 * @author 
 * John Yucel
 */


#include "hls_mlr.h"
#include <io.h>
#include <stdio.h>
#include "system.h"
#include "alt_types.h"

#define  num_features 4

// function for verification/execution time comparison
void mlr_tb(float* sample, float* result_tb) {
   float coefficients[num_features] = {5.7431, -8.6601, 0.1176, 17.3460};
    const float intercept = -6.4097;
     *result_tb = intercept;
    for (int i = 0; i < num_features; i++) {
        *result_tb += coefficients[i] * sample[i];
    }
}

int main(){
   
    float mlrc_result;
    float result_tb;  // Declare result_tb



    // Disable interrupt and clear interrupt status register
    mlrc_disable_interrupt();
    mlrc_clear_done_status();

    for (int i=0;i<num_features;i++){
    	mlrc_write(i*sizeof(alt_32), *(alt_32 *) (&features[i]));
    }

    while (mlrc_busy()){}
    mlrc_start();

    while (!(mlrc_done())){}

   *(alt_32*) (&mlrc_result) = mlrc_returndata();

    // Call comparison function
     mlr_tb(features, &result_tb);
    // Check results
     printf("Predicted (float)    : Ice Cream Sales: %lf\n", result_tb);
     printf("Predicted (component): Ice Cream Sales: %lf\n", mlrc_result);
     printf("Error (compared to float): %lf (%lf%%)\n",
        (result_tb - mlrc_result),
        ((result_tb - mlrc_result) / result_tb) * 100);

     return 0;
 }
