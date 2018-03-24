/**
 * @brief Imprimindo em um Display Lcd 16x2 a leitura da porta Serial. Será impresso no display o que for digitado no teclado.    
 * @date 17/09/2014
 * @author Houston Santos
 */

// Bibliotecas a serem usadas 
#include <LiquidCrystal.h>

// Portas do Arduino associadas ao lcd 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Inicializando display 16x2 
  lcd.begin(16, 2);

  // Inicializa a interface serial 
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    delay(100);

    // Limpando lcd 
    lcd.clear();
  
    // Imprimindo no display a leitura serial 
    while (Serial.available() > 0) {
      lcd.write(Serial.read());
    }
  }
}
