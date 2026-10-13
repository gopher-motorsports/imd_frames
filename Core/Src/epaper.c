// /**
#include "epaper.h"
#include "GopherCAN.h"
// #include "GUI_Paint.h"
// #include <string.h>
// #include "fonts.h"
// #include "myimage.h"

// #define EPD_WIDTH   800
// #define EPD_HEIGHT  480
// #define EPD_ARRAY   (EPD_WIDTH * EPD_HEIGHT / 8)

// static uint8_t buffer[EPD_ARRAY];
// void Draw_SmallBitmap(int x0, int y0, const uint8_t* img, int w, int h);

U8 imd_configure(U8 num){
    CAN_MSG message;

    message.header.StdId = 0x22;
    message.header.IDE = CAN_ID_STD;
    message.header.RTR = DATA_MESSAGE;
    message.header.DLC = 8;

    message.data[0] = 0x79;
    message.data[1] = num;
    message.data[2] = 0x01;
    message.data[3] = 0xFF;
    message.data[4] = 0xFF;
    message.data[5] = 0xFF;
    message.data[6] = 0xFF;
    message.data[7] = 0xFF;

    return tx_can_message(&message);
}
 

// /* ================= HARDWARE CONTROL ================= */

// static void EPD_Reset(void)
// {
//     HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin, GPIO_PIN_RESET);
//     HAL_Delay(200);
//     HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin, GPIO_PIN_SET);
//     HAL_Delay(200);
// }

// static void EPD_WaitBusy(void)
// {
//     // UC8179: BUSY LOW = busy, HIGH = idle
//     while(HAL_GPIO_ReadPin(BUSY_GPIO_Port, BUSY_Pin) == GPIO_PIN_RESET)
//     {
//         HAL_Delay(5);
//     }
// }

// /* ================= INITIALIZATION ================= */

// void EPD_Init(void)
// {
//     EPD_Reset();

//     // Power setting
//     EPD_W21_WriteCMD(0x01);
//     EPD_W21_WriteDATA(0x07);
//     EPD_W21_WriteDATA(0x07);
//     EPD_W21_WriteDATA(0x3F);
//     EPD_W21_WriteDATA(0x3F);

//     // Booster soft start
//     EPD_W21_WriteCMD(0x06);
//     EPD_W21_WriteDATA(0x17);
//     EPD_W21_WriteDATA(0x17);
//     EPD_W21_WriteDATA(0x28);
//     EPD_W21_WriteDATA(0x17);

//     // Power on
//     EPD_W21_WriteCMD(0x04);
//     EPD_WaitBusy();

//     // Panel setting
//     EPD_W21_WriteCMD(0x00);
//     EPD_W21_WriteDATA(0x1F);

//     // Resolution 800×480
//     EPD_W21_WriteCMD(0x61);
//     EPD_W21_WriteDATA(0x03);  // 800 >> 8
//     EPD_W21_WriteDATA(0x20);  // 800 & 0xFF
//     EPD_W21_WriteDATA(0x01);  // 480 >> 8
//     EPD_W21_WriteDATA(0xE0);  // 480 & 0xFF

//     // Data entry mode (REQUIRED)
//     EPD_W21_WriteCMD(0x11);
//     EPD_W21_WriteDATA(0x03);

//     // VCOM and data interval
//     EPD_W21_WriteCMD(0x50);
//     EPD_W21_WriteDATA(0x10);
//     EPD_W21_WriteDATA(0x07);

//     // TCON
//     EPD_W21_WriteCMD(0x60);
//     EPD_W21_WriteDATA(0x22);
// }

// /* ================= IMAGE MEMORY ================= */

// static void EPD_WriteOldImage(uint8_t color)
// {
//     EPD_W21_WriteCMD(0x10);
//     for(uint32_t i = 0; i < EPD_ARRAY; i++)
//         EPD_W21_WriteDATA(color);
// }

// static void EPD_WriteNewImage(uint8_t *buf)
// {
//     EPD_W21_WriteCMD(0x13);
//     for(uint32_t i = 0; i < EPD_ARRAY; i++)
//         EPD_W21_WriteDATA(buf[i]);
// }

// /* ================= DISPLAY UPDATE ================= */

// void EPD_Update(void)
// {
//     EPD_W21_WriteCMD(0x12);   // Display refresh
//     HAL_Delay(10);
//     EPD_WaitBusy();
// }

// /* ================= TEST PATTERN ================= */

// void EPD_TestPattern(void)
// {

//     Paint_SelectImage(buffer);
//     Paint_Clear(WHITE);

//     memset(buffer, 0xFF, sizeof(buffer));  // white background

//     // vertical black bars
//     for(uint32_t y = 0; y < EPD_HEIGHT; y++)
//     {
//         for(uint32_t x = 0; x < EPD_WIDTH; x++)
//         {
//             if((x / 50) % 2 == 0)
//             {
//                 uint32_t index = (x + y * EPD_WIDTH) / 8;
//                 buffer[index] &= ~(0x80 >> (x % 8));
//             }
//         }
//     }

//     EPD_WriteOldImage(0xFF);      // previous frame = white
//     EPD_WriteNewImage(buffer);    // new frame = pattern
//     EPD_Update();
// }


// void runEpaperTask(void) {
//     // Initialize the buffer
//     Paint_NewImage(buffer, EPD_WIDTH, EPD_HEIGHT, ROTATE_180, BLACK);
//     Paint_SelectImage(buffer);
//     Paint_Clear(WHITE);  // clear buffer to white

//     // Draw rectangle
//     Paint_DrawRectangle(50, 70, 750, 420, BLACK, DRAW_FILL_EMPTY, DOT_PIXEL_DFT);

//     // Draw text
//     char* name = "Beanie";
//     Paint_DrawString_EN(EPD_WIDTH/2 - 50, EPD_HEIGHT/2, name, &Font20, WHITE, BLACK);

//     EPD_WriteNewImage(buffer);    
//     EPD_Update();

//     Paint_SelectImage(buffer);
//     Paint_Clear(WHITE);
     

//     Draw_SmallBitmap(25, 25, gImage_beanie2, 480, 480);

//     // Send the complete buffer to display
//     EPD_WriteNewImage(buffer);    
//     EPD_Update();
// }

// void Draw_SmallBitmap(int x0, int y0, const uint8_t* img, int w, int h)
// {
//     for (int y = 0; y < h; y++)
//     {
//         for (int x = 0; x < w; x++)
//         {
//             int byteIndex = (x + y * w) / 8;
//             int bitIndex  = 7 - (x % 8); // most libraries use MSB first

//             if (img[byteIndex] & (1 << bitIndex))
//                 Paint_SetPixel(x0 + x, y0 + y, BLACK); // 1 = black
//             else
//                 Paint_SetPixel(x0 + x, y0 + y, WHITE); // 0 = white
//         }
//     }
// }