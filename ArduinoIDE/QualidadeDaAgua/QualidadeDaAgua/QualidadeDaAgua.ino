const int pinoDiferencaPotencial = 35;
const int pinoEntradaDeLuz = 34;
const int pinoLed = 17;
int valorEntradaDeLuz = 0;
int valorDiferencaPotencial = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinoDiferencaPotencial, INPUT);
  pinMode(pinoEntradaDeLuz, INPUT);
  pinMode(pinoLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(pinoLed, 500);
  // Lê a entrada de um pino analógico
  valorEntradaDeLuz = analogRead(pinoEntradaDeLuz);

  // Serial.print("Valor analógico = ");
  Serial.print(valorEntradaDeLuz); 

  // // Estados determinados para a luz
  // if (valorEntradaDeLuz < 40) {
  //   Serial.println(" => Escuro");
  // } else if (valorEntradaDeLuz < 800) {
  //   Serial.println(" => Denso");
  // } else if (valorEntradaDeLuz < 2000) {
  //   Serial.println(" => Claro");
  // } else if (valorEntradaDeLuz < 3200) {
  //   Serial.println(" => Transparente");
  // } else {
  //   Serial.println(" => Muito Clara");
  // }

  // Lendo a condutividade da água
  valorDiferencaPotencial = analogRead(pinoDiferencaPotencial);
  Serial.print(", ");
  Serial.println(valorDiferencaPotencial);
  
  delay(500);
}
