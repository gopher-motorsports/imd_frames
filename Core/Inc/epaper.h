#ifndef EPAPER_H
#define EPAPER_H

#include "spi.h"
#include <stdint.h>
#include "GopherCAN.h"


//extern uint8_t fullScreenBitmap[EPD_ARRAY];

// void EPD_Init(void);
// void createAndSendTestPattern();
// void runEpaperTask();
// void EPD_TestPattern(void);
U8 imd_configure(U8 num);

#endif