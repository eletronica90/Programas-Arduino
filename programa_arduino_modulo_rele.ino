// TÍTULO: Programa Para Acionamento de Cargas Elétricas com Módulo Relé
// AUTOR: Ângelo Meneguini

#define botao  4                         // pino digital do botão, push-button
#define rele  5                          // pino digital do relé
int estado = 0;                          // estado no qual se encontra o relé (0 para desligado e 1 para ligado)
int leitura;                             // armazena o valor da leitura da porta digital

void setup() {
  pinMode(botao, INPUT);                 // declara o pino do botão como uma entrada
  pinMode(rele, OUTPUT);                 // declara o pino do rele como uma saída
}

void loop() {
  leitura = digitalRead(botao);          // leitura da porta digital do botão (botão conectado em pull-down)
  if(leitura != 1){
    while(digitalRead(botao) != 1){      // cria um loop infinito até que leitura seja igual a 1 (para manter o relé energizado caso a leitura seja igual a 1)
      delay(100);
    }
    estado = !estado;                    // inversão da variável estado para controlar o relé
    digitalWrite(rele, estado);          // aciona o relé de acordo com o definido na variável estado
  }
}
