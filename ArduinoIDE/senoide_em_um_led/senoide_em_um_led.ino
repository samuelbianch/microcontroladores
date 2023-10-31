#define LED_BUILTIN 17

const float sen[19] = {0, 0.1736, 0.342, 0.5, 0.6428, 0.766, 0.866, 0.9397, 0.9848, 1,
                    0.9848, 0.9397, 0.866, 0.766, 0.6428, 0.5, 0.342, 0.1736, 0};
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<19; i++){
    analogWrite(LED_BUILTIN, 127*sen[i]);
    delay(200);
  }
}
