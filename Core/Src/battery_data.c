
#include "GopherCAN.h"
#include <stdio.h>

void printBattery(void) {
    
    //send_can_command(PRI-LOW, 5, 0x76);
    printf("%s", bmsBatteryVoltage_V.data);

}
