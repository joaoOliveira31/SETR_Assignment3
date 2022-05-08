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
#include "placa.c"


/* Main function */
void main(void) {

    InitConfig();
    printk("OLAAAA\r\n");
    while(1) {                  
        if(dcToggleFlag){
          if(dcToggleFlag == 1)
            printk("Botão 1 pressionado\r\n");
          else if(dcToggleFlag == 2)
            printk("Botão 2 pressionado\r\n");
          else if(dcToggleFlag == 3)
            printk("Botão 3 pressionado\r\n");
          else if(dcToggleFlag == 4)
            printk("Botão 4 pressionado\r\n");
          else if(dcToggleFlag == 5){
            printk("Botao Moedas pressionado\r\n");
            printf("FLAG = %d\r\n",dcToggleFlag);
            printf("COIN = %d\r\n",coinv);
          }
          else
            printk("wut?\r\n");

          dcToggleFlag = 0;
        }
    }
    
    return;
} 






