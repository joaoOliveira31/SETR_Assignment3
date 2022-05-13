/** @file Statemachine.c
 * @brief Maquina de estados
 * 
 * @author Goncalo Moniz
 * @bug No known bugs.
 */

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


void StateMachine()
{
   int state = inicio; 
   int nextstate;
   int credito,custo;
   char produto;
 
   switch (state) 
   {
      case inicio: 
             printk("Pagina Inicial\r\n");
             //leaving inicio:
             if(dcToggleFlag)
             {
                 if(dcToggleFlag==1) nextstate = beer;
                 else if(dcToggleFlag==2) nextstate = beer;
                 else if(dcToggleFlag==5) nextstate = inserir;
                 else if(dcToggleFlag==3) nextstate = retorno;
             }
             state = nextstate; 
             break;
 
       case  beer: 
             custo=150;
             produto="beer";
             printk("Produto: BEER  Credito: %d   Custo: 1.5EUR\r\n",credito);
             //leaving beer:
             if(dcToggleFlag)
             {
                 if(dcToggleFlag == bretorno)    nextstate = retorno;
                 else if(dcToggleFlag == moeda)  nextstate = inserir;
                 else if(dcToggleFlag == up)     nextstate = coffee;
                 else if(dcToggleFlag == down)   nextstate = tuna;
             }
             state = nextstate; 
             break;

       case  tuna:
             custo = 100; 
             produto = "tuna";
             printk("Produto: TUNA  Credito: %d   Custo: 1.0EUR\r\n",credito);
             //leaving tuna:
             if(dcToggleFlag)
             {
                 if(dcToggleFlag == bretorno)   nextstate = retorno;
                 else if(dcToggleFlag == moeda) nextstate = inserir;
                 else if(dcToggleFlag == up)    nextstate = beer;
                 else if(dcToggleFlag == down)  nextstate = coffee;
             }
             state = nextstate; 
             break;

        case coffee:
             custo = 50;
             produto = "coffee";
             printk("Produto: COFFEE  Credito: %d   Custo: 0.5EUR\r\n",credito);
             //leaving coffee:
             if(dcToggleFlag)
             {
                 if(dcToggleFlag == bretorno) nextstate = retorno;
                 else if(dcToggleFlag==moeda) nextstate = inserir;
                 else if(dcToggleFlag==up)    nextstate = tuna;
                 else  if(dcToggleFlag==down) nextstate = beer;
             }
             state =  nextstate;
             break;

        case select_e:
             credito=credito-custo;
             if(credito>=0) printk("Product %c dispensed, remaining credit %d\r\n",produto,credito);
             else printk("Not enough credit, Product %c costs %d, credit is %d %d\r\n",produto,custo,credito);
             //leaving select:
             nextstate=inicio;
             state = nextstate; 
             break;

        case inserir: 
             printk("Inseriu %d EUR\r\n",coinv);
             credito=credito+coinv; 
             //leaving inserir:
             nextstate = inicio;
             state = nextstate; 
             break;

        case retorno: 
             printk("Return\r\n");
             credito=0;
             //leaving retorno:
             nextstate=inicio;
             state =  nextstate;
             break;
      }
}
