// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

# include QMK_KEYBOARD_H
# include "print.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     * +-----------------------------------------+                             +-----------------------------------------+
     * | ESC  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |      |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | TAB  |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |      |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | SHFT |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |      |
     * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
     *               |  [   |   ]  | a    |                                           | 5    |  +   |  =   |
     *               +-------------+-------------+                             +-------------+-------------+
     *                             |  b   |   c  |                             |  3   |  4   |
     *                             |------+------|                             |------+------|

     */
    [0] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                          KC_LBRC, KC_RBRC, KC_A,                                 KC_P5,   KC_PLUS, KC_EQL,
                                            KC_B,   KC_C,                KC_P3,   KC_P4
    )
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  // debug_matrix=true;
  //debug_keyboard=true;
  debug_mouse=true;
}


int count = 0;
report_mouse_t pointing_device_task_user(report_mouse_t left_report) {

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

  int16_t X = analogReadPin(ANALOG_JOYSTICK_X_AXIS_PIN);
  int16_t Y = analogReadPin(ANALOG_JOYSTICK_Y_AXIS_PIN);

  uprintf("x: %5d y: %5d X: %5d Y: %5d\n", left_report.x, left_report.y, X, Y);
  return left_report;
}