// TÍTULO: Programa Para Controle do Sentido de Rotação de um Motor com Ponte H GBK
// AUTOR: Ângelo Meneguini

int dir1 = 5;                  // Define o pino digital 5 como sendo o comando IN-1
int dir2 = 4;                  // Define o pino digital 4 como sendo o comando IN-2

void setup() {
  pinMode(dir1, OUTPUT);        // Configura o pino 5 como saída
  pinMode(dir2, OUTPUT);        // Configura o pino 4 como saída
}

void loop() {
  
  digitalWrite(dir1, HIGH);     // Aciona o pino 5, fazendo o motor girar num sentido
  digitalWrite(dir2, LOW);      // Desliga o pino 4
  
  delay(2000);                  // Espera 2 segundos,onde motor girará por este tempo
  
  digitalWrite(dir1, LOW);      // Desliga o pino 5, fazendo o motor desacelerar
  digitalWrite(dir2, LOW);      // Desliga o pino 4
  
  delay(1000);                  // Espera 1 segundo ate o motor parar
  
  digitalWrite(dir1, LOW);      // Desliga o pino 5
  digitalWrite(dir2, HIGH);     // Aciona o pino 4, fazendo o motor girar noutro sentido
  
  delay(2000);                  // Espera 2 segundos, onde o motor girará por este tempo
  
  digitalWrite(dir1, LOW);      // Desliga o pino 5
  digitalWrite(dir2, LOW);      // Desliga o pino 4, fazendo o motor desacelerar
  
  delay(1000);                  // Espera 1 segundo até tudo se repetir novamente
  
}
