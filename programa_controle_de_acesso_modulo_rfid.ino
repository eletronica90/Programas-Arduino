// TÍTULO : Programa Para Controle de Acesso com Módulo RFID
// Autor : Ângelo Meneguini

#include <SPI.h>                                                             // Incluimos a biblioteca SPI
#include <MFRC522.h>                                                         // Incluimos a biblioteca MFRC522 para o módulo RFID

#define SS_PIN 10                                                            // Definindo o pino para conexão do módulo RFID 
#define RST_PIN 9                                                            // Definindo o pino para conexão do módulo RFID

MFRC522 mfrc522(SS_PIN, RST_PIN);                                            // Informa no programa quais os pinos de comunicação ao módulo

#define led_verde 3                                                          // Define o pino 3 para conectarmos o LED verde (acesso liberado)
#define led_vermelho 2                                                       // Define o pino 2 para conectarmos o LED vermelho (acesso negado)

char st[20];                                                                 // Cria um espaço na memória para armazenar a string

void setup() 
{
  pinMode(led_verde, OUTPUT);                                                // Configura o pino que o LED verde está conectado como saída
  pinMode(led_vermelho, OUTPUT);                                             // Configura o pino que o LED vermelho está conectado com saída
  Serial.begin(9600);                                                        // Inicia a comunicação serial
  SPI.begin();                                                               // Inicia a comunicação SPI
  mfrc522.PCD_Init();                                                        // Inicializa a biblioteca MFRC522
  Serial.println("Aproxime o cartao ao leitor...");                          // Apresenta a frase na janela serial
  Serial.println();
} // end setup()

void loop() 
{
  if ( ! mfrc522.PICC_IsNewCardPresent())                                    // Aguarda o cartão ser aproximado
  {
    return;
  } // end if()
  if ( ! mfrc522.PICC_ReadCardSerial())                                      // Seleciona um dos cartões
  {
    return;
  } // end if()
  
  Serial.println("UID da tag :");                                              // Apresenta o ID do cartão na comunicação serial
  String conteudo= "";
  byte letra;
  
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  } // end for()
  Serial.println();
  
  conteudo.toUpperCase();
  
  if (conteudo.substring(1) == "65 5F 48 BE")                                 // Verifica se o cartão 1 foi lido
  {
    digitalWrite(led_verde, HIGH);                                            // Acende o LED verde
    Serial.println("Cartao 1 - Acesso liberado!");                            // Apresenta na serial que o acesso foi liberado
    Serial.println();
    delay(3000);                                                              // Espera o 3 segundos mantendo o LED aceso
    digitalWrite(led_verde, LOW);                                             // Apaga o LED verde
    } // end for()
    
  if (conteudo.substring(1) == "E5 75 23 1C")                                 // Verifica se o cartão 2 foi lido

  {
    Serial.println("Cartao 2 - Acesso negado!!");                             // Apresenta que o acesso foi negado
    Serial.println();
    // Pisca o led vermelho
    for (int i= 1; i<5 ; i++)                                                 // Pisca o LED vermelho
    {
      digitalWrite(led_vermelho, HIGH);
      delay(200);
      digitalWrite(led_vermelho, LOW);
      delay(200);
    } // end for()
  } // end for()
  delay(1000);                                                                // Espera 1 segundo
} // end loop()
