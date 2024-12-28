// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

# include QMK_KEYBOARD_H
# include "print.h"
# include "g/keymap_combo.h"

enum layer_names {
  HOME,
  AROW,
  NUM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     * +-----------------------------------------+                             +-----------------------------------------+
     * | boot |   q  |   w  |   f  |   p  |   g  |                             |   j  |   l  |   u  |   y  | esc  | boot |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | TAB  |   a  |   r  |   s  |   t  |   d  |                             |   h  |   n  |   e  |   i  |   o  | enter|
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | N/A  |   z  |   x  |   c  |   v  |   b  |                             |   k  |   m  |   ,  |   .  |   ?  | N/A  |
     * +------+------+------+------+------+------+                             +------+------+------+------+------+------+
     *               |  N/A | N/A  |sh/bpc|                                           |sh/spc|  \   |  /   |
     *               +------+-------------+------+                             +------+------+------+------+
     *                             |  alt | ctr  |                             | ctr  |  alt |
     *                             +------+------+                             +------+------+

     */
    [HOME] = LAYOUT(
        QK_BOOTLOADER,  KC_Q,           KC_W,     KC_F,     KC_P,             KC_G,             KC_J,            KC_L,    KC_U,    KC_Y,    KC_ESC,          QK_BOOTLOADER,
        KC_TAB,         LT(NUM, KC_A),  KC_R,     KC_S,     KC_T,             KC_D,             KC_H,            KC_N,    KC_E,    KC_I,    LT(AROW, KC_O),  KC_ENT,
        KC_NO,          KC_Z,           KC_X,     KC_C,     KC_V,             KC_B,             KC_K,            KC_M,    KC_COMM, KC_DOT,  KC_QUES,         KC_NO,
                                        KC_BSLS,  KC_PIPE,  LSFT_T(KC_BSPC),  KC_NO,            RSFT_T(KC_SPC),  KC_NO,   KC_NO,   KC_NO,
                                                            KC_LALT,          KC_LCTL,          KC_RCTL,         KC_RALT
    ),
    [AROW] = LAYOUT(
        KC_NO,          KC_NO,          KC_NO,    KC_UP,    KC_NO,            KC_NO,            KC_F12,           KC_F7,  KC_F8,   KC_F9,   KC_NO,           KC_NO,
        KC_NO,          KC_HOME,        KC_LEFT,  KC_DOWN,  KC_RGHT,          KC_END,           KC_F11,           KC_F4,  KC_F5,   KC_F6,   KC_NO,           KC_NO,
        KC_NO,          KC_NO,          KC_NO,    KC_NO,    KC_NO,            KC_NO,            KC_F10,           KC_F1,  KC_F2,   KC_F3,   KC_NO,           KC_NO,
                                        KC_NO,    KC_NO,    LSFT_T(KC_BSPC),  KC_NO,            RSFT_T(KC_SPC),   KC_NO,  KC_NO,   KC_NO,
                                                            KC_LALT,          KC_LCTL,          KC_RCTL,          KC_RALT
    ),
    [NUM] = LAYOUT(
        KC_NO,          KC_NO,          KC_NO,    KC_NO,    KC_NO,            KC_NO,            KC_F12,           KC_7,   KC_8,    KC_9,   KC_NO,           KC_NO,
        KC_NO,          KC_NO,          KC_NO,    KC_NO,    KC_NO,            KC_NO,            KC_F11,           KC_4,   KC_5,    KC_6,   KC_KP_EQUAL,     KC_NO,
        KC_NO,          KC_NO,          KC_NO,    KC_NO,    KC_NO,            KC_NO,            KC_F10,           KC_1,   KC_2,    KC_3,   KC_NO,           KC_NO,
                                        KC_NO,    KC_NO,    LSFT_T(KC_BSPC),  KC_NO,            RSFT_T(KC_SPC),   KC_0,   KC_DOT,  KC_NO,
                                                            KC_LALT,          KC_LCTL,          KC_RCTL,          KC_RALT
    )
};

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  mod_state = get_mods();

  switch(keycode) { 
    // Switch backspace for a delete press, if holding shift
    // https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md#shift--backspace-for-delete-shift-backspace-for-delete
    // This case, LSFT_T(KC_BSPC), has to capture the whole feature code of the
    // left thumb press, not just KC_BSPC
    case LSFT_T(KC_BSPC): {
      static bool delkey_registered;

      if (record->event.pressed) {  // On key press.
        if (keyboard_report->mods & MOD_BIT(KC_RSFT)) {
          // First temporarily canceling shift so that
          // shift isn't applied to the KC_DEL keycode
          del_mods(MOD_MASK_SHIFT);
          register_code(KC_DEL);

          // Update the boolean variable to reflect the status of KC_DEL
          delkey_registered = true;

          // Reapplying modifier state so that the held shift key
          // still works even after having tapped the Backspace/Delete key.
          set_mods(mod_state);
          return false;
        }
        // if the right shift wasn't pressed, return true and do the normal LSFT_T(KC_BSPC)
        return true;

      } else { // on release of LSFT_T(KC_BSPC)
        // In case KC_DEL is still being sent even after the release of LSFT_T(KC_BSPC)
        if (delkey_registered) {
          unregister_code(KC_DEL);
          delkey_registered = false;
          return false;
        }
      }
    }
  };



  return true;
}

// int count = 0;
// report_mouse_t pointing_device_task_user(report_mouse_t left_report) {

  // count++;
  // if (count >10){
  //   count = 0;
  //   // convert right hand side to scrolling
  //   // once I have the right side built, I may need to invert these values
  //   if (right_report.x>0){
  //     right_report.h = 1;
  //   } else if (right_report.x <0){
  //     right_report.h = -1;
  //   }
  //   if (right_report.y>0){
  //     right_report.v = 1;
  //   } else if (right_report.y <0){
  //     right_report.v = -1;
  //   }
  // }

  // right_report.x = 0;
  // right_report.y = 0;

//   int16_t X = analogReadPin(ANALOG_JOYSTICK_X_AXIS_PIN);
//   int16_t Y = analogReadPin(ANALOG_JOYSTICK_Y_AXIS_PIN);
//   int16_t button = analogReadPin(GP28);

//   uprintf("x: %5d y: %5d X: %5d Y: %5d Button: %5d\n", left_report.x, left_report.y, X, Y, button);
//   return left_report;
// }

//void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
//}