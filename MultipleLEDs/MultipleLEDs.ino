const int PIN_LED_GREEN  = 3;
const int PIN_LED_ORANGE = 5;
const int PIN_LED_RED    = 9;

const int LEDS[] = {
  PIN_LED_GREEN,
  PIN_LED_ORANGE,
  PIN_LED_RED
};

const int FADE_STEP  = 5;
const int DELAY_FADE = 6;
const int LEDS_SIZE = sizeof(LEDS) / sizeof(int);

int current_leds = 0;
int direction = 1;

void setup() {
  pinMode(PIN_LED_GREEN,  OUTPUT);
  pinMode(PIN_LED_ORANGE, OUTPUT);
  pinMode(PIN_LED_RED,    OUTPUT);
}

void loop() {
  for (int fadeValue = 0; fadeValue <= 255; fadeValue += FADE_STEP) {
    analogWrite(LEDS[current_leds], fadeValue);
    delay(DELAY_FADE);
  }

  for (int fadeValue = 255; fadeValue >= 0; fadeValue -= FADE_STEP) {
    analogWrite(LEDS[current_leds], fadeValue);
    delay(DELAY_FADE);
  }

  if (current_leds == LEDS_SIZE - 1) {
   direction = -1;
  } else if (current_leds == 0) {
    direction = 1;
  }

  current_leds = (current_leds + direction) % LEDS_SIZE;
}

