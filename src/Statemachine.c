#include "Statemachine.h"

volatile int state = inicio; 
void StateMachinee()
{
   
   static int nextstate;
   static int credito,custo,coinadd;
   static char produto[6];
 
   switch (state) 
   {
      case inicio: 
             
             //leaving inicio:
             if(dcToggleFlag)
             {
                 if(dcToggleFlag==1) {nextstate = beer;printk("Product: Beer           Credit: %d.%d   Cost: 1.5EUR\r\n",credito/100,credito%100);}
                 else if(dcToggleFlag==2) {nextstate = beer;printk("Product: Beer           Credit: %d.%d   Cost: 1.5EUR\r\n",credito/100,credito%100);}
                 else if(dcToggleFlag==moeda) {nextstate = inserir;coinadd = coinv;}
                 else if(dcToggleFlag==3) nextstate = retorno;
                 else if(dcToggleFlag==select) printk("No Product selected\r\n");
             }
             state = nextstate; 
             break;
 
       case  beer: 
             custo=150;
             strcpy(produto,"Beer");
             
             //leaving beer:
             if(dcToggleFlag)
             {
                 if(dcToggleFlag == bretorno)    nextstate = retorno;
                 else if(dcToggleFlag == moeda)  {nextstate = inserir;coinadd = coinv;}
                 else if(dcToggleFlag == up)     {nextstate = coffee;printk("Product: Coffee         Credit: %d.%d   Cost: 0.5EUR\r\n",credito/100,credito%100);}
                 else if(dcToggleFlag == down)   {nextstate = tuna;printk("Product: Tuna sandwich  Credit: %d.%d   Cost: 1.0EUR\r\n",credito/100,credito%100);}
                 else if(dcToggleFlag==select) nextstate = select_e;
             }
             state = nextstate; 
             break;

       case  tuna:
             custo = 100; 
             strcpy(produto,"Tuna");
             
             //leaving tuna:
             if(dcToggleFlag)
             {
                 if(dcToggleFlag == bretorno)   nextstate = retorno;
                 else if(dcToggleFlag == moeda) {nextstate = inserir;coinadd = coinv;}
                 else if(dcToggleFlag == up)    {nextstate = beer;printk("Product: Beer           Credit: %d.%d   Cost: 1.5EUR\r\n",credito/100,credito%100);}
                 else if(dcToggleFlag == down)  {nextstate = coffee;printk("Product: Coffee         Credit: %d.%d   Cost: 0.5EUR\r\n",credito/100,credito%100);}
                 else if(dcToggleFlag==select) nextstate = select_e;
             }
             state = nextstate; 
             break;

        case coffee:
             custo = 50;
             strcpy(produto,"Coffee");
             
             //leaving coffee:
             if(dcToggleFlag)
             {
                 if(dcToggleFlag == bretorno) nextstate = retorno;
                 else if(dcToggleFlag==moeda) {nextstate = inserir;coinadd = coinv;}
                 else if(dcToggleFlag==up)    {nextstate = tuna;printk("Product: Tuna sandwich  Credit: %d.%d   Cost: 1.0EUR\r\n",credito/100,credito%100);}
                 else if(dcToggleFlag==down) {nextstate = beer;printk("Product: Beer           Credit: %d.%d   Cost: 1.5EUR\r\n",credito/100,credito%100);}
                 else if(dcToggleFlag==select) nextstate = select_e;
             }
             state =  nextstate;
             break;

        case select_e:
             
             if(credito>=custo) {
                credito=credito-custo;
                printk("\r\nProduct %s dispensed, remaining credit %d.%dEUR\r\n\r\n",produto,credito/100,credito%100);
             }
             else {
                printk("\r\nNot enough credit, Product %s costs %d.%dEUR, credit is %d.%dEUR\r\n\r\n",produto,custo/100,custo%100,credito/100,credito%100);
             }
             //leaving select:
             nextstate=inicio;
             state = nextstate; 
             printk("Main Page\r\n");
             break;

        case inserir: 
             printk("%d.%d EUR Inserted\r\n",coinadd/100,coinadd%100);
             credito=credito+coinadd; 
             printk("Credit = %d.%d\r\n",credito/100,credito%100);
             //leaving inserir:
             nextstate = inicio;
             state = nextstate;
             coinadd=0;
             printk("Main Page\r\n");
             break;

        case retorno: 
             printk("\r\n%d.%d EUR returned\r\n\r\n",credito/100,credito%100);
             credito=0;
             //leaving retorno:
             nextstate=inicio;
             state =  nextstate;
             printk("Main Page\r\n");
             break;
      }
      return;
}
