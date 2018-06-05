// TÍTULO: Programa Para Medição de Distâncias com Sensor Ultrassônico HC-SR04
// AUTOR: Ângelo Meneguini

#define trigger 4                                           // Declara que o pino de trigger estará na porta 4
#define echo 5                                              // Declara que o pino de echo estará na porta 5
float distancia = 0;                                        // Cria a variável para receber o valor da distância
float tempo = 0;                                            // Cria a variável para recer o valor do tempo lido do pino 5

void setup() {
  pinMode(trigger, OUTPUT);                                 // Configura o trigger como saída
  digitalWrite(trigger, LOW);                               // Configura o trigger em nível baixo inicialmente
  pinMode(echo, INPUT);                                     // Configura o echo como entrada de sinal digital
  Serial.begin(9600);                                       // Inicia a comunicação serial
}

void loop() {
  digitalWrite(trigger, HIGH);                              // Aciona o trigger por 10 microsegundos
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  tempo = pulseIn(echo, HIGH);                              // Lê o tempo em que echo permanece em nivel alto, tempo dado em microsegundos
  tempo = tempo/1000000;                                    // Converte o tempo para segundos
  distancia = (tempo*340)/2;                                // Calcula a distancia com base na equação fornecida no datasheet

  Serial.println("A Distancia Medida em Metros é:");        // Apresenta no monitor a distancia calculada anteriormente em metros
  Serial.println(distancia);
  Serial.println("A Distancia Medida em Centimetros é:");   // Apresenta no monitor a distancia em centimetros
  Serial.println(distancia*100);
  delay(10);                                                // Espera 10 milisegundos ate reiniciar o loop
}
