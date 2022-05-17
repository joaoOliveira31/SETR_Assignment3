/** @file StateMachine.h
 * @brief Programa Máquina de estados
 *
 * Este modulo executa a máquina de estados a cada 100ms e tem 7 estados: 
 * Pagina Inicial, Beer, Tuna Sandwich, Coffee, Select, Inserir, Retorno
 * 
 * 
 * @author Goncalo Moniz, João Oliveira, Diogo Leão
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

/**
 * @brief Executa a máquna de estados
 * 
 */
void StateMachinee(void);
