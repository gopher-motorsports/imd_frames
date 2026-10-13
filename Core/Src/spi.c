// #include "spi.h"

// // SPI timeout period
// #define SPI_TIMEOUT_MS          10

// extern SPI_HandleTypeDef hspi1;

// // SPI write command
// void EPD_W21_WriteCMD(uint8_t command)
// {
//     HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_RESET);
//     HAL_GPIO_WritePin(SPI1_DC_GPIO_Port, SPI1_DC_Pin, GPIO_PIN_RESET); // D/C# 0:command 1:data
//     taskNotifySPI(&hspi1, &command, 1, SPI_TIMEOUT_MS);
//     HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_SET);
// }

// // SPI write data
// void EPD_W21_WriteDATA(uint8_t data)
// {
//     HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_RESET);
//     HAL_GPIO_WritePin(SPI1_DC_GPIO_Port, SPI1_DC_Pin, GPIO_PIN_SET); // D/C# 0:command 1:data
//     taskNotifySPI(&hspi1, &data, 1, SPI_TIMEOUT_MS);
//     HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_SET);
// }
