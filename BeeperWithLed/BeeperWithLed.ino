const int PIN_LED    = 3;
const int PIN_BEEP   = 8;

const int FADE_STEP  = 5;

const int DELAY_BEEP = 75;
const int DELAY_FADE = 10;

void setup() {
  pinMode(PIN_BEEP, OUTPUT);
}

void beep() {
  digitalWrite(PIN_BEEP, HIGH);
  delay(DELAY_BEEP);
  digitalWrite(PIN_BEEP, LOW);
}

void loop() {
  for (int fadeValue = 0; fadeValue <= 255; fadeValue += FADE_STEP) {
    analogWrite(PIN_LED, fadeValue);
    delay(DELAY_FADE);
  }

  beep();

  for (int fadeValue = 255; fadeValue >= 0; fadeValue -= FADE_STEP) {
    analogWrite(PIN_LED, fadeValue);
    delay(DELAY_FADE);
  }
}

