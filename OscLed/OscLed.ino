/**
 * @brief Acionamento de led com utilização do protocolo OSC para comunicação com o Arduino via tcp/ip.    
 * @date 04/01/2016
 * @author Houston Santos
 */

// Bibliotecas a serem usadas 
#include <SPI.h>														                      
#include <Ethernet.h>													                      
#include <ArdOSC.h>

// IP & MAC para shield ethernet 
byte myMac[] = { 0x90, 0xA2, 0xDA, 0x0F, 0x2C, 0xDE };				
byte myIp[] = { 192, 168, 25, 155 };								

// Porta de envio e recepção OSC 
const int serverPort = 8000;													
const int destPort = 9000;													

// Porta do Arduino associada 
const int ledPin = 13;													

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
}
  
void loop() {
	// Verifica se existe alguma mensagem OSC disponível para leitura 
	if(server.availableCheck()>0) {										                  	  
 	
	}
}

// Acendendo o led 
void acenderLed(OSCMessage *_mes) {								// Rotina que trata comando OSC "/HS/ledPin" recebido do ANDROID
	int value = (int)_mes->getArgFloat(0);						// Armazena em "value" o argumento do comando OSC "/HS/ledPin"
	digitalWrite(ledPin, value);								// Muda estado da porta digital 13 (ledPin) conforme argumento OSC recebido
	newMes.setAddress(_mes->getIpAddress(), destPort);			// Define endereço e porta para mensagem OSC
	newMes.beginMessage("/HS/ledPin"); 							// Define o Comando OSC
	newMes.addArgFloat(value);									// Define o novo estado do comando que sera enviado para o dispositivo móvel															
    client.send(&newMes);										// Envia mensagem OSC atualizando o estado no dispositivo móvel
}
