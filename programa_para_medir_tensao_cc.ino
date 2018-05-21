// TÍTULO: Programa Para Medir Tensão CC
// AUTOR: Ângelo Meneguini

#include <LiquidCrystal.h>                     // Inclui a biblioteca para o display de lcd

#define pin_div A0                             // Defini o pino analógico A0 como entrada da tensão
float R1 = 30000.0;                            // Valor do resistor R1 para o cálculo da tensão
float R2 = 10000.0;                            // Valor do resistor R2 para o cálculo da tensão
float v_cc[50];                                // Declara v_cc como um vetor de 50 posições

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);         // Informa a biblioteca quais pinos digitais são reservados para acionar o display

void setup() {
  
  pinMode(pin_div, INPUT);                     // Configura a porta A0 como entrada analógica
  
  lcd.begin(16,2);                             // Inicia o display informando o tipo de display, 16x2
  lcd.clear();                                 // Limpa os dados em cache do display
  lcd.setCursor(1,0);                          // Posiciona o cursor para coluna 2, linha 1
  lcd.print("Voltimetro CC");                  // Inprime no display o tipo de protótipo, Voltímetro CC
} // fim do setup

void loop() {
  
  float v_lido = 0;                            // Declara uma variável para leitura dos valores analógicos
  float v_medido = 0;                          // Variável que armazenará a média das amostras da tensão cc

  for(int i = 0; i < 50; i++)                  // Armaneza no vetor v_cc a tensão de entrada, em 50 espaços de memória
  {
    v_lido = analogRead(pin_div);              // Lê o valor analógico e armazena na variável v_lido
    
    v_cc[i] = (5*v_lido*(R1 + R2))/(R2*1023);  // Faz o cálculo da tensão medida correspondente a leitura analógica 
  } // fim laço for
  for(int i = 0; i < 50; i++)                  // Calcula a soma de todos os valores de tensão cc armazenados em v_cc
  {
    v_medido = v_medido + v_cc[i];             // Somas dos valores de tensão medidos
  } // fim laço for

  v_medido = (v_medido/50);                    // Calcula a média de todos os valores de tensão
  
  lcd.setCursor(0,1);                          // Posiciona o cursor na coluna 1, linha 2
  lcd.print("Vcc = ");                         // Inprime o texto Vcc =
  lcd.setCursor(6,1);                          // Posiciona o cursor na coluna 7, linha 2
  lcd.print(v_medido);                         // Imprime o valor da tensão calculada, que corresponderá a tensão medida

  delay(1000);                                 // Espera por 1 segundo

} // fim do loop
