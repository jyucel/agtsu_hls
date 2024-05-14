/**
 * @file mlr2.c
 * @Component for predicting ice cream sales using multiple linear regression.
 *
 * @details
 * This file contains the implementation of a machine learning component that predicts ice cream sales
 * based on four key features: temperature, rainfall, advertising expenditure, and sunny hours.
 * The model uses predefined coefficients derived from a multiple linear regression analysis.
 * The component is designed to be synthesized using the Intel® High-Level Synthesis (HLS) tool.
 *
 * - **Coefficients**:
 *   - Intercept: -6.4097
 *   - Temperature (x1): 5.7431
 *   - Rainfall (x2): -8.6601
 *   - Advertising (x3): 0.11761
 *   - Sunny hours (x4): 17.346
 *
 * @note This project is part of the Ingenjörsuppgift course at AGSTU.
 * 
 * @date 2024-05-11
 * @version 1.0
 * @auth John Yucel
 */

#include "HLS/hls.h"


#define FEATURES_SIZE 4

/**
 * @Ice cream sales based on input features.
 *
 * @details
 * This function computes the predicted ice cream sales using a multiple linear regression model.
 * The model uses a set of predefined coefficients for the features temperature, rainfall,
 * advertising expenditure, and sunny hours. The function is designed as an Avalon slave component
 * for synthesis with the Intel® HLS tool.
 *
 * @param features A pointer to an array of floats representing the input features.
 *                 - features[0]: Temperature
 *                 - features[1]: Rainfall
 *                 - features[2]: Advertising
 *                 - features[3]: Sunny hours
 * 
 * @return The predicted ice cream sales as a float.
 */
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
