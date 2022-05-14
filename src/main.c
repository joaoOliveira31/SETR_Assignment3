#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>
#include <sys/printk.h>
#include <sys/__assert.h>
#include <string.h>
#include <timing/timing.h>
#include <stdio.h>
#include <string.h>
#include "placa.h"
#include "Statemachine.h"


/* Main function */
void main(void) {

    InitConfig();
    printk("\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n");
    while(1) {
      StateMachinee();
      dcToggleFlag=0;
      coinv=0;
      k_msleep(100);
    }
    
    return;
} 
