//Hiba Fatima
//23-Ntu-cs-1037
//Task B — Coding: Use a single button with press-type detection (display the event on the 
//OLED): 
// Short press → toggle LED 
//Long press (> 1.5 s) → play a buzzer tone
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Function Prototypes (Declarations)
void shortBeep();
void showMessage(String msg);
void playMelody();



// ---------- OLED CONFIG ----------
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// ---------- PIN DEFINITIONS ----------
#define BUTTON 32
#define LED 25
#define BUZZER 14

// ---------- GLOBAL VARIABLES ----------
bool ledState = false;
unsigned long pressStart = 0;
bool isPressed = false;

// ---------- SETUP ----------
void setup() {
  pinMode(BUTTON, INPUT_PULLUP);   // button connected to GND
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("System Ready...");
  display.display();
  delay(1000);
  showMessage("Waiting for button...");
}

// ---------- MAIN LOOP ----------
void loop() {
  int buttonState = digitalRead(BUTTON);

  // detect press
  if (buttonState == LOW && !isPressed) {
    isPressed = true;
    pressStart = millis(); // time press began
  }

  // detect release
  if (buttonState == HIGH && isPressed) {
    isPressed = false;
    unsigned long pressDuration = millis() - pressStart;

    if (pressDuration > 1500) {
      // Long press -> play buzzer melody
      playMelody();
      showMessage("Long Press -> Melody");
    } else {
      // Short press -> toggle LED + short beep
      ledState = !ledState;
      digitalWrite(LED, ledState);
      shortBeep();
      showMessage("Short Press -> LED " + String(ledState ? "ON" : "OFF"));
    }
  }
}

// ---------- FUNCTIONS ----------
void playMelody() {
  // simple 3-tone melody for long press
  tone(BUZZER, 500, 200);   // low tone
  delay(250);
  tone(BUZZER, 800, 200);   // medium tone
  delay(250);
  tone(BUZZER, 1200, 300);  // high tone
  delay(350);
  noTone(BUZZER);
}

void shortBeep() {
  // quick beep for short press
  tone(BUZZER, 1000, 100);
  delay(150);
  noTone(BUZZER);
}

void showMessage(String msg) {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Button Event:");
  display.setCursor(0, 20);
  display.println(msg);
  display.display();
}