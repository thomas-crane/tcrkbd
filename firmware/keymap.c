/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2021 Thomas Crane <thomasgcrane@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "raw_hid.h"

#include "./layout.c"

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_NUMPAD 2
#define L_SYMBOLS 4
#define L_ARROWS 8

void oled_render_layer_state(void) {
  oled_write_P(PSTR("Layer: "), false);
  switch (layer_state) {
    case L_BASE:
      oled_write_ln_P(PSTR("Default"), false);
      break;
    case L_NUMPAD:
      oled_write_ln_P(PSTR("Numpad"), false);
      break;
    case L_SYMBOLS:
      oled_write_ln_P(PSTR("Symbols"), false);
      break;
    case L_ARROWS:
    case L_ARROWS|L_NUMPAD:
    case L_ARROWS|L_SYMBOLS:
    case L_ARROWS|L_NUMPAD|L_SYMBOLS:
      oled_write_ln_P(PSTR("Arrows"), false);
      break;
  }
}


char keylog_str[24] = {};
char wpm_str[24] = {};
uint8_t wpm_high = 0;

const char code_to_name[60] = {
  ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
  'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
  'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
  '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
  'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
  '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '
};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
  if (
    (keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)
  ) {
    keycode = keycode & 0xFF;
  }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(
    keylog_str,
    sizeof(keylog_str),
    "%dx%d, k%2d : %c",
    record->event.key.row,
    record->event.key.col,
    keycode,
    name
  );
}

void oled_render_keylog(void) {
  oled_write_ln(keylog_str, false);
}

void oled_render_wpm(void) {
  uint8_t wpm_current = get_current_wpm();
  if (wpm_current > wpm_high) {
    wpm_high = wpm_current;
  }

  snprintf(wpm_str, sizeof(wpm_str), "WPM Hi: %d", wpm_high);
  oled_write(wpm_str, false);
}

void oled_render_logo(void) {
  static const char PROGMEM crkbd_logo[] = {
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
    0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
    0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
    0,
  };
  oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
  if (is_master) {
    oled_render_layer_state();
    oled_render_keylog();
    oled_render_wpm();
  } else {
    oled_render_logo();
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE
