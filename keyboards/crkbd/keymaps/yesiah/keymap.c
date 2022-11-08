/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

// Test changes
#include QMK_KEYBOARD_H
#include <stdio.h>

// Custom macros for shorter key code
#define LCTLS LCTL_T(KC_S)
#define LALTD LALT_T(KC_D)
#define RCTLL RCTL_T(KC_L)
#define RALTK RALT_T(KC_K)
#define LGUICAP LGUI_T(KC_CAPS)
#define NUM_TAB LT(NUM, KC_TAB)
#define NAV_ENT LT(NAV, KC_ENT)

enum layers { BASE, NUM, SYM, NAV };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BSPC,    KC_A,   LCTLS,   LALTD,    KC_F,    KC_G,                         KC_H,    KC_J,   RALTK,   RCTLL, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LGUICAP, NUM_TAB,  KC_SPC,    NAV_ENT, MO(SYM), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      KC_PSLS,   KC_P7,   KC_P8,   KC_P9, KC_PMNS, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_DEL, _______, _______, _______, _______, _______,                      KC_PAST,   KC_P4,   KC_P5,   KC_P6, KC_PPLS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                       KC_EQL,   KC_P1,   KC_P2,   KC_P3, KC_PDOT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______,   KC_P0, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______,  KC_GRV, KC_MINS,  KC_EQL, _______,                      _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, _______, _______, _______, _______, _______,                      KC_HOME, _______,   KC_UP, _______, KC_PGUP, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                       KC_END, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};
// clang-format on

void render_base_layer_led(uint8_t led_min, uint8_t led_max) {
  for (uint8_t i = led_min; i <= led_max; i++) {
    rgb_matrix_set_color(i, RGB_OFF);
  }
}

void render_num_layer_led(uint8_t led_min, uint8_t led_max) {
  for (uint8_t i = led_min; i <= led_max; i++) {
    rgb_matrix_set_color(i, RGB_RED);
  }
}

void render_sym_layer_led(uint8_t led_min, uint8_t led_max) {
  for (uint8_t i = led_min; i <= led_max; i++) {
    rgb_matrix_set_color(i, RGB_GREEN);
  }
}

void render_nav_layer_led(uint8_t led_min, uint8_t led_max) {
  for (uint8_t i = led_min; i <= led_max; i++) {
    rgb_matrix_set_color(i, RGB_BLUE);
  }
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  switch (biton32(layer_state)) {
    case NUM:
      render_num_layer_led(led_min, led_max);
      break;
    case SYM:
      render_sym_layer_led(led_min, led_max);
      break;
    case NAV:
      render_nav_layer_led(led_min, led_max);
      break;
    default:
      render_base_layer_led(led_min, led_max);
      break;
  }
}

// Per key, per layer RGBs
//
// LED indexing
//   number: number on the build guide, 1-index
//   id: used in code, 0-index
// lhs id = number - 1
// rhs id = number + 26
// num leds between ids = to - from + 1
// const rgblight_segment_t PROGMEM my_base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 13, HSV_OFF}, {13, 1, HSV_MAGENTA}, {14, 26, HSV_OFF},
//     {40, 1, HSV_YELLOW}, {41, 13, HSV_OFF});

// Num layer
// const rgblight_segment_t PROGMEM my_num_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     // Delete: LHS 26 white
//     {25, 1, HSV_WHITE},
//     // Numpad: RHS 11~14, 16~21 magenta
//     {37, 4, HSV_MAGENTA}, {42, 6, HSV_MAGENTA},
//     // Numpad symbols: RHS 8~10, 22~24 yellow
//     {34, 3, HSV_YELLOW}, {48, 3, HSV_YELLOW});

