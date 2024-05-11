
/**
 * @file mlr2.h
 * @brief Header file for the machine learning component predicting ice cream sales using multiple linear regression.
 *
 * @details
 * This header file declares the function for predicting ice cream sales based on four features:
 * temperature, rainfall, advertising, and sunny hours. The function is designed as an Avalon slave
 * component, suitable for integration into system-on-chip (SoC) designs.
 *
 * - **Implementation**: The function is synthesized using the Intel® High-Level Synthesis (HLS) tool.
 * - **Features**: Utilizes temperature, rainfall, advertising, and sunny hours as input features.
 * - **Usage**: Include this header in your project to utilize the ice cream sales prediction component.
 * 
 * @note This project is part of the Ingenjörsuppgift course at AGSTU.
 * 
 * @date 2024-05-11
 * @version 1.0
 * @auth John Yucel
 */

#ifndef MLR2_H
#define MLR2_H

// Include necessary headers
#include <HLS/hls.h>  // Ensure HLS specific headers are included

// Define the FEATURES_SIZE if not defined
#ifndef FEATURES_SIZE
#define FEATURES_SIZE 4  // Example size, adjust as needed
#endif

/**
 * @brief Predicts ice cream sales based on input features.
 *
 * @details
 * This function uses multiple linear regression to predict ice cream sales. It accepts
 * a pointer to an array of features which include temperature, rainfall, advertising, and sunny hours.
 * The function is designed to be synthesized as an Avalon slave.
 *
 * @param features A pointer to an array of floats representing the input features.
 *                 - features[0]: Temperature
 *                 - features[1]: Rainfall
 *                 - features[2]: Advertising
 *                 - features[3]: Sunny hours
 * 
 * @return Predicted ice cream sales as a float.
 */

 float features[FEATURES_SIZE] = {
        24.296,1.657,318.889,3.000  // Real value is 206 from actual data.
    };
component float mlrc(hls_avalon_slave_memory_argument(FEATURES_SIZE * sizeof(float)) float* features);

#endif // MLR2_H
