/**
 * @brief Leitura Serial - Imprime na porta serial o valor lido da porta do Arduino associada ao led   
 * @date 01/01/2016
 * @author Houston Santos
 */

// Portas do Arduino associadas 
const int botaoPin = 8;                 
const int ledPin = 13;                  

void setup() {
  // Inicializa a interface serial 
	Serial.begin(9600);

  // Definindo portas como INPUT ou OUTPUT 
	pinMode(botaoPin, INPUT_PULLUP);
	pinMode(ledPin, OUTPUT);              
}

void loop() {
  // Muda estado de led precionando o push button 
  if(digitalRead(botaoPin) == LOW) {
    digitalWrite(ledPin, HIGH);
  } else {
      digitalWrite(ledPin, LOW);
      delay(300);
    }
  // Impreime na serial o valor de LledPin 
  Serial.println(digitalRead(ledPin));
  delay(300);
}
