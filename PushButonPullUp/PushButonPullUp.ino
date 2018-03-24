/**
 * @brief Resitor Pull Up - Exemplo de utilização de um resitor pull up com toggle button mantendo o estado 
 * do botão quando precionado e push button alternado o estado.    
 * @date 20/10/2014
 * @author Houston Santos
 */

// Portas do Arduino associadas 
const int botaoPin = 8;                 
const int ledPin = 13;                  

void setup() {
	// Definindo portas como INPUT ou OUTPUT 
  	pinMode(botaoPin, INPUT_PULLUP);
	pinMode(ledPin, OUTPUT);              
}

void loop() {
	// Mantendo o estado - toggle button 
	/*if(digitalRead(botaoPin) == LOW) { 
		int state = digitalRead(ledPin);
		digitalWrite(ledPin, !state);
		delay(300);
	}*/
 	
 	// Não mantendo o estado - push button 
	if(digitalRead(botaoPin) == LOW) {
		digitalWrite(ledPin, HIGH);
	} else {
		digitalWrite(ledPin, LOW);
		delay(300);
      }
}