// const rgblight_segment_t PROGMEM my_sym_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     // Number row: LHS 10~11, 18~19, 24 Yellow
//     //             RHS 10~11, 18~19, 24 Yellow
//     {9, 2, HSV_YELLOW}, {17, 2, HSV_YELLOW}, {23, 1, HSV_YELLOW},
//     {36, 2, HSV_YELLOW}, {44, 2, HSV_YELLOW}, {50, 1, HSV_YELLOW},
//     // Backtick, minus, equal: LHS 13, 16, 21 cyan
//     {12, 1, HSV_CYAN}, {15, 1, HSV_CYAN}, {20, 1, HSV_CYAN},
//     // Symbols: LHS 9, 12, 17, 20, 23 Orange
//     //          RHS 9 12 17 Orange
//     {8, 1, HSV_ORANGE}, {11, 1, HSV_ORANGE}, {16, 1, HSV_ORANGE},
//     {19, 1, HSV_ORANGE}, {22, 1, HSV_ORANGE}, {35, 1, HSV_ORANGE},
//     {38, 1, HSV_ORANGE}, {43, 1, HSV_ORANGE},
//     // Brackets: RHS 13 16 20 21 22 23 Magenta
//     {39, 1, HSV_MAGENTA}, {42, 1, HSV_MAGENTA}, {46, 4, HSV_MAGENTA});

// const rgblight_segment_t PROGMEM my_nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     // Nav: RHS 9~10, 23~24 magenta
//     {35, 2, HSV_MAGENTA}, {49, 2, HSV_MAGENTA},
//     // Arrow keys: RHS 12, 17~18, 20 yellow
//     {38, 1, HSV_YELLOW}, {43, 2, HSV_YELLOW}, {46, 1, HSV_YELLOW},
//     // Volume control: RHS 13, 16, 21 cyan
//     {39, 1, HSV_CYAN}, {42, 1, HSV_CYAN}, {47, 1, HSV_CYAN});

// Now define the array of layers. Later layers take precedence
// const rgblight_segment_t *const PROGMEM my_rgb_layers[] =
// RGBLIGHT_LAYERS_LIST(
//     my_base_layer, my_num_layer, my_sym_layer, my_nav_layer);

// void keyboard_post_init_user(void) {
//   // Enable the LED layers
//   rgblight_layers = my_rgb_layers;
// }

// layer_state_t default_layer_state_set_user(layer_state_t state) {
//   rgblight_set_layer_state(BASE, layer_state_cmp(state, BASE));
//   return state;
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//   rgblight_set_layer_state(NUM, layer_state_cmp(state, NUM));
//   rgblight_set_layer_state(SYM, layer_state_cmp(state, SYM));
//   rgblight_set_layer_state(NAV, layer_state_cmp(state, NAV));
//   return state;
// }

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
  oled_write_P(PSTR("Layer: "), false);
  switch (layer_state) {
    case L_BASE:
      oled_write_ln_P(PSTR("Default"), false);
      break;
    case L_LOWER:
      oled_write_ln_P(PSTR("Lower"), false);
      break;
    case L_RAISE:
      oled_write_ln_P(PSTR("Raise"), false);
      break;
    case L_ADJUST:
    case L_ADJUST | L_LOWER:
    case L_ADJUST | L_RAISE:
    case L_ADJUST | L_LOWER | L_RAISE:
      oled_write_ln_P(PSTR("Adjust"), false);
      break;
  }
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ',  ' ', ' ', 'a',  'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j',  'k', 'l', 'm',  'n', 'o', 'p', 'q', 'r', 's', 't',
    'u', 'v',  'w', 'x', 'y',  'z', '1', '2', '3', '4', '5', '6',
    '7', '8',  '9', '0', 'R',  'E', 'B', 'T', '_', '-', '=', '[',
    ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
  if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
      (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
    keycode = keycode & 0xFF;
  }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col, keycode, name);
}

void oled_render_keylog(void) { oled_write(keylog_str, false); }

void render_bootmagic_status(bool status) {
  /* Show Ctrl-Gui Swap options */
  static const char PROGMEM logo[][2][3] = {
      {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
      {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
  };
  if (status) {
    oled_write_ln_P(logo[0][0], false);
    oled_write_ln_P(logo[0][1], false);
  } else {
    oled_write_ln_P(logo[1][0], false);
    oled_write_ln_P(logo[1][1], false);
  }
}

void oled_render_logo(void) {
  static const char PROGMEM crkbd_logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a,
      0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0,
      0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab,
      0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1,
      0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc,
      0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};
  oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_render_layer_state();
    oled_render_keylog();
  } else {
    oled_render_logo();
  }
  return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif  // OLED_ENABLE
