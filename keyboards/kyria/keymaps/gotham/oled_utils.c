#include "oled_utils.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    oled_sleep_timer = timer_read32();
#if defined(OLED_ANIMATIONS_ENABLED) && defined(OLED_ANIM_STARFIELD)
    oled_init_starfield();
#elif defined(OLED_ANIMATIONS_ENABLED) && defined(OLED_ANIM_DVD_LOGO)
    oled_init_dvd_logo();
#endif
    return OLED_ROTATION_180;
}

__attribute__((weak)) bool process_record_keymap_oled(uint16_t keycode, keyrecord_t *record) {
    oled_sleep_timer = timer_read32();
#if defined(OLED_ANIMATIONS_ENABLED) && defined(OLED_ANIM_STARFIELD)
    random16_add_entropy(keycode);
#endif
    return true;
}

void oled_task_user(void) {
    if (timer_elapsed(oled_sleep_timer) >= 30000) {
        oled_off();
#if defined(OLED_ANIMATIONS_ENABLED) && defined(OLED_ANIM_STARFIELD_WANDER)
        erase_stars();
        set_starfield_center();
#endif
        return;
    } else {
        render_status();
    }
}

void render_layer(void) {
    oled_write_P(PSTR("\nLayer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("???\n"), false);
    }
}

#ifdef ENCODER_ENABLE
void render_encoder(encoder_mode_t mode) {
    switch (mode) {
        case ENC_MODE_VOLUME:
            oled_write_P(PSTR("Volume\n"), false);
            break;
        case ENC_MODE_WORD_NAV:
            oled_write_P(PSTR("Word Nav\n"), false);
            break;
        case ENC_MODE_LEFT_RIGHT:
            oled_write_P(PSTR("Left / Right\n"), false);
            break;
        case ENC_MODE_UP_DOWN:
            oled_write_P(PSTR("Up / Down\n"), false);
            break;
        case ENC_MODE_PAGING:
            oled_write_P(PSTR("PgUp / PgDwn\n"), false);
            break;
        default:
            oled_write_P(PSTR("???\n"), false);
    }
}
#endif

#ifdef THUMBSTICK_ENABLE
void render_thumbstick(thumbstick_mode_t mode) {
    switch (mode) {
        case THUMBSTICK_MODE_MOUSE:
            oled_write_P(PSTR("Mouse"), false);
            break;
        case THUMBSTICK_MODE_ARROWS:
            oled_write_P(PSTR("Arrows"), false);
            break;
        case THUMBSTICK_MODE_SCROLL:
            oled_write_P(PSTR("Scroll"), false);
            break;
        default:
            oled_write_P(PSTR("???\n"), false);
    }
}
#endif

void render_status(void) {
    if (!is_keyboard_master()) {
        // Host Keyboard Layer Status
        render_layer();
#ifdef ENCODER_ENABLE
        // Encoder state
        oled_write_P(PSTR("L-Enc: "), false);
        render_encoder(encoder_left_mode);
        oled_write_P(PSTR("R-Enc: "), false);
        render_encoder(encoder_right_mode);
#endif
#ifdef THUMBSTICK_ENABLE
        // Thumbstick state
        oled_write_P(PSTR("Joystick: "), false);
        render_thumbstick(thumbstick_state.config.mode);
#endif
        // Host Keyboard LED Status
        led_t led_state = host_keyboard_led_state();
        oled_write_P(led_state.num_lock ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_state.caps_lock ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
#ifndef OLED_ANIMATIONS_ENABLE
        oled_write_P(PSTR("\n\n\n      Kyria v1.0\n"), false);
#else
#    if defined(OLED_ANIM_STARFIELD)
        render_starfield();
#    elif defined(OLED_ANIM_DVD_LOGO)
        render_dvd_logo();
#    endif
#endif
    }
}
