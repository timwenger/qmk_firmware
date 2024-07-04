#pragma once

#include "keycodes.h"

#ifdef ENCODER_ENABLE
#    include "encoder_utils.h"
#endif

#ifdef THUMBSTICK_ENABLE
#    include "thumbstick.h"
#endif

#if defined(OLED_ANIMATIONS_ENABLE)
#    if defined(OLED_ANIM_DVD_LOGO)
#        include "oled_animations/dvd_logo.h"
#    elif defined(OLED_ANIM_STARFIELD)
#        include "oled_animations/starfield.h"
#    endif
#endif

uint32_t oled_sleep_timer;

bool process_record_keymap_oled(uint16_t keycode, keyrecord_t *record);

void render_kyria_logo(void);

void render_layer(void);

#ifdef ENCODER_ENABLE
void render_encoder(encoder_mode_t mode);
#endif

#ifdef THUMBSTICK_ENABLE
void render_thumbstick(thumbstick_mode_t mode);
#endif

void render_status(void);
