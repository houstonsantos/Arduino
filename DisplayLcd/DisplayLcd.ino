/**    
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
  // Limpando lcd 
  lcd.clear();

  // Colocando o cursor na posição (Aij) 
  lcd.setCursor(0,0);

  // Imprimindo no lcd 
  lcd.print(" Houston Santos");
  lcd.setCursor(0,1);
  lcd.print("   & Ana Melo  ");
  delay(1000);
 
  // Movimentando texto 
  for (int esquerda = 0; esquerda < 15; esquerda++) {
    lcd.scrollDisplayLeft();
    delay(300);
  }
}
