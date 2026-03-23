#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

// ====== CONFIGURATION ======
#define PIN1       1       // Data pin for first NeoPixel string
#define PIN2       2       // Data pin for second NeoPixel string
#define PIXELS1    3       // Number of pixels on first string
#define PIXELS2    3       // Number of pixels on second string
#define BRIGHTNESS 200     // Max brightness (0-255)
#define VARIATION  30      // Flicker variation amount (0-255)

// Create NeoPixel objects
Adafruit_NeoPixel strip1(PIXELS1, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(PIXELS2, PIN2, NEO_GRB + NEO_KHZ800);

// Base colors for each pixel (R, G, B) — 6 colors total
uint8_t baseColors[6][3] = {
  {128,   0, 128}, // Purple
  {  0,   0, 255}, // Blue
  {  0, 255, 255}, // Cyan
  {  0, 255,   0}, // Green
  {255, 255,   0}, // Yellow
  {255, 165,   0}  // Orange
};

// Apply flicker to all pixels in both strips
void flickerAllPixels() {
  // First strip (pixels 0–2 in baseColors)
  for (int i = 0; i < PIXELS1; i++) {
    int flicker = random(-VARIATION, VARIATION);
    int newR = constrain(baseColors[i][0] + flicker, 0, 255);
    int newG = constrain(baseColors[i][1] + flicker, 0, 255);
    int newB = constrain(baseColors[i][2] + flicker, 0, 255);
    strip1.setPixelColor(i, strip1.Color(newR, newG, newB));
  }

  // Second strip (pixels 3–5 in baseColors)
  for (int i = 0; i < PIXELS2; i++) {
    int flicker = random(-VARIATION, VARIATION);
    int newR = constrain(baseColors[i + PIXELS1][0] + flicker, 0, 255);
    int newG = constrain(baseColors[i + PIXELS1][1] + flicker, 0, 255);
    int newB = constrain(baseColors[i + PIXELS1][2] + flicker, 0, 255);
    strip2.setPixelColor(i, strip2.Color(newR, newG, newB));
  }

  strip1.show();
  strip2.show();

  delay(random(100, 250)); // Random delay for natural flicker
}

void setup() {
  strip1.begin();
  strip2.begin();
  strip1.setBrightness(BRIGHTNESS);
  strip2.setBrightness(BRIGHTNESS);
  strip1.show();
  strip2.show();
}

void loop() {
  flickerAllPixels();
}