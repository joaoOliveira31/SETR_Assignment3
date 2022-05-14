/** @file StateMachine.h
 * @brief Variaveis e programação da maquina de estados
 *
 * Este modulo inicia a maquina de estados
 * 
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

//estados
#define inicio 0
#define beer 1
#define tuna 2
#define select_e 3
#define inserir 4
#define retorno 5

//acoes/flags

#define up 1
#define down 2
#define bretorno 3
#define select 4
#define moeda 5
#define coffee 6

 extern volatile int state;


void StateMachinee(void);
