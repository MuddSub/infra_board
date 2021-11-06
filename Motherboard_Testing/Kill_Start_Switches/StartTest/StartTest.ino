// When the start pin is powered, the built-in LED of the teensy should light up.

// Value of kill pin & LED pin:
const int killPin = 26;
const int ledPin = LED_BUILTIN;

// ledState variable:
int ledState = LOW;

// Variable to hold time:
unsigned long previousMillis = 0;       // Stores last time LED was updated

// Constants won't change:
const long interval = 20;         // Interval at which to blink (milliseconds)

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin, INPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    if (digitalRead(killPin)) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);
  }
}
