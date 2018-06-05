// TÍTULO: Programa Para Leitura do Sensor de Luminosidade com LDR
// AUTOR: Ângelo Meneguini

#define sinal A0                      // Pino no qual o sensor LDR está conectado
#define led1 2                        // Pino do LED 1
#define led2 3                        // Pino do LED 2
#define led3 4                        // Pino do LED 3

int leitura = 0;                      // Variável que armazena o valor analogico lido em A0

void setup() {

  Serial.begin(9600);                 // Inicia a comunicação serial

  pinMode(sinal, INPUT);              // Configura o pino analogico A0 como entrada
  pinMode(led1, OUTPUT);              // Configura o pino do LED 1 como saída
  pinMode(led2, OUTPUT);              // Configura o pino do LED 2 como saída
  pinMode(led3, OUTPUT);              // Configura o pino do LED 3 como saída

  digitalWrite(led1, LOW);            // Inicia o LED 1 em nível lógico 0
  digitalWrite(led2, LOW);            // Inicia o LED 2 em nível lógico 0
  digitalWrite(led3, LOW);            // Inicia o LED 3 em nível lógico 0
}

void loop() {

  leitura = analogRead(sinal);        // Lê o valor analogico em A0 do sensor LDR

  Serial.print("Leitura do LDR:");    // Imprime no Monitor Serial a frase
  Serial.println(leitura);            // Imprime o valor analogico no Monitor Serial

  if(leitura >= 100 && sinal < 350)   // Compara se o valor analogico esta entre 100 e 350
  {
    digitalWrite(led1, HIGH);         // Coloca o LED 1 em nível alto
    digitalWrite(led2, LOW);          // Coloca o LED 2 em nível baixo
    digitalWrite(led3, LOW);          // Coloca o LED 3 em nível baixo
  }

  if(leitura >= 350 && sinal < 600)   // Compara se o valor analogico está entre 350 e 600
  {
    digitalWrite(led1, HIGH);         // Coloca o LED 1 em nível alto
    digitalWrite(led2, HIGH);         // Coloca o LED 2 em nível alto
    digitalWrite(led3, LOW);          // Coloca o LED 3 em nível baixo
  }

  if(leitura >= 600 && sinal <= 1023) // Compara se o valor analogico está entre 600 e 1023
  {
    digitalWrite(led1, HIGH);         // Coloca o LED 1 em nível alto
    digitalWrite(led2, HIGH);         // Coloca o LED 2 em nível alto
    digitalWrite(led3, HIGH);         // Coloca o LED 3 em nível alto
  }

  delay(1000);                        // Espera 1 segundo até a nova leitura
}
