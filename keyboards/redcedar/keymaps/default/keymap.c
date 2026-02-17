// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

# include QMK_KEYBOARD_H
# include "layers.h"
# include "print.h"
# include "g/keymap_combo.h"

// Use a * to disable chordal hold on a key.
// For more control, use the the get_chordal_hold() function below.
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R', 'R', 
        '*', 'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R', '*', 
        'L', '*', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R', 'R', /*the 2nd column on this row is indeed a * to disable chordal hold on Lower left pinky so that 1 handed copy paste can happen*/
                  'L', 'L', '*',               '*', 'R', 'R',
                            '*', '*',     '*', '*'
    );

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
        KC_AUDIO_MUTE,  KC_Q,           KC_W,               KC_F,            KC_P,              KC_G,             KC_J,      KC_L,            KC_U,           KC_Y,            KC_ESC,          KC_AUDIO_VOL_UP,
        KC_LSFT,      LT(L_PKY, KC_A),  KC_R,               LALT_T(KC_S),    LCTL_T(KC_T),      KC_D,             KC_H,      RCTL_T(KC_N),    RALT_T(KC_E),   LT(R_IDX, KC_I), LT(R_PKY, KC_O), KC_LSFT,
        KC_MPLY,      LT(L_LPKY, KC_Z), KC_X,               KC_C,            KC_V,              KC_B,             KC_K,      KC_M,            KC_COMM,        KC_DOT,          KC_QUES,         KC_AUDIO_VOL_DOWN,
                                        KC_LALT,            KC_TAB,          KC_BSPC,                                        KC_SPC,          KC_NO,          KC_NO,
                                                                             KC_TAB,            KC_LCTL,          KC_RCTL,   KC_RALT
    ),
    [LH] = LAYOUT( /*pressing any key on the right side toggles this left-hand only layer off again.*/
        KC_TRNS,        KC_NO,          KC_7,               KC_8,            KC_9,              KC_EQL,           TG(LH),    TG(LH),          TG(LH),         TG(LH),          TG(LH),          TG(LH),
        KC_TRNS,       LT(L_PKY, KC_0), KC_4,               LALT_T(KC_5),    LCTL_T(KC_6),      KC_SPC,           TG(LH),    TG(LH),          TG(LH),         TG(LH),          TG(LH),          TG(LH),
        KC_TRNS, LT(L_LPKY,LCTL(KC_Z)), KC_1,               KC_2,            KC_3,              KC_ENTER,         TG(LH),    TG(LH),          TG(LH),         TG(LH),          TG(LH),          TG(LH),
                                        KC_COMM,            KC_DOT,          KC_BSPC,                                        TG(LH),          TG(LH),         TG(LH),
                                                                             KC_TRNS,           KC_TRNS,          TG(LH),    TG(LH)
    ),
    [R_PKY] = LAYOUT(
        KC_TRNS,        KC_NO,          QK_MOUSE_BUTTON_2,  KC_UP,           QK_MOUSE_BUTTON_1, KC_NO,            KC_F12,    KC_F7,            KC_F8,         KC_F9,           KC_NO,           KC_TRNS,
        KC_TRNS,        KC_HOME,        KC_LEFT,            KC_DOWN,         KC_RGHT,           KC_END,           KC_F11,    RCTL_T(KC_F4),    RALT_T(KC_F5), KC_F6,           KC_NO,           KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,            KC_TRNS,         KC_TRNS,           KC_TRNS,          KC_F10,    KC_F1,            KC_F2,         KC_F3,           KC_NO,           KC_TRNS,
                                        KC_LALT,            KC_TAB,          KC_LSFT,                                        KC_RSFT,          KC_NO,         KC_NO,
                                                                             KC_TRNS,           KC_TRNS,          KC_TRNS,   KC_TRNS
    ),
    [L_LPKY] = LAYOUT(
        KC_TRNS,        KC_NO,          QK_MOUSE_BUTTON_2,  KC_UP,           QK_MOUSE_BUTTON_1, KC_NO,            KC_F12,    KC_F7,            KC_F8,         KC_F9,           KC_NO,           KC_TRNS,
        KC_TRNS,        KC_HOME,        KC_LEFT,            KC_DOWN,         KC_RGHT,           KC_END,           KC_F11,    RCTL_T(KC_F4),    RALT_T(KC_F5), KC_F6,           KC_NO,           KC_TRNS,
        KC_TRNS,        LCTL(KC_Z),     LCTL(KC_X),         LCTL(KC_C),      LCTL(KC_V),        KC_ENTER,         KC_F10,    KC_F1,            KC_F2,         KC_F3,           KC_NO,           KC_TRNS,
                                        KC_LALT,            KC_TAB,          KC_DEL,                                         KC_RSFT,          KC_NO,         KC_NO,
                                                                             KC_TRNS,           KC_TRNS,          KC_TRNS,   KC_TRNS
    ),
    [L_PKY] = LAYOUT(
        KC_TRNS,        KC_NO,          KC_TRNS,            KC_TRNS,         KC_TRNS,           KC_TRNS,          KC_EQL,    KC_7,             KC_8,          KC_9,            KC_NO,           KC_TRNS,
        KC_TRNS,        KC_NO,          KC_TRNS,            KC_TRNS,         KC_TRNS,           KC_TRNS,          KC_PPLS,   RCTL_T(KC_4),     RALT_T(KC_5),  KC_6,            KC_0,            KC_TRNS,
        KC_TRNS,        KC_NO,          KC_TRNS,            KC_TRNS,         KC_TRNS,           KC_TRNS,          KC_NO,     KC_1,             KC_2,          KC_3,            KC_NO,           KC_TRNS,
                                        KC_TRNS,            KC_TRNS,         KC_LSFT,                                        KC_RSFT,          KC_COMM,       KC_DOT,
                                                                             KC_TRNS,           KC_TRNS,          KC_TRNS,   KC_TRNS
    ),
    [R_IDX] = LAYOUT( /* for slashes*/
        KC_TRNS,        KC_TRNS,        KC_TRNS,            KC_TRNS,         KC_TRNS,           KC_TRNS,          KC_TRNS,   KC_TRNS,          KC_TRNS,       KC_TRNS,         KC_TRNS,         KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_BSLS,            KC_SLSH,         KC_MINS,           KC_TRNS,          KC_TRNS,   KC_TRNS,          KC_TRNS,       KC_TRNS,         KC_TRNS,         KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,            KC_TRNS,         KC_TRNS,           KC_TRNS,          KC_TRNS,   KC_TRNS,          KC_TRNS,       KC_TRNS,         KC_TRNS,         KC_TRNS,
                                        KC_TRNS,            KC_TRNS,         KC_LSFT,                                        KC_RSFT,          KC_TRNS,       KC_TRNS,
                                                                             KC_TRNS,           KC_TRNS,          KC_TRNS,   KC_TRNS
    )
};

