/**
 * @brief Dimmer - Acionamento de led RGB com OSC via tcp/ip, controlando itensidade das cores.    
 * @date 10/10/2014
 * @author Houston Santos
 */

// Bibliotecas a serem usadas 
#include <SPI.h>
#include <Ethernet.h>
#include <ArdOSC.h>

// Definindo saídas analógica 
#define RED 3 
#define BLUE 5 
#define GREEN 6 

// IP & MAC para shield ethernet 
byte myMac[] = { 0x90, 0xA2, 0xDA, 0x0F, 0x2C, 0xDE };
byte myIp[] = { 192, 168, 25, 155 };

// Porta de envio e recepção OSC 
const int serverPort = 8000;
const int destPort = 9000;

// Inicializando servidor e cliente OSC 
OSCServer server;
OSCClient client;

// Cria uma nova menssagem OSC 
OSCMessage newMes;

void setup() { 
	Serial.begin(9600);
	Ethernet.begin(myMac ,myIp); 
	server.begin(serverPort);
 
	// Definindo funções OSC 
	server.addCallback("/rgb/red", &func1);
	server.addCallback("/rgb/blue", &func2);
	server.addCallback("/rgb/green", &func3);
	
	// Definindo portas como INPUT ou OUTPUT 
	pinMode (RED, OUTPUT); 
	pinMode (BLUE, OUTPUT); 
	pinMode (GREEN, OUTPUT);  
}
  
void loop() {
	// Verifica se existe alguma mensagem OSC disponível para leitura 
	if(server.availableCheck()>0) {
	 
	}
}

// Fução que trata a cor RED 
void func1(OSCMessage *_mes) {
	int red = (int)_mes->getArgFloat(0);
	analogWrite(RED, red);
	newMes.setAddress(_mes->getIpAddress(), destPort);
	newMes.beginMessage("/rgb/red");
	newMes.addArgFloat(red);
	client.send(&newMes);
}
 
// Fução que trata a cor BLUE 
void func2(OSCMessage *_mes) {
	int blue = (int)_mes->getArgFloat(0);
	analogWrite(BLUE, blue);
	newMes.setAddress(_mes->getIpAddress(), destPort);
	newMes.beginMessage("/rgb/blue");
	newMes.addArgFloat(blue);
	client.send(&newMes);
}

// Fução que trata a cor GREEN 
void func3(OSCMessage *_mes) {
	int green = (int)_mes->getArgFloat(0);
	analogWrite(GREEN, green);
	newMes.setAddress(_mes->getIpAddress(), destPort);
	newMes.beginMessage("/rgb/green");
	newMes.addArgFloat(green);
	client.send(&newMes);
}  
  