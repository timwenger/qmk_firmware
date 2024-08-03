

This one is made for a gherkin, which has quite some extra pins. If you need anything else please let me know

#include "kb.h"
#include "champ40j.h"
#include "analog.c"
#include "math.h"
#include "pincontrol.h"
#include "pointing_device.h"
#include "print.h"
#include "report.h"
#include "timer.h"
// Joystick
// Set Pins
int xPin = B1; // VRx
int yPin = F7; // VRy
// Set Parameters
int minAxisValue = 0;
int maxAxisValue = 1023;
int maxCursorSpeed = 4;
int precisionSpeed = 1;
int speedRegulator = 20; // Lower Values Create Faster Movement
int xPolarity = 1;
int yPolarity = -1;
int cursorTimeout = 10;
int xOrigin, yOrigin;
uint16_t lastCursor = 0;

int axisCoordinate(int pin, int origin) {
    int direction;
    int distanceFromOrigin;
    int range;
    int position = analogRead(pin);
    if (origin == position) {
        return 0;
    } else if (origin > position) {
        distanceFromOrigin = origin - position;
        range = origin - minAxisValue;
        direction = -1;
    } else {
        distanceFromOrigin = position - origin;
        range = maxAxisValue - origin;
        direction = 1;
    }
    float percent = (float)distanceFromOrigin / range;
    int coordinate = (int)(percent * 100);
    if (coordinate < 0) {
        return 0;
    }
    else if (coordinate > 100) {
        return 100 * direction;
    }
    else {
        return coordinate * direction;
    }
}

int axisToMouseComponent(int pin, int origin, int maxSpeed, int polarity) {
    int coordinate = axisCoordinate(pin, origin);
    if (coordinate == 0) {
    return 0;
    }
    else {
    float percent = (float)coordinate / 100;
    if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
    return percent * precisionSpeed * polarity * (abs(coordinate)/speedRegulator);
    }
    else {
    return percent * maxCursorSpeed * polarity * (abs(coordinate)/speedRegulator);
    }
    }
}

void pointing_device_task(void) {
    report_mouse_t report;
    report.x = 0;
    report.y = 0;
    report.h = 0;
    report.v = 0;
    report.buttons = 0;
    // todo read as one vector
    if (timer_elapsed(lastCursor) > cursorTimeout) {
    lastCursor = timer_read();
    report.x = axisToMouseComponent(xPin, xOrigin, maxCursorSpeed, xPolarity);
    report.y = axisToMouseComponent(yPin, yOrigin, maxCursorSpeed, yPolarity);
    }
    void matrix_init_kb(void) {
    timer_init();
    xOrigin = analogRead(xPin);
    yOrigin = analogRead(yPin);
    }
}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_BSLS, TO(0), KC_SPC, KC_SPC, TO(1), KC_LEFT, KC_RGHT, KC_UP, KC_DOWN),
    KEYMAP(
    KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
    KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_LBRC, KC_VOLD, KC_MPLY, KC_VOLU, KC_TRNS,
    KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_RBRC, KC_MPRV, KC_MSTP, KC_MNXT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0), KC_TRNS, KC_TRNS, TO(1), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    KEYMAP(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    keyevent_t event = record->event;
    switch (id) {
    }
    return MACRO_NONE;
}
void matrix_init_user(void) {
}
void matrix_scan_user(void) {
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
return true;
}
void led_set_user(uint8_t usb_led) {
if (usb_led & (1 << USB_LED_NUM_LOCK)) {

} else {  
	  
}  
if (usb\_led & (1 << USB\_LED\_CAPS\_LOCK)) {  
	  
} else {  
	  
}  
if (usb\_led & (1 << USB\_LED\_SCROLL\_LOCK)) {  
	  
} else {  
	  
}  
if (usb\_led & (1 << USB\_LED\_COMPOSE)) {  
	  
} else {  
	  
}  
if (usb\_led & (1 << USB\_LED\_KANA)) {  
	  
} else {  
	  
}  

}
