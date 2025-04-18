#ifdef OLED_ANIM_DVD_LOGO
#include "dvd_logo.h"

#define DVD_LOGO_WIDTH 32
#define DVD_LOGO_HEIGHT 16

// clang-format off
static const uint8_t dvd_logo_data[] = {
0x00, 0xf0, 0xff, 0xff, 0xff, 0xc3, 0xc3, 0xe3, 0x67, 0x7f, 0x3f, 0x1f, 0x0f, 0x3f, 0xff, 0xf8,
0xf0, 0x78, 0x3c, 0x1f, 0xc7, 0xff, 0xff, 0xff, 0xcf, 0xc3, 0xc3, 0xe3, 0x7f, 0x7f, 0x3e, 0x1c,
0x00, 0x08, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x36, 0x37, 0x37,
0x36, 0x36, 0x36, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x08, 0x00
};
// clang-format on

static bool move_up;
static bool move_left;
static int16_t logo_x;
static int16_t logo_y;
static uint16_t logo_update_timer = 0;

void oled_init_dvd_logo(void) {
    random16_set_seed(timer_read());
    logo_x = random8_max(OLED_DISPLAY_WIDTH - DVD_LOGO_WIDTH);
    logo_y = random8_max(OLED_DISPLAY_HEIGHT - DVD_LOGO_HEIGHT);
    move_up = (random8() % 2 == 0);
    move_left = (random8() % 2 == 0);
}

void update_dvd_logo(void) {
    if (move_left) {
        logo_x -= DVD_LOGO_SPEED;
    } else {
        logo_x += DVD_LOGO_SPEED;
    }
    if (move_up) {
        logo_y -= DVD_LOGO_SPEED;
    } else {
        logo_y += DVD_LOGO_SPEED;
    }
    uint8_t collision_mask = rect_out_of_bounds(logo_x, logo_y, DVD_LOGO_WIDTH, DVD_LOGO_HEIGHT, 0);
    if ((collision_mask & COLLISION_MASK_UP || collision_mask & COLLISION_MASK_DOWN)) {
        move_up = !move_up;
    }
    if ((collision_mask & COLLISION_MASK_LEFT || collision_mask & COLLISION_MASK_RIGHT)) {
        move_left = !move_left;
    }
}

void render_dvd_logo(void) {
    if (timer_elapsed(logo_update_timer) >= UPDATE_DELAY) {
        oled_write_bitmap(dvd_logo_data, logo_x, logo_y, DVD_LOGO_WIDTH, DVD_LOGO_HEIGHT, true);
        update_dvd_logo();
        oled_write_bitmap(dvd_logo_data, logo_x, logo_y, DVD_LOGO_WIDTH, DVD_LOGO_HEIGHT, false);
        logo_update_timer = timer_read();
    }
}
#endif
