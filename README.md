# Ice Cream Sales Predictor

## Project Overview

This project implements a machine learning component to predict ice cream sales using multiple linear regression. The component is designed to take into account various features such as temperature, rainfall, advertising, and sunny hours to make accurate sales predictions. The implementation is done in C and synthesized using the Intel® High-Level Synthesis (HLS) tool.

## Features

- **Multiple Linear Regression**: Utilizes a regression model to predict ice cream sales based on multiple features.
- **Avalon Slave Component**: Designed as an Avalon slave for easy integration into system-on-chip (SoC) designs.
- **HLS Toolchain**: Synthesized using Intel® HLS for efficient hardware implementation.
- **Test Bench**: Includes a test bench to validate the model’s predictions against expected results.

## File Descriptions

- **mlr2.c**: Implements the multiple linear regression component.
- **mlr2.h**: Header file declaring the `mlrc` function.
- **mlr2_tb.c**: Test bench to validate the regression model.
- **ice_cream_sales_weather.csv**: Dataset containing historical ice cream sales data with features.
- **build.bat**: Batch file to compile the component and test bench.

## Getting Started

### Prerequisites

- Intel® HLS Compiler
- Standard C Compiler

### Compilation and Execution

1. **Compile and Synthesize the Component**:
   - Use the provided `build.bat` script to compile and synthesize the component for FPGA.
   - Example command:
     ```bash
     build.bat fpga
     ```

2. **Run the Test Bench**:
   - After compilation, execute the test bench to compare predicted sales with expected values.
   - The test bench will output the predicted ice cream sales and the error percentage.

## Usage

### Function: `mlrc`

```c
/**
 * @brief Predicts ice cream sales based on input features.
 * @param features A pointer to an array of floats representing the input features. 
 *                 - features[0]: Temperature
 *                 - features[1]: Rainfall
 *                 - features[2]: Advertising
 *                 - features[3]: Sunny hours
 * @return Predicted ice cream sales as a float.
 */
component float mlrc(hls_avalon_slave_memory_argument(FEATURES_SIZE * sizeof(float)) float* features);
float features[4] = {24.3, 1.7, 318.9, 3.0};
float predicted_sales = mlrc(features);
printf("Predicted Ice Cream Sales: %f\n", predicted_sales);


