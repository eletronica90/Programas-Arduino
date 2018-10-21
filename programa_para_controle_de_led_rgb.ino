// TÍTULO: Controlando LED RGB com Arduio
// AUTOR: Ângelo Meneguini
// SITE: https://eletronicagaragem.blogspot.com.br


#define red 9         // pino conectado ao LED vermelho
#define green 10      // pino conectado ao LED verde
#define blue 11       // pino conectado ao LED azul

#define pot1 A0       // entrada do potenciômetro 1
#define pot2 A1       // entrada do potenciômetro 2
#define pot3 A2       // entrada do potenciômetro 3

void setup() {
  
  pinMode(red, OUTPUT);    // define o pino 9 como saída
  pinMode(green, OUTPUT);  // define o pino 10 como saída
  pinMode(blue, OUTPUT);   // define o pino 11 como saída
}

void loop() {
  
  int v1 = analogRead(pot1);   // lê a entrada analógica A0
  int v2 = analogRead(pot2);   // lê a entrada analógica A1
  int v3 = analogRead(pot3);   // lê a entrada analógica A2

  v1 = constrain(v1, 0, 255);  // converte o valor v1 para o intervalo de 0 a 255
  v2 = constrain(v2, 0, 255);  // converte o valor v2 para o intervalo de 0 a 255
  v3 = constrain(v3, 0, 255);  // converte o valor v3 para o intervalo de 0 a 255

  analogWrite(red, v1);        // aciona a saída pwm com o valor de v1
  analogWrite(green, v2);      // aciona a saída pwm com o valor de v2
  analogWrite(blue, v3);       // aciona a saída pwm com o valor de v3
}
