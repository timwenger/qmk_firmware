// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

# include QMK_KEYBOARD_H
# include "layers.h"
# include "print.h"
# include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     * +-----------------------------------------+                             +-----------------------------------------+
     * | mute |   q  |   w  |   f  |   p  |   g  |                             |   j  |   l  |   u  |   y  | esc  |vol up|
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | TAB  |   a  |   r  |   s  |   t  |   d  |                             |   h  |   n  |   e  |   i  |   o  | enter|
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | pause|   z  |   x  |   c  |   v  |   b  |                             |   k  |   m  |   ,  |   .  |   ?  |vol dn|
     * +------+------+------+------+------+------+                             +------+------+------+------+------+------+
     *               |  alt | TAB  |sh/bpc|                                           |sh/spc|  N/A |  N/A |
     *               +------+-------------+------+                             +------+------+------+------+
     *                             |  alt | ctr  |                             | ctr  |  alt |
     *                             +------+------+                             +------+------+

     */
    [HOME] = LAYOUT(
        KC_AUDIO_MUTE,  KC_Q,           KC_W,     KC_F,     KC_P,             KC_G,             KC_J,      KC_L,            KC_U,    KC_Y,    KC_ESC,          KC_AUDIO_VOL_UP,
        KC_TAB,         LT(NUM, KC_A),  KC_R,     KC_S,     KC_T,             KC_D,             KC_H,      KC_N,            KC_E,    KC_I,    LT(AROW, KC_O),  KC_RCTL,
        KC_MPLY,        LT(AROW, KC_Z), KC_X,     KC_C,     KC_V,             KC_B,             KC_K,      KC_M,            KC_COMM, KC_DOT,  KC_QUES,         KC_AUDIO_VOL_DOWN,
                                        KC_LALT,  KC_TAB,   LSFT_T(KC_BSPC),                               RSFT_T(KC_SPC),  KC_NO,   KC_NO,
                                                            KC_LALT,          KC_LCTL,          KC_RCTL,   KC_RALT
    ),
    [LH_NUM] = LAYOUT(
        LCTL(KC_Y),     KC_NO,          KC_7,     KC_8,     KC_9,             KC_EQL,           KC_TRNS,   KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,
        KC_TAB,         LT(AROW, KC_0), KC_4,     KC_5,     KC_6,             KC_MINS,          KC_TRNS,   KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,
        LCTL(KC_Z),     KC_ENTER,       KC_1,     KC_2,     KC_3,             KC_SLSH,          KC_TRNS,   KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,
                                        KC_COMM,  KC_DOT,   LSFT_T(KC_SPC),                                KC_TRNS,         KC_TRNS, KC_TRNS,
                                                            KC_LALT,          KC_LCTL,          KC_TRNS,   KC_TRNS
    ),
    [AROW] = LAYOUT(
        KC_NO,          KC_NO, QK_MOUSE_BUTTON_2, KC_UP,   QK_MOUSE_BUTTON_1, KC_NO,            KC_F12,    KC_F7,            KC_F8,   KC_F9,   KC_NO,           KC_NO,
        KC_NO,          KC_HOME,        KC_LEFT,  KC_DOWN,  KC_RGHT,          KC_END,           KC_F11,    KC_F4,            KC_F5,   KC_F6,   KC_TRNS,         KC_NO,
        KC_NO,          LCTL(KC_Z),   LCTL(KC_X), LCTL(KC_C), LCTL(KC_V),     KC_NO,            KC_F10,    KC_F1,            KC_F2,   KC_F3,   KC_NO,           KC_NO,
                                        KC_LALT,  KC_TAB,   LSFT_T(KC_BSPC),                               RSFT_T(KC_ENTER), KC_NO,  KC_NO,
                                                            KC_LALT,          KC_LCTL,          KC_RCTL,   KC_RALT
    ),
    [NUM] = LAYOUT(
        KC_NO,          KC_NO, QK_MOUSE_BUTTON_2, KC_NO,   QK_MOUSE_BUTTON_1, KC_NO,            KC_EQL,    KC_7,             KC_8,   KC_9,   KC_NO,           KC_NO,
        KC_NO,          KC_TRNS,        KC_PIPE,  KC_BSLS,  KC_SLSH,          KC_MINS,          KC_PPLS,   KC_4,             KC_5,   KC_6,   KC_0,            KC_NO,
        KC_NO,          KC_NO,          KC_NO,    KC_NO,    KC_NO,            KC_NO,            KC_NO,     KC_1,             KC_2,   KC_3,   KC_NO,           KC_NO,
                                        KC_LALT,  KC_TAB,   LSFT_T(KC_DEL),                                RSFT_T(KC_SPC),   KC_COMM, KC_DOT,
                                                            KC_LALT,          KC_LCTL,          KC_RCTL,   KC_RALT
    )
};

// const key_override_t shift_backspace_delete = ko_make_basic(MOD_MASK_SHIFT, LSFT_T(KC_BSPC), KC_DEL);
// const key_override_t shift_space_enter = ko_make_basic(MOD_MASK_SHIFT, RSFT_T(KC_SPC), KC_ENTER);
const key_override_t exclamation_mark = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_EXCLAIM);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	// &shift_backspace_delete,
  // &shift_space_enter,
  &exclamation_mark
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(NUM, KC_A):
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}

// https://docs.qmk.fm/tap_hold#permissive-hold
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(NUM, KC_A):
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

bool left_side_scroll = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(AROW, KC_0):
            if(record->event.pressed){
                left_side_scroll = true;
            }
            else {
                left_side_scroll = false;
            }
            return true;
        default:
            return true;
    }
    return true;
}

// The higher the thresholds are, the longer it takes to accumulate to scroll to the next line jump
int vertical_scroll_sum = 0;
int vertical_scroll_threshold = 60;
int horizontal_scroll_sum = 0;
int horizontal_scroll_threshold = 80;
report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    if (left_side_scroll){
        right_report.x = left_report.x;
        right_report.y = left_report.y;
        left_report.x = 0;
        left_report.y = 0;
    }
    
    vertical_scroll_sum += right_report.y;
    if (vertical_scroll_sum > vertical_scroll_threshold) {
        left_report.v = -1;
        vertical_scroll_sum = 0;
    } else if (vertical_scroll_sum < (vertical_scroll_threshold * -1)) {
        left_report.v = 1;
        vertical_scroll_sum = 0;
    }

    horizontal_scroll_sum += right_report.x;
    if (horizontal_scroll_sum > horizontal_scroll_threshold){
        left_report.h = 1;
        horizontal_scroll_sum = 0;
    } else if (horizontal_scroll_sum < (horizontal_scroll_threshold * -1)){
        left_report.h = -1;
        horizontal_scroll_sum = 0;
    }

    return left_report;
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