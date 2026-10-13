// #ifndef INC_UTILS_H_
// #define INC_UTILS_H_

// /* ==================================================================== */
// /* ============================= INCLUDES ============================= */
// /* ==================================================================== */

// #include <stdint.h>
// #include "stm32f4xx_hal.h"
// #include "cmsis_os.h"

// /* ==================================================================== */
// /* ========================= ENUMERATED TYPES========================== */
// /* ==================================================================== */

// typedef enum
// {
//     SPI_TIMEOUT = 0,  // SPI timed out
//     SPI_ERROR,        // SPI error occured
//     SPI_SUCCESS       // SPI was successful
// } SPI_STATUS_E;       // Interupt status enum for task notification flags

// /* ==================================================================== */
// /* =================== GLOBAL FUNCTION DECLARATIONS =================== */
// /* ==================================================================== */

// SPI_STATUS_E taskNotifySPI(SPI_HandleTypeDef* hspi, uint8_t* txBuffer, uint16_t size, uint32_t timeout);

// #endif /* INC_UTILS_H_ */