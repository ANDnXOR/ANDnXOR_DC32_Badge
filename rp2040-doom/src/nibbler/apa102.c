/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <math.h>
#include <stdio.h>

#include "apa102.h"
#include "apa102.pio.h"
#include "hardware/pio.h"
#include "pico/stdlib.h"

#define PIN_CLK 24
#define PIN_DIN 23

#define SERIAL_FREQ (5 * 1000 * 1000)

// Global brightness value 0->31
#define BRIGHTNESS 1

// LED RGB Data, this will be pushed to the LEDs per frame
static led_rgb_t _leds[N_LEDS];

// Pico PIO stuff
static PIO _pio = pio1;
static uint _sm = 0;

static led_rgb_t _hsv_to_rgb(led_hsv_t hsv) {
  led_rgb_t rgb;
  float fC = hsv.v * hsv.s; // Chroma
  float fHPrime = fmod(hsv.h / 60.0, 6);
  float fX = fC * (1 - fabs(fmod(fHPrime, 2) - 1));
  float fM = hsv.v - fC;
  float fR, fG, fB;

  if (0 <= fHPrime && fHPrime < 1) {
    fR = fC;
    fG = fX;
    fB = 0;
  } else if (1 <= fHPrime && fHPrime < 2) {
    fR = fX;
    fG = fC;
    fB = 0;
  } else if (2 <= fHPrime && fHPrime < 3) {
    fR = 0;
    fG = fC;
    fB = fX;
  } else if (3 <= fHPrime && fHPrime < 4) {
    fR = 0;
    fG = fX;
    fB = fC;
  } else if (4 <= fHPrime && fHPrime < 5) {
    fR = fX;
    fG = 0;
    fB = fC;
  } else if (5 <= fHPrime && fHPrime < 6) {
    fR = fC;
    fG = 0;
    fB = fX;
  } else {
    fR = 0;
    fG = 0;
    fB = 0;
  }

  fR += fM;
  fG += fM;
  fB += fM;
  rgb.r = (uint8_t)(fR * 255);
  rgb.g = (uint8_t)(fG * 255);
  rgb.b = (uint8_t)(fB * 255);
  return rgb;
}

/**
 * Initialize APA102 Driver
 */
void apa102_init() {
  printf("Initializing APA102 PIO Driver\n");

  uint offset = pio_add_program(_pio, &apa102_mini_program);
  apa102_mini_program_init(_pio, _sm, offset, SERIAL_FREQ, PIN_CLK, PIN_DIN);

  // Initialize LED RGB data to black
  memset(_leds, 0, N_LEDS * sizeof(led_rgb_t));

  apa102_push();
}

/**
 * Set LED value in memory
 */
void apa102_led_set(uint8_t index, led_rgb_t rgb) {
  if (index < N_LEDS) {
    _leds[index] = rgb;
  } else {
    printf("Invalid LED index %d > %d", index, (N_LEDS - 1));
  }
}

void apa102_led_set_all(led_rgb_t rgb) {
  for (uint8_t i = 0; i < N_LEDS; i++) {
    apa102_led_set(i, rgb);
  }
}

void apa102_led_set_hsv(uint8_t index, led_hsv_t hsv) {
  led_rgb_t rgb = _hsv_to_rgb(hsv);
  apa102_led_set(index, rgb);
}

/**
 * Push all LED data at once
 */
void apa102_push() {
  pio_sm_put_blocking(_pio, _sm, 0u); // Start frame
  for (uint8_t i = 0; i < N_LEDS; i++) {
    // Adjust brightness
    uint8_t r = _leds[i].r >> 2;
    uint8_t g = _leds[i].g >> 2;
    uint8_t b = _leds[i].b >> 2;
    pio_sm_put_blocking(
        _pio, _sm,
        0x7 << 29 |                     // magic
            (BRIGHTNESS & 0x1f) << 24 | // global brightness parameter
            (uint32_t)b << 16 | (uint32_t)g << 8 | (uint32_t)r << 0);
  }
  pio_sm_put_blocking(_pio, _sm, ~0u); // End frame
}