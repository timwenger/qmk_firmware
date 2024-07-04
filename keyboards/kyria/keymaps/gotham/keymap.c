/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include "keycodes.h"

#ifdef ENCODER_ENABLE
#    include "encoder_utils.h"
#endif

#ifdef OLED_DRIVER_ENABLE
#    include "oled_utils.h"
#endif

#ifdef THUMBSTICK_ENABLE
#    include "thumbstick.h"
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
*/
    [_QWERTY] = LAYOUT(
      ESC_RAISE,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     BSLS_RAISE,
      KC_LSFT,      KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  SFT_QUOT,
      KC_LCTL,      KC_Z,   KC_X,   KC_C,   KC_V,   KC_B, KC_LGUI, DF(_GAME),  TMB_MODE, KC_NO, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  CTL_MINS,
        ENC_MODE_L, KC_LALT, LT(_LOWER, KC_SPC), LT(_RAISE, KC_TAB), KC_LSFT,  KC_EQL, LT(_LOWER, KC_ENT), LT(_RAISE, KC_BSPC),  KC_DEL, ENC_MODE_R
    ),
/*
 * Game Layer: GAME
*/
    [_GAME] = LAYOUT(
      LT(_GAMENUM, KC_T),   KC_ESC,     KC_Q,   KC_W,   KC_E,   KC_R,                                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSLS,
      LT(_GAMENUM, KC_G),   KC_LSFT,    KC_A,   KC_S,   KC_D,   KC_F,                                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_RSFT,
      LT(_GAMENUM, KC_B),   KC_LCTL,    KC_Z,   KC_X,   KC_C,   KC_V, KC_NO, DF(_QWERTY),  TMB_MODE, KC_NO, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RCTL,
                         ENC_MODE_L, KC_LALT, KC_SPC, LT(_GAMENUM, KC_TAB), MO(_GAMENUM),  KC_EQL, KC_ENT, KC_BSPC, KC_DEL, ENC_MODE_R
    ),
/*
 * Game Number Layer: GAMENUM
*/
    [_GAMENUM] = LAYOUT(
      KC_NO,    KC_NO,  KC_1,   KC_2,   KC_3,   KC_NO,                                      KC_NO,  KC_F1,  KC_F2,  KC_F3,  KC_F10, KC_NO,
      KC_NO,    KC_0,   KC_4,   KC_5,   KC_6,   KC_NO,                                      KC_NO,  KC_F4,  KC_F5,  KC_F6,  KC_F11, KC_NO,
      KC_NO,    KC_NO,  KC_7,   KC_8,   KC_9,   KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_F7,  KC_F8,  KC_F9,  KC_F12, KC_NO,
                          _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______
    ),
/*
 * Lower Layer: Symbols, Navigation
 */
    [_LOWER] = LAYOUT(
      _______, KC_HASH, KC_DLR,  KC_LCBR, KC_RCBR, KC_PIPE,                                     _______, _______, _______, _______, _______, KC_PIPE,
      _______, KC_EXLM, KC_AT,   KC_LPRN, KC_RPRN, KC_GRV,                                      KC_AMPR, KC_PLUS, KC_ASTR, KC_SLSH, KC_PERC, KC_QUOT,
      _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______, _______, _______, KC_AMPR, KC_PIPE, KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                                 _______, _______, _______, KC_SCLN, KC_EQL,  KC_EQL,  KC_SCLN, _______, _______, _______
    ),
/*
 * Raise Layer: Number keys, media, more symbols
  */
    [_RAISE] = LAYOUT(
      _______, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7, KC_8,    KC_9,    KC_0,    _______,
      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                                     KC_PGUP, KC_LEFT, KC_UP,   KC_RGHT, _______, _______,
      _______, _______, _______, _______, KC_MUTE, KC_VOLD, _______, _______, _______, _______, KC_PGDN, KC_HOME, KC_DOWN, KC_END,  _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Adjust Layer: Function keys, RGB
  */
    [_ADJUST] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, _______, KC_F11,  KC_F12,  _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};
// clang-format on

void matrix_init_user(void) {
#ifdef ENCODER_ENABLE
    encoder_utils_init();
#endif
}

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_DRIVER_ENABLE
    if (!process_record_keymap_oled(keycode, record)) {
        return false;
    }
#endif
    switch (keycode) {
#ifdef ENCODER_ENABLE
        case ENC_MODE_L:
            if (record->event.pressed) {
                cycle_encoder_mode(true, false);
            }
            break;
        case ENC_MODE_R:
            if (record->event.pressed) {
                cycle_encoder_mode(false, false);
            }
            break;
#endif
#ifdef THUMBSTICK_ENABLE
        case TMB_MODE:
            if (record->event.pressed) {
                thumbstick_mode_cycle_forward();
            }
#endif
    }
    return true;
}

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        encoder_action(get_encoder_mode(true), clockwise);
#    ifdef OLED_DRIVER_ENABLE
        oled_on();
#    endif
    } else if (index == 1) {
        encoder_action(get_encoder_mode(false), clockwise);
#    ifdef OLED_DRIVER_ENABLE
        oled_on();
#    endif
    }
}
#endif
