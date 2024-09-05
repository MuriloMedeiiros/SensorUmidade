#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Configura o endereço I2C do LCD (0x27) e define que ele tem 16 colunas e 2 linhas
LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensor = A0; // Pino do sensor de umidade
int led = 8;     // Pino do LED
int nivel_umidade; // Variável para armazenar o nível de umidade

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial a 9600 bps
  lcd.begin(16, 2);   // Inicializa o LCD
  lcd.backlight();    // Liga a luz de fundo do LCD
  pinMode(sensor, INPUT); // Configura o pino do sensor como entrada
  pinMode(led, OUTPUT);   // Configura o pino do LED como saída
}

void loop() {
  nivel_umidade = analogRead(sensor); // Lê o valor do sensor de umidade
  Serial.print("Umidade: ");          // Imprime "Umidade: " no monitor serial
  Serial.println(nivel_umidade);      // Imprime o valor da umidade no monitor serial

  lcd.clear(); // Limpa o LCD
  if (nivel_umidade > 700) {
    lcd.print("ESTOU COM SEDE");   // Mostra "ESTOU COM SEDE" no LCD
    digitalWrite(led, HIGH);       // Liga o LED
  } else {
    lcd.print("HIDRATADA");        // Mostra "HIDRATADA" no LCD
    digitalWrite(led, LOW);        // Desliga o LED
  }

  delay(1000); // Espera por 1 segundo antes de repetir o loop
}
