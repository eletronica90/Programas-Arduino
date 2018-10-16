// Título: Usando Teclado Matricial com Arduino
// Autor: Ângelo Meneguini
// Site: https://eletronicagaragem.blogspot.com.br

#include <Keypad.h>                          // inclui a biblioteca Keypad no programa

const byte LINHAS = 4;                       // define o numero de linhas do teclado utilizado
const byte COLUNAS = 3;                      // define o numero de colunas do teclado utilizado

char matriz_teclas[LINHAS][COLUNAS] =        // cria-se uma matriz de caracteres de acordo com o teclado
{
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte PinosLinhas[LINHAS] = {4, 5, 6, 7};    // definimos os pinos do arduino utilizados para as linhas

byte PinosColunas[COLUNAS] = {8, 9, 10};    // definimos os pinos do arduino utilizados para as colunas

Keypad meuteclado = Keypad( makeKeymap(matriz_teclas), PinosLinhas, PinosColunas, LINHAS, COLUNAS); // inicialização do teclado

void setup()
{
  Serial.begin(9600);                                              // definimos a taxa de comunicação com a serial
  Serial.println("Utilizando Teclado Matricial 4x3 com Arduino");  // imprimimos no monitor o texto
  Serial.println("Aguardando acionamento das teclas...");          // imprimimos no monitor o texto
  Serial.println();                                                // cria um espaço vazio
}
  
void loop()
{
  char tecla_pressionada = meuteclado.getKey();                    // verifica se alguma tecla foi pressionada
  
  if (tecla_pressionada)                                           // mostra na serial monitor a tecla que foi pressionada
  {
    Serial.print("Tecla pressionada : ");
    Serial.println(tecla_pressionada);
  }
}
