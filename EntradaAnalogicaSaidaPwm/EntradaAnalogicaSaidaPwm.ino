/**   
 * @date 03/01/2016
 * @author Houston Santos
 */

// Portas do Arduino associadas 
const int analogInPin = A0;                                 
const int analogOutPin = 9;                                 

// Valor inicial do potenciometro 
int sensorValue = 0;

// Valor saída PWM 
int outputValue = 0;                                        

void setup() {
  // Inicializa a interface serial 
  Serial.begin(9600);
}

void loop() {
  // Fazendo leitura da entrada analógica 
  sensorValue = analogRead(analogInPin);  

  // Mapeando o resultado da entrada analógica dentro do intervalo de 0 a 255 
  outputValue = map(sensorValue, 0, 1023, 0, 255);

  // Muda o valor da saida analógica 
  analogWrite(analogOutPin, outputValue);                   
  
  // Imprimindo no lcd os valores de sensorValue e outputValue 
  Serial.print("Sensor = " );
  Serial.print(sensorValue);
  Serial.print("\t Output = ");
  Serial.println(outputValue);
  delay(300);
}
