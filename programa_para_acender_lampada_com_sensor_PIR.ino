// TÍTULO: Programa Para Acender Lâmpada com Sensor PIR
// AUTOR: Ângelo Meneguini
// WEBSITE: https://eletronicagaragem.blogspot.com

#define pino_PIR 7                   // pino que recebe o sinal do sensor PIR
#define pino_rele 12                 // pino que envia o sinal para o relé

int estado;                          // variável que armazena a leitura do sensor PIR

void setup() {
  pinMode(pino_PIR, INPUT);          // informa que o pino do sensor é uma entrada
  pinMode(pino_rele, OUTPUT);        // informa que o pino do relé é uma saída
} // end void setup

void loop() {

  estado = digitalRead(pino_PIR);    // lê a entrada o pino digital que está conectado o sensor PIR

  if(estado == HIGH)                 // checa se o sensor PIR detectou presença
  {
    digitalWrite(pino_rele, HIGH);   // aciona o relé que ligará a lâmpada
    delay(10000);
  } // end if
  else
  {
    digitalWrite(pino_rele, LOW);    // desliga o relé que desliga a lâmpada
  } // end else
} // end void loop
