#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
// -------- OLED CONFIG ----------
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// -------- PIN DEFINITIONS ----------
#define LED1 25        // Red
#define LED2 26        // Yellow
#define LED3 27        // Optional Green
#define BUTTON_MODE 32 // Mode button
#define BUTTON_RESET 33 // Reset button
#define BUZZER 14

// -------- GLOBAL VARIABLES ----------
int mode = 0; // 0: OFF, 1: Alternate Blink, 2: Both ON, 3: PWM Fade
unsigned long lastPress = 0;
int fadeValue = 0;
int fadeDir = 1;

// -------- FUNCTION DECLARATIONS ----------
void showMode();

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON_MODE, INPUT_PULLUP);
  pinMode(BUTTON_RESET, INPUT_PULLUP);


  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("System Ready...");
  display.display();
  delay(1000);
  showMode();
  Serial.begin(9600);
}

void loop() {
  // ----- MODE BUTTON -----
  if (digitalRead(BUTTON_MODE) == LOW) {
    delay(200); // debounce
    mode = (mode + 1) % 4;
    showMode();
    while (digitalRead(BUTTON_MODE) == LOW); // wait for release
    Serial.println("LED HIGH");
  }

  // ----- RESET BUTTON -----
  if (digitalRead(BUTTON_RESET) == LOW) {
    delay(200);
    mode = 0;
    showMode();
    while (digitalRead(BUTTON_RESET) == LOW);
  }

  // ----- LED BEHAVIOR -----
  switch (mode) {
    case 0: // OFF
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      break;

    case 1: // Alternate blink
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      delay(300);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      delay(300);
      break;

    case 2: // Both ON
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      break;

    case 3: // PWM fade on LED1
      analogWrite(LED1, fadeValue);
      analogWrite(LED2, fadeValue);
      fadeValue += fadeDir * 10;
      if (fadeValue >= 255 || fadeValue <= 0) fadeDir = -fadeDir;
      delay(30);
      break;
  }
}

// -------- DISPLAY FUNCTION ----------
void showMode() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("LED Mode System");
  display.setCursor(0, 20);
  switch (mode) {
    case 0: display.println("Mode: OFF"); break;
    case 1: display.println("Mode: Alternate Blink"); break;
    case 2: display.println("Mode: Both ON"); break;
    case 3: display.println("Mode: PWM Fade"); break;
  }
  display.display();
