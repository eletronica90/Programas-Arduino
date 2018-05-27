// TÍTULO: 01 - Programa Para Acender um LED
// AUTOR: Ângelo Meneguini
// SITE: https://eletronicagaragem.blogspot.com.br/

int ledPin = 10;                  // pino onde o led será conectado

void setup() 
{   
    pinMode(ledPin, OUTPUT);      // configura o pino 10 como saída
}

void loop()
{    
    digitalWrite(ledPin, HIGH);   // aciona a saída, pino 10 com 5V
    delay(1000);                  // espera por 1 segundo
    digitalWrite(ledPin, LOW);    // desativa a saída, pino 10 com 0V
    delay(1000);                  // espera por 1 segundo
}
