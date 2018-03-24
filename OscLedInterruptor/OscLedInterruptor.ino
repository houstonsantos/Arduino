/**
 * @brief Acionamento de led com utilizando do protocolo OSC via tcp/ip com Arduino e obtendo 
 * retorno do Push Buton, posteriormente sendo eviado para dispositivo.   
 * @date 17/09/2014
 * @author Houston Santos
 */

// Bibliotecas a serem usadas 
#include <Ethernet.h>
#include <SPI.h>
#include <ArdOSC.h>														                      

// IP & MAC para shield ethernet 
byte myMac[] = { 0x90, 0xA2, 0xDA, 0x0F, 0x2C, 0xDE };				
byte myIp[] = { 192, 168, 25, 155 };								
byte destIP[] = {192, 168, 25, 1};									                		  

// Porta de envio e recepção OSC 
const int serverPort = 8000; 
const int destPort = 9000;

// Portas do Arduino associadas 
const int ledPin = 13; 
const int botPin = 7;

// Inicializando servidor e cliente OSC 
OSCServer server;													
OSCClient client;

// Cria uma nova menssagem OSC 
OSCMessage newMes;													

void setup() {
	// Inicializa a interface serial 
	Serial.begin(19200);

	// Inicializa a interface ethernet 
	Ethernet.begin(myMac ,myIp);

	// Inicializa o servidor OSC definindo na porta de RX 										                      
	server.begin(serverPort);											                      
 
	// Definindo funções OSC 
	server.addCallback("/HS/ledPin", &acenderLed);							
	
	// Definindo portas como INPUT ou OUTPUT 
	pinMode(ledPin, OUTPUT);
	pinMode(ledPin, INPUT);
 
	// Definindo status de porta como HIGH ou LOW 
	digitalWrite(botPin, HIGH);										
}
  
void loop() {
	// Verifica se existe alguma mensagem disponível para leitura 
	if(server.availableCheck()>0) {										                 	  
    
	}
						
// Lendo estado do push button e evinado retorno 				
if (digitalRead(botPin) == LOW) {								// Verifica se o botPin foi pressionado
	int state = digitalRead(ledPin);							// Armazena em state o estado do ledPin
	newMes.setAddress(destIP, destPort);						// Define endereço e porta para mensagem OSC
	newMes.beginMessage("/HS/ledPin");							// Define o Comando OSC
	newMes.addArgFloat(!state);									// Define o novo estado do comando que sera enviado para o dispositivo móvel
	client.send(&newMes);										// Envia mensagem OSC atualizando o estado no dispositivo móvel
	digitalWrite(ledPin, !state);								// Modifica o estado da porta ledPin
	delay(300);													// Delay de 300ms
	}
}

// Acendendo o led 
void acenderLed(OSCMessage *_mes) {								// Rotina que trata comando OSC "/HS/ledPin" recebido do ANDROID
	int value = (int)_mes->getArgFloat(0);						// Armazena em "value" o argumento do comando OSC "/HS/ledPin"
	digitalWrite(ledPin, value);								// Muda estado da porta digital 13 (ledPin) conforme argumento OSC recebido
}