// const key_override_t shift_space_enter = ko_make_basic(MOD_MASK_SHIFT, RSFT_T(KC_SPC), KC_ENTER);
const key_override_t shift_backspace_delete = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t exclamation_mark = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_EXCLAIM);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
  &shift_backspace_delete,
  // &shift_space_enter,
  &exclamation_mark
};



/////////////////////////////////////////////////////
// Hold and tap control                            //
/////////////////////////////////////////////////////




// explicitly return true when you want tap_hold_keycodes to hold on opposite hand key taps.
// or explicitly return false when you want to allow a specific same-handed shortcut (chord) 
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
    uint16_t other_keycode, keyrecord_t* other_record) {

    // // problem: Apparently I roll the index fingers. Therefore, any combination that's commonly at the beginning of typing (and at the beginning of a word) is 
    // // a good candidate to remove from here. If I really want that combo, I'll need to hold >500ms.
    
    // switch (tap_hold_keycode) {
    //     case LCTL_T(KC_T):
    //         if (other_keycode == KC_H) { // T+H, common in 'the' / 'there', etc
    //             return false;
    //         }
    //         break;
    //     case LALT_T(KC_S):
    //         if (other_keycode == KC_O || // S+O (in some) 
    //             other_keycode == KC_H) { // S+H (in shift)
    //             return false;
    //         }
    //         break;
    // }
    // Otherwise defer to the opposite hands rule.
    return get_chordal_hold_default(tap_hold_record, other_record);
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  // Enable the apostrophe combo during regular typing.
    if (combo_index == QUOTES) {
        return true;
    }
  // Disable the combo if it's pressed within the Flow Tap term.
  return !within_flow_tap_term(keycode, record);
}

// https://docs.qmk.fm/tap_hold#is-flow-tap-key
// called by get_flow_tap_term for both the tap/hold key and the previous key.
// Implementation is default
bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        case KC_SPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}

// https://docs.qmk.fm/tap_hold#get-flow-tap-term
// Return a time of 0 to disable flow tap. In this way, Flow Tap may be disabled for certain tap-hold keys, or when following certain previous keys.
// Implementation is default (only explicitly defined here for clarity and ease of future modification)
uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record,
                           uint16_t prev_keycode) {
    if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
        return FLOW_TAP_TERM;
    }
    return 0;
}






/////////////////////////////////////////////////////
// Joystick mouse movement and scrolling           //
/////////////////////////////////////////////////////





bool left_side_scroll = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(R_PKY, KC_0):
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