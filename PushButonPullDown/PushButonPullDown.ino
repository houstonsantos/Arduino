/**
 * @brief Resitor Pull Down - Exemplo de utilização de um resitor pull down com toggle button
 * mantendo o estado do botão quando precionado e push button alternado o estado.    
 * @date 20/10/2014
 * @author Houston Santos
 */

// Portas do Arduino associadas 
const int ledPin = 13; 
const int botaoPin = 2;

// Estado inicial do botão 
int estadoBotao = 0;

void setup() {
	// Definindo portas como INPUT ou OUTPUT 
	pinMode(ledPin, OUTPUT); 
	pinMode(botaoPin, INPUT); 
}

void loop() {
	// Não mantendo o estado - push button 
	estadoBotao = digitalRead(botaoPin); 
	if (estadoBotao == HIGH) { 
		digitalWrite(ledPin, HIGH);
	} else {
		digitalWrite(ledPin, LOW);
		delay(300);
	  }
}
