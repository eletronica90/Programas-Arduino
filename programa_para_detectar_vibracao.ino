// TÍTULO: Programa Para Detecção de Vibração com Sensor SW-420
// AUTOR: Ângelo Meneguini
// SITE: https://eletronicagaragem.blogspot.com.br

#define pinoLed 8                    // pino que o LED esta conectado
#define pinoSensor 7                 // pino que o sensor esta conectado

void setup() {
  pinMode(pinoSensor, INPUT);        // configura o pino 7 como entrada
  pinMode(pinoLed, OUTPUT);          // configura o pino 8 como saída
  digitalWrite(pinoLed, LOW);        // inicia a saída 8 como low
}

void loop() {
  if(digitalRead(pinoSensor) == HIGH)// lê a porta digital 7 e verfica a se o valor é alto
  {
    digitalWrite(pinoLed, HIGH);     // acende o led no pino 8
  }
  else
  {
    digitalWrite(pinoLed, LOW);      // apaga o led no pino 8
  }
}
