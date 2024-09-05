#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Configura o endereço I2C do LCD (0x27) e define que ele tem 16 colunas e 2 linhas
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin(16, 2);   // Inicializa o LCD com 16 colunas e 2 linhas
  lcd.backlight();    // Liga a luz de fundo do LCD

  // Exibe mensagens de teste
  lcd.setCursor(0, 0); // Move o cursor para a coluna 0, linha 0
  lcd.print("Teste do LCD"); // Imprime a mensagem na primeira linha
  lcd.setCursor(0, 1); // Move o cursor para a coluna 0, linha 1
  lcd.print("Linha 2 ok"); // Imprime a mensagem na segunda linha
}

void loop() {
  // Nenhuma ação é necessária no loop para este teste
}
