// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

# include QMK_KEYBOARD_H
# include "print.h"
# include "g/keymap_combo.h"

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
    [0] = LAYOUT(
        QK_BOOTLOADER,  KC_Q,    KC_W,    KC_F,    KC_P,             KC_G,               KC_J,            KC_L,    KC_U,    KC_Y,    KC_ESC,  QK_BOOTLOADER,
        KC_TAB,         KC_A,    KC_R,    KC_S,    KC_T,             KC_D,               KC_H,            KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
        KC_NO,          KC_Z,    KC_X,    KC_C,    KC_V,             KC_B,               KC_K,            KC_M,    KC_COMM, KC_DOT,  KC_QUES, KC_NO,
                                 KC_NO,   KC_NO,   LSFT_T(KC_BSPC),  KC_NO,              RSFT_T(KC_SPC),  KC_BSLS, KC_SLSH, KC_NO,
                                                   KC_LALT,          KC_LCTL,            KC_RCTL,         KC_RALT
    )
};


// bool process_record_user(uint16_t keycode, keyrecord_t *record)
// {
//   // https://www.monotux.tech/posts/2024/09/qmk-shift-backspace-delete/

//   switch(keycode) { // switch backspace for a delete press, if holding shift
//     case KC_BSPC: {
//       static uint16_t registered_key = KC_NO;
//       if (record->event.pressed) {  // On key press.
//         const uint8_t mods = get_mods();
// #ifndef NO_ACTION_ONESHOT
//         uint8_t shift_mods = (mods | get_oneshot_mods()) & MOD_MASK_SHIFT;
// #else
//         uint8_t shift_mods = mods & MOD_MASK_SHIFT;
// #endif  // NO_ACTION_ONESHOT
//         if (shift_mods) {  // At least one shift key is held.
//           registered_key = KC_DEL;
//           // If one shift is held, clear it from the mods. But if both
//           // shifts are held, leave as is to send Shift + Del.
//           if (shift_mods != MOD_MASK_SHIFT) {
// #ifndef NO_ACTION_ONESHOT
//             del_oneshot_mods(MOD_MASK_SHIFT);
// #endif  // NO_ACTION_ONESHOT
//             unregister_mods(MOD_MASK_SHIFT);
//           }
//         } else {
//           registered_key = KC_BSPC;
//         }

//         register_code(registered_key);
//         set_mods(mods);
//       } else {  // On key release.
//         unregister_code(registered_key);
//       }
//     } return false;


//   };

//   return true;
// }

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