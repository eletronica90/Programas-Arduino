// TÍTULO: Programa Medidor de Temperatura com Sensor LM35
// AUTOR: Ângelo Meneguini

#include <LiquidCrystal.h>                         // Inclui a biblioteca para o display LCD
#define lm35 A0                                    // Define o pino do sensor como sendo a entrada A0

float temperatura = 0;                             // Declara a variável temperatura como ponto flutuante
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);             // Define os pinos que são utilizados para conexão do display

void setup() {
  pinMode(lm35, INPUT);                            // Declara o pino do sensor como entrada
  lcd.begin(16,2);                                 // Inicia o display informando que ele é do tipo 16x2
  lcd.clear();                                     // Limpa a informação armazenada anteriormente
  lcd.setCursor(2,0);                              // Posiciona o cursor na coluna 3 e linha 1 
  lcd.print("Medidor de");                         // Escreve no visor
  lcd.setCursor(0,1);                              // Posiciona o cursor na coluna 0 e linha 2
  lcd.print("Temperatura LM35");                   // Escreve no visor
  delay(2000);                                     // Espera 2 s
  }

void loop() {
 
  float leitura = analogRead(lm35);                // Lê e armazena  o valor da entrada analógica em leitura
  temperatura = (5*leitura) / (10.23);             // Cálcula o valor da temperatura

  lcd.clear();                                     // Limpa a informação anterior do display
  lcd.setCursor(2,0);                              // Posiciona o cursor
  lcd.print("Temperatura");                        // Escreve no visor
  lcd.setCursor(0,1);                              // Posiciona o cursor
  lcd.print("T:");                                 // Escreve no visor
  lcd.setCursor(3,1);                              // Posiciona o cursor
  lcd.print(temperatura);                          // Escreve no visor
  lcd.setCursor(9,1);                              // Posiciona o cursor
  lcd.write(B11011111);                            // Escreve o caractere especial °
  lcd.setCursor(10,1);                             // Posiciona o cursor
  lcd.print("C");                                  // Escreve no visor
  delay(500);                                      // Espera 0,5 s para repetir o programa novamente
}
