// /* ==================================================================== */
// /* ============================= INCLUDES ============================= */
// /* ==================================================================== */

// #include "utils.h"

// /* ==================================================================== */
// /* ============================= DEFINES ============================== */
// /* ==================================================================== */

// // Task notification flags
// #define TASK_NO_OP          0UL
// #define TASK_CLEAR_FLAGS    0xffffffffUL

// // Number of SPI retry events
// #define NUM_SPI_RETRY       3

// /* ==================================================================== */
// /* =================== GLOBAL FUNCTION DEFINITIONS ==================== */
// /* ==================================================================== */

// SPI_STATUS_E taskNotifySPI(SPI_HandleTypeDef* hspi, uint8_t* txBuffer, uint16_t size, uint32_t timeout)
// {
//     for(uint32_t attemptNum = 0; attemptNum < NUM_SPI_RETRY; attemptNum++)
//     {
//         // Clear any stale notifications first
//         xTaskNotifyStateClear(NULL);

//         // Attempt to start SPI transaction
//         if(HAL_SPI_Transmit_IT(hspi, txBuffer, size) != HAL_OK)
//         {
//             // If SPI fails to start, HAL must abort transaction. Still much wait for the SPI Abort complete interrupt
//             HAL_SPI_Abort_IT(hspi);
//         }

//         // xTaskNotifyWait will wait for a task notification from the SPI complete, SPI Error, or SPI Abort complete callbacks
//         // The notification flags will be set with SPI_SUCCESS on success, and SPI_ERROR otherwise. If the wait times out, flags will not be set
//         uint32_t notificationFlags = 0;
//         xTaskNotifyWait(TASK_NO_OP, TASK_CLEAR_FLAGS, &notificationFlags, timeout);

//         // Check the task notification flags
//         if(notificationFlags == SPI_SUCCESS)
//         {
//             // If only the success flag is set, return success
//             return SPI_SUCCESS;
//         }
//         else if(notificationFlags == SPI_TIMEOUT)
//         {
//             // If no flags are set, abort the SPI transaction
//             HAL_SPI_Abort_IT(hspi);

//             // Wait for the SPI abort complete interrupt
//             xTaskNotifyWait(TASK_NO_OP, TASK_CLEAR_FLAGS, &notificationFlags, timeout);

//             // Return to prevent any further delay
//             return SPI_TIMEOUT;
//         }

//         // If a SPI error flag is set, retry the transaction
//     }

//     // After all failed attempts return spi error
//     return SPI_ERROR;

// }
