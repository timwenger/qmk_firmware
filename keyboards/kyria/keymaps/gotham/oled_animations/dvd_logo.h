#ifdef OLED_ANIM_DVD_LOGO
#pragma once
#include "common.h"

#define DVD_LOGO_SPEED 1
#define DVD_LOGO_FPS 45
#define UPDATE_DELAY (uint8_t)(1000.0 / DVD_LOGO_FPS)

void oled_init_dvd_logo(void);
void update_dvd_logo(void);
void render_dvd_logo(void);
#endif
