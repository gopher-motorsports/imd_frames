#ifndef INC_SPI_H_
#define INC_SPI_H_

/* ==================================================================== */
/* ============================= INCLUDES ============================= */
/* ==================================================================== */

#include "utils.h"
#include "main.h"

void EPD_W21_WriteCMD(uint8_t command);
void EPD_W21_WriteDATA(uint8_t data);

#endif /* INC_SPI_H_ */