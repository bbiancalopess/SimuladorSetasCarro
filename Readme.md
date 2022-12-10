Projeto desenvolvido no ambiente IAR Embeded Workbench IDE; ver.: 5.60.2 e implementado em um microcontrolador MSP430F1611

O projeto tem o intuito de simular o controle das quatro setas de um veículo. Elas devem piscar de acordo com a posição das chaves, representadas aqui pelas combinações dos bits de entrada P1.1 e P1.0.

As combinações dos bits de entrada e o comportamento das lâmpadas das setas são descritas abaixo.

  Chave de seta   Lâmpadas

  E (P1.1)      D(P1.0)            FE(P1.7)   TE(P1.6)   FD(P1.5)   TD(P1.4)

   0     0            Todas apagadas

   0     1            Piscam as lâmpadas da direita (TD e FD)

   1     0            Piscam as lâmpadas da esquerda (TE e FE)

   1     1            Piscam as 4 lâmpadas
