// TÍTULO: Programa Para Controlar Servomotores com Joystick de PS2
// AUTOR: Ângelo Meneguini
// WEBSITE: https://eletronicagaragem.blogspot.com.br

#include <Servo.h>                         // inclusão da biblioteca sero.h

Servo servo1;                              // cria o objeto para o servo 1
Servo servo2;                              // cria o objeto para o servo 2

#define V_pin A0                           // pino de conexão da posição vertical do joystick
#define H_pin A1                           // pino de conexão da posição horizontal do joystick 

int H_val = 0;                             // armazena o valor da leitura analógica da posição horizontal
int V_val = 0;                             // armazena o valor da leitura analógica da posição vertical


void setup() {
  servo1.attach(9);                        // configura o pino digital 9 como saída para controle do servo 1
  servo2.attach(10);                       // configura o pino digital 10 como saída para controle do servo 2
} // end void setup

void loop() {

  H_val = analogRead(H_pin);               // leitura do valor analógico do joystick na posição horizontal
  V_val = analogRead(V_pin);               // leitura do valor analógico do joystick na posição vertical

  H_val = map(H_val, 0, 1023, 0, 180);     // faz o mapeamento do valor para faixa de 0 a 180° para determinar a posição que o servo será colocado
  V_val = map(V_val, 0, 1023, 0, 180);     // faz o mapeamento do valor para faixa de 0 a 180° para determinar a posição que o servo será colocado

  servo1.write(H_val);                     // aciona o servo 1 com o valor mapeado anteriormente entre 0 a 180°
  servo2.write(V_val);                     // aciona o servo 2 com o valor mapeado anteriormente entre 0 a 180°
  delay(15);                               // espera 15 ms para iniciar novamente o loop
} // end void loop
