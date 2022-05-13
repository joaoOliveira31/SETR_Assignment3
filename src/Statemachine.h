/** @file StateMachine.h
 * @brief Variaveis e programação da maquina de estados
 *
 * Este modulo inicia a maquina de estados
 * 
 * 
 * @author Goncalo Moniz
 * @bug No known bugs.
 */

//estados
#define inicio 0
#define beer 1
#define tuna 2
#define select_e 3
#define inserir 4
#define retorno 5

//acoes/flags
#define coffee 6
#define up 1
#define down 2
#define select 4
#define bretorno 3
#define moeda 5

 int custo;
 int produto;
 int state;
 int credito;

void Statemachine(void);
