#include <Adafruit_NeoPixel.h>

// ====== CONFIGURATION ======
#define PIN        1       // Data pin for NeoPixels
#define NUMPIXELS  7       // Number of NeoPixels
#define BRIGHTNESS 20     // Max brightness (0-255)
#define VARIATION  60      // Flicker variation amount (0-255)

// Create NeoPixel object
Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Base colors for each pixel (R, G, B)
uint8_t baseColors[NUMPIXELS][3] = {
  {128,   0, 128}, // Purple
  {  0,   0, 255}, // Blue
  {255, 165,   0}, // Orange
  {  0, 255,   0}, // Green
  {255, 255,   0}, // Yellow
  {  0, 255, 255}, // Cyan
  {255,   0,   0}  // Red
};

// Apply flicker to all pixels independently
void flickerAllPixels() {
  for (int i = 0; i < NUMPIXELS; i++) {
    int flicker = random(-VARIATION, VARIATION);

    int newR = constrain(baseColors[i][0] + flicker, 0, 255);
    int newG = constrain(baseColors[i][1] + flicker, 0, 255);
    int newB = constrain(baseColors[i][2] + flicker, 0, 255);

    strip.setPixelColor(i, strip.Color(newR, newG, newB));
  }

  strip.show();
  delay(random(100, 250)); // Random delay for natural flicker
}

void setup() {
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  flickerAllPixels();
}