#ifndef APA102_H
#define APA102_H

#include "pico.h"

#define N_LEDS 17
#define HUE_MIN 0
#define HUE_MAX 360

typedef struct {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} led_rgb_t;

typedef struct {
  float h; // 0 to 360
  float s; // 0 to 1
  float v; // 0 to 1ß
} led_hsv_t;

#define LED_BLACK                                                              \
  (led_rgb_t) { 0, 0, 0 }
#define LED_RED                                                                \
  (led_rgb_t) { 255, 0, 0 }
#define LED_GREEN                                                              \
  (led_rgb_t) { 0, 255, 0 }
#define LED_BLUE                                                               \
  (led_rgb_t) { 0, 0, 255 }
#define LED_YELLOW                                                             \
  (led_rgb_t) { 255, 255, 0 }

extern void apa102_init();
extern void apa102_led_set(uint8_t index, led_rgb_t rgb);
extern void apa102_led_set_all(led_rgb_t rgb);
extern void apa102_led_set_hsv(uint8_t index, led_hsv_t hsv);
/**
 * Converts HSV to RGB values
 * fH: hue value 0 to 360
 * fS: saturation 0 to 1
 * fV: Value 0 to 1
 */
extern led_rgb_t HSVtoRGB(float fH, float fS, float fV);
extern void apa102_push();

#endif