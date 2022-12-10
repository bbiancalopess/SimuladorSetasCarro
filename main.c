

/* Prog 02
  Elaborar um programa para o kit 1611 que simule o controle das quatro setas de um
  veículo (P1.7 a P1.4). Elas piscarão de acordo com a posição da "chave de seta",
  representwada aqui pelas combinações dos bits de entrada P1.1 e P1.0.
  As combinações dos bits de entrada e o comportamento das lâmpadas das setas são descritas abaixo

  Chave de seta   Lâmpadas
  E      D            FE   TE   FD   TD
  P1.1  P1.0          P1.7 P1.6 P1.5 P1.4
   0     0            Todas apagadas
   0     1            Piscam as lâmpadas da direita (TD e FD)
   1     0            Piscam as lâmpadas da esquerda (TE e FE)
   1     1            Piscam as 4 lâmpadas.

*/


#include "io430.h"

#define Fclk 750e3
#define DISPLAY P5OUT 
#define todas_lampadas (BIT7+BIT6+BIT5+BIT4)

// Protótipos
void Delay1ms();

//Funções

// Função com tempo de atraso variável em milisegundos com 
// faixa de 0 a 10.000ms (escala de tempo arbitrária)

void Delayms (int Tempo)
{  
  while (Tempo)
  {
    Delay1ms();
    Tempo--;
  }  
}


void main( void )
{
  // Stop watchdog timer to prevent time out reset
  
                   WDTCTL = WDTPW + WDTHOLD;

// CONFIGURANDO PERIFERICOS
// Configura apenas o bit utilizado no programa
// Não altere os demais bits!  
  P1SEL = P1SEL & ~(BIT0+BIT1+BIT4+BIT5+BIT6+BIT7);    // Altera os bits 0, 1, 4, 5, 6 e 7
  P1DIR = P1DIR | (BIT4+BIT5+BIT6+BIT7);          // Configura P1.4, P1.5 P1.6 e P1.7 como saída
  P1DIR = P1DIR & ~(BIT0+BIT1);                      // Configura P1.0 e P1.1 como entrada

  

 //Loop principal (loop infinito)
  while(1)
  { 
    switch (P1IN & (BIT0+BIT1))
    {
    case 0:
      P1OUT = P1OUT & ~todas_lampadas;
      break;
      
    case 1:                        // Pisca os leds da esquerda
      
      P1OUT = P1OUT | (BIT5+BIT4);  //Liga os leds
      Delayms(200);                 
      P1OUT = P1OUT & ~(BIT5+BIT4);  //Desliga os leds
      Delayms(200);
      break;
      
   case 2:                         // Pisca os leds da direita
      
      P1OUT = P1OUT | (BIT7+BIT6);  //Liga os leds
      Delayms(200);
      P1OUT = P1OUT & ~(BIT7+BIT6);  //Desliga os leds
      Delayms(200);
     break;
     
      case 3:                     // Pisca todos os leds 
      
      P1OUT = P1OUT | todas_lampadas;  //Liga os leds
      Delayms(200);
      P1OUT = P1OUT & ~todas_lampadas;  //Desliga os leds
      Delayms(200);
     break;
     
    }
  }
}

// Função com tempmo de atraso fixo em 1ms ou seja 750 pulsos de clk
void Delay1ms()
{
 int Repete = 184;
 
 while (Repete)
   Repete--;
}



