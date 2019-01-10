/**
 * @date 20/10/2014
 * @author Houston Santos
 */

// Portas do Arduino associadas 
const int moviPin = 8;
const int ledPin = 13;                  

void setup() {
	// Definindo portas como INPUT ou OUTPUT 
	pinMode(moviPin, INPUT);              
	pinMode(ledPin, OUTPUT);               
}

void loop() {
	// Verificando valor do sensor para acionamento do relé 
	if(digitalRead(moviPin) == HIGH)  {
		digitalWrite(ledPin, HIGH);
	} else {
		digitalWrite(ledPin, LOW);
		delay(300);
	  }
}
