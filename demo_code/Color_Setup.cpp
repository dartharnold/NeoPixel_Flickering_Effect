// Crystal Colors in Hex
#define BLACK         0x00000000    // rgb(0, 0, 0)
#define WHITE         0x00FFFFFF    // rgb(255, 255, 255)
#define RED           0x00FF0000    // rgb(255, 0, 0)
#define CRIMSONRED    0x00DC143C    // rgb(220, 20, 60)  
#define PURPLE        0x00FF00FF    // rgb(255, 0, 255)  
#define DARKPURPLE    0x00301934    // rgb(48, 25, 52)  
#define BLUE          0x0000008B    // rgb(0, 0, 139)
#define CYAN          0x0000FFFF    // rgb(0, 255, 255)
#define GREEN         0x0000FF00    // rgb(0, 255, 0)
#define YELLOW        0x00FFBF00    // rgb(255, 191, 0)
#define ORANGE        0x00FF7E00    // rgb(255, 126, 0) 

// Setup Array for RGB Values

#define COLOR_COUNT 11

#define BLACK         0
#define WHITE         1
#define RED           2
#define CRIMSONRED    3
#define PURPLE        4
#define DARKPURPLE    5
#define BLUE          6
#define CYAN          7
#define GREEN         8
#define YELLOW        9
#define ORANGE        10

#define RGB_RED       0
#define RGB_GREEN     1
#define RGB_BLUE      2

uint8_t baseColors[COLOR_COUNT][3] = {
  {0, 0, 0},       // BLACK       rgb(0, 0, 0)
  {255, 255, 255}, // WHITE       rgb(255, 255, 255)
  {255, 0, 0},     // RED         rgb(255, 0, 0)
  {220, 20, 60},   // CRIMSONRED  rgb(220, 20, 60)
  {255, 0, 255},   // PURPLE      rgb(255, 0, 255)
  {48, 25, 52},    // DARKPURPLE  rgb(48, 25, 52)
  {0, 0, 139},     // BLUE        rgb(0, 0, 139)
  {0, 255, 255},   // CYAN        rgb(0, 255, 255)
  {0, 255, 0},     // GREEN       rgb(0, 255, 0)
  {255, 191, 0},   // YELLOW      rgb(255, 191, 0)
  {255, 126, 0}    // ORANGE      rgb(255, 126, 0)
};

// Example usage: Set strip X Pixel Y to Green
strip[x].setPixelColor(y, baseColors[GREEN][RGB_RED], baseColors[GREEN][RGB_GREEN], baseColors[GREEN][RGB_BLUE]);  // Set strip X Pixel Y to Green



