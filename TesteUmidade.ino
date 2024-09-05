int sensor = A0;  // Pino do sensor de umidade
int valor_umidade;  // Variável para armazenar o valor lido do sensor

void setup() {
  Serial.begin(9600);  // Inicializa a comunicação serial a 9600 bps
  pinMode(sensor, INPUT);  // Configura o pino do sensor como entrada
}

void loop() {
  valor_umidade = analogRead(sensor);  // Lê o valor analógico do sensor de umidade
  Serial.print("Valor de umidade: ");  // Imprime a mensagem "Valor de umidade: " no Monitor Serial
  Serial.println(valor_umidade);  // Imprime o valor lido do sensor no Monitor Serial
  
  delay(1000);  // Espera por 1 segundo antes de ler o valor novamente
}
