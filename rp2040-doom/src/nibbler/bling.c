#include "apa102.h"
#include "bling.h"
#include "i_timer.h"
#include "doom/doomstat.h"

typedef enum {
  bling_mode_rainbow,
  bling_mode_damage,
  bling_mode_extralight,
  bling_mode_dead,
  __bling_mode_count
} bling_mode_t;

static bling_mode_t m_bling_mode = bling_mode_rainbow;
static uint32_t m_frame = 0;
static led_hsv_t m_hsv = {0.0, 1.0, 1.0};

static void __bling_mode_rainbow(uint8_t frame, void* p_data) {
  // Calculate step size such that each LED changes hue by less than one hue
  // step giving the effect of movement
  float step = 10; // Hue step between each LED
  float h = m_hsv.h;
  for (uint8_t i = 0; i < N_LEDS; i++) {
    apa102_led_set_hsv(i, (led_hsv_t){h, 1.0, 1.0});

    h += step;
    if (h >= HUE_MAX) {
      h -= HUE_MAX;
    }
  }

  m_hsv.h += 5.0; // Hue step each frame
  if (m_hsv.h >= HUE_MAX) {
    m_hsv.h -= HUE_MAX;
  }

  apa102_push();
}

static void __bling_mode_dead() {
  led_rgb_t rgb;
  rgb.r = rgb.b = rgb.g = 0;
  apa102_led_set_all(rgb);
  apa102_push();
}

static void __bling_mode_damage(int damagecount) {
  led_rgb_t rgb;
  float red = ((float)damagecount * 2.55);
  if (red > 255) {
    red = 255;
  }
  rgb.r = (uint8_t)red;
  rgb.b = rgb.g = 0;
  apa102_led_set_all(rgb);
  apa102_push();
}

static void __bling_mode_extralight(int extralight) {
  led_rgb_t rgb;
  if (extralight > 2) extralight = 2;
  rgb.r = rgb.b = rgb.g = extralight * 127;
  apa102_led_set_all(rgb);
  apa102_push();
}


void bling_update() {
    if (m_frame % 4) {
      m_bling_mode = bling_mode_rainbow;
      player_t *p = &players[0];

      if (p->playerstate == PST_DEAD) {
        m_bling_mode = bling_mode_dead;
      }
      // Gun flash
      else if (p->extralight > 0) {
        // printf("Extralight = %d\n", p->extralight);
        m_bling_mode = bling_mode_extralight;
      } 
      // Taking damage
      else if (p->damagecount > 0) {
        // printf("Damagecount = %d\n", p->damagecount);
        m_bling_mode = bling_mode_damage;
      } 

      // player_t* p = &players[0];
      switch (m_bling_mode) {
          case bling_mode_rainbow:
            __bling_mode_rainbow(m_frame, NULL);
            break;
          case bling_mode_damage:
            __bling_mode_damage(p->damagecount);
            break;
          case bling_mode_extralight:
            __bling_mode_extralight(p->extralight);
          case __bling_mode_count:
            break;
      }
    }
    m_frame++;
}