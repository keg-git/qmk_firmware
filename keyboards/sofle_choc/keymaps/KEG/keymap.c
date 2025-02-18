/* Copyright 2023 Brian Low
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    // _COLEMAK,
    _NAV,
    _SYM,
    _GAME,
    _GAMEH,
    // _ADJUST,
    _NUM,
    // _SDOKU,
};

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    // KC_QWERTY,
    // KC_COLEMAK,
    KC_ALTAB,
    KC_CTLTAB,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ALT  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | '  " |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |SHIFT |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |ENTER |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI |  F4  | GAME |SPACE | / Bspc  /       \Space \  | NUM  | DEL  | F12  | F11  |
 *            |      |      |      |      |/ (NAV) /         \ (SYM)\ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  KC_LALT,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_EQL,
  KC_LCTL,  LGUI_T(KC_A),LALT_T(KC_S),LCTL_T(KC_D),LSFT_T(KC_F), KC_G,            KC_H,RSFT_T(KC_J),RCTL_T(KC_K),RALT_T(KC_L),  LGUI_T(KC_SCLN),  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MPLY,     KC_MUTE, KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                 KC_LGUI,KC_F4,TG(_GAME),KC_SPC, LT(_NAV,KC_BSPC),  LT(_SYM,KC_SPC), MO(_NUM), KC_DEL, KC_F12, KC_F11
),

/* Navigation
 * ,----------------------------------------.                     ,-----------------------------------------.
 * | CAD  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |  F11 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CSE  | C+A  | CTAB |  UP  | ATAB | CAPS |                    |Setti |NXWORD| WinUp|PVWORD|CTL W |  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Alt  | SHFT | LEFT | DOWN | RIGHT| HOME |-------.    ,-------| PAUP | WinL | WinD | WinR |SHIFT | ' "  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | CTRL | Undo |  Cut | Copy | Paste| END  |-------|    |-------| PADW | Prev |  F7  | Next |CSlash|ENTER |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | SYM   |SLEEP |SPACE | LOCK | / TRNS /       \ TAB  \  |CTRL  | CSHFT | Shift| LGUI |
 *            |      |      |      |      |/       /         \      \ | BSPC |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NAV] = LAYOUT(
        LCA(KC_DEL),         KC_F1,        KC_F2,    KC_F3,    KC_F4,        KC_F5,                                KC_F6,         KC_F7,    KC_F8,     KC_F9,        KC_F10,  KC_F11,
        KC_LALT,     LCTL(KC_LALT),     KC_PRVWD,    KC_UP, KC_NXTWD,      KC_CAPS,                           LGUI(KC_I),       KC_BTN1,  KC_MS_U,   KC_BTN2,    LCTL(KC_W),  KC_F12,
        KC_LCTL,           KC_LSFT,      KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_PAGE_UP,                              KC_BTN4,       KC_MS_L,  KC_MS_D,   KC_MS_R,       KC_LSFT, _______,
        KC_LSFT,     LCTL(KC_LALT),      KC_HOME,  KC_COPY,   KC_END, KC_PAGE_DOWN, _______,         _______,    KC_BTN5,       KC_MPRV,  KC_MPLY,   KC_MNXT, LCTL(KC_SLSH), _______,
                                        MO(_SYM),  KC_SLEP,  _______,   LGUI(KC_L), _______,          KC_TAB,   KC_DLINE, LCTL(KC_LSFT),  KC_LSFT,   KC_LGUI
        ),

/* Symbols
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   #  |   /  |   [  |   ]  |   +  |                    |   |  |   <  |   >  |   \  |   '  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Alt  |   @  |   *  |   (  |   )  |   =  |-------.    ,-------|   &  |   ;  |   .  |   ,  |   "  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | Ctrl |   $  |   %  |   {  |   }  |   -  |-------|    |-------|   ?  |   :  |   !  |   _  |   `  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \______\  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SYM] = LAYOUT(
        KC_GRV,KC_1,            KC_2,            KC_3,            KC_4,    KC_5,                             KC_6,            KC_7,              KC_8,          KC_9,    KC_0,    _______,
        KC_LALT,KC_HASH,         KC_SLSH,         KC_LBRC,         KC_RBRC, KC_PLUS,                          KC_PIPE,           KC_LT,           KC_GT,         KC_BSLS, KC_QUOT, KC_CIRC,
        KC_LCTL,  KC_AT,         KC_ASTR,         KC_LPRN,         KC_RPRN,  KC_EQL,                          KC_AMPR,         KC_SCLN,         KC_PDOT,         KC_COMM, KC_DQUO, KC_TILD,
        KC_LSFT, KC_DLR,         KC_PERC,         KC_LCBR,         KC_RCBR, KC_MINS,  _______,       _______, KC_QUES,         KC_COLN,         KC_EXLM,         KC_UNDS,  KC_GRV, _______,
                                 KC_MUTE,         _______,         KC_BSPC,  KC_SPC, MO(_NAV),       _______, KC_LSFT,           KC_F6,           KC_F7,           KC_F8
        ),

// Game Layers
// Base Game Layout great for destiny
[_GAME] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,     KC_3,    KC_4,   KC_5,                          KC_6,        KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
    KC_TAB,  KC_Q,   KC_W,     KC_E,    KC_R,   KC_T,                          KC_Y,     KC_U, KC_I, KC_O,    KC_P,  KC_EQL,
    KC_LCTL, KC_A,   KC_S,     KC_D,    KC_F,   KC_G,                          KC_H,     KC_J, KC_K, KC_L, KC_SCLN,  KC_QUOT,
    KC_LSFT, KC_Z,   KC_X,     KC_C,    KC_V,   KC_B, _______,     _______,    KC_N,        KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                     KC_M,   KC_O, MO(_GAMEH), KC_LALT, KC_SPC,    KC_SPC, TG(_GAME), LALT(KC_F4),  KC_F12,  KC_F11
),

[_GAMEH] = LAYOUT(
  KC_ESC,   KC_F1,   KC_F2,     KC_F3,    KC_F4,   KC_F5,                          KC_F6,        KC_F7,    KC_F8,    KC_F9,    KC_0,  KC_MINS,
    KC_TAB,  KC_CTLTAB,   KC_UP,     KC_ALTAB,    KC_R,   KC_T,                          KC_Y,     KC_BTN5, KC_MS_U, KC_BTN4,    KC_P,  KC_EQL,
    KC_LCTL, KC_LEFT,   KC_DOWN, KC_RGHT,    KC_J,   KC_G,                          KC_B,     KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2,  KC_QUOT,
    KC_LSFT, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, _______,     _______,    KC_N,        KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                     KC_M,   KC_O, _______, KC_LALT, KC_SPC,    TG(_GAME), KC_BTN1, LALT(KC_F4),  KC_F12,  KC_F11
),
/* ADJUST  not correct
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | BOOT | Spd+ | Val+ | Sat+ | Hue+ |Mode+ |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Spd- | Val- | Sat- | Hue- |Mode- |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |MacWin|      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
// [_ADJUST] = LAYOUT(
//     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_PWR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//     QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//     XXXXXXX, XXXXXXX, XXXXXXX, TG(_SDOKU), TG(_GAME), XXXXXXX,                     XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//     CG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//                       _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
// ),

[_NUM] = LAYOUT(
    XXXXXXX, KC_ACL0, KC_ACL1, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, KC_PLUS, KC_EQL, KC_MINS, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_BTN4, KC_MS_U, KC_BTN5, XXXXXXX,                       KC_BSPC, KC_7, KC_8, KC_9, KC_PSLS, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN3,                       KC_LPRN,KC_4, KC_5, KC_6, KC_ASTR, KC_BSPC,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_RPRN, KC_1, KC_2, KC_3, KC_0, KC_ENT,
                      _______, _______, _______, KC_BTN2, KC_BTN1,     _______, _______, KC_DOT, KC_0, KC_COMM
),

// [_SDOKU] = LAYOUT(
//     XXXXXXX, LSFT(KC_L), LSFT(KC_H), KC_MPLY, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//     XXXXXXX, KC_0,    KC_1,    KC_2,    KC_3,    KC_C,                          XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,
//     XXXXXXX, KC_LALT,    KC_4,    KC_5,    KC_6,    KC_Z,                       XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
//     KC_BSPC, KC_LCTL,    KC_7,    KC_8,    KC_9,    KC_V, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//                       _______,    KC_0, _______, KC_LALT, KC_LCTL,     TG(_SDOKU), _______, _______, _______, _______
// ),

};

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _NAV, _SYM, _ADJUST);
// }
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ALTAB:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                register_code(KC_TAB);
                unregister_code(KC_TAB);
            } else {
                unregister_mods(mod_config(MOD_LALT));
            }
            return false;
        case KC_CTLTAB:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_TAB);
                unregister_code(KC_TAB);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            return false;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            return false;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            return false;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            return false;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            return false;
        case KC_COPY:
            if (record->event.pressed) {
                // CMD-c on Mac, but we have CTL and GUI swapped
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                // CMD-v on Mac, but we have CTL and GUI swapped
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                // CMD-x on Mac, but we have CTL and GUI swapped
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            return false;
        case KC_UNDO:
            if (record->event.pressed) {
                // CMD-z on Mac, but we have CTL and GUI swapped
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
        default:
            return true;
    }
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] =   { ENCODER_CCW_CW(KC_MS_WH_RIGHT, KC_MS_WH_LEFT), ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP)  },
    [_GAME] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP)  },
    [_GAMEH] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP)  },
    [_SYM] =  { ENCODER_CCW_CW(LCTL(KC_PPLS), LCTL(KC_PMNS)),   ENCODER_CCW_CW(LCTL(KC_PPLS), LCTL(KC_PMNS))  },
    [_NAV] =  { ENCODER_CCW_CW(KC_VOLU, KC_VOLD),   ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
    // [_ADJUST] = { ENCODER_CCW_CW(KC_MS_WH_RIGHT, KC_MS_WH_LEFT), ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP) },
    [_NUM] =   { ENCODER_CCW_CW(KC_MS_WH_RIGHT, KC_MS_WH_LEFT), ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP)  },
    // [_SDOKU] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP)  },
};
#endif

#ifdef OLED_ENABLE


static void render_logo(void) {
    static const char qmk_logo [] PROGMEM = {
        // 'oledimage', 32x128px
        0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x03, 0x07, 0x1e, 0x3c, 0x78, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf1, 0x7b, 0x3f, 0x1f, 0x0e, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x38, 0x3c, 0x1e, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
        0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0x00, 0x80, 0xc0,
        0xc0, 0xe0, 0xf7, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0x7f, 0x3f,
        0x9f, 0xaf, 0x27, 0x03, 0x81, 0x81, 0x00, 0x00, 0x80, 0x80, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x0c,
        0x0f, 0x03, 0x00, 0x0c, 0x0f, 0x03, 0x01, 0x0f, 0x0f, 0x01, 0x09, 0x0f, 0x0f, 0x01, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xe0,
        0xe0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0xff, 0xff, 0xff, 0xff,
        0xfb, 0xff, 0x7f, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf8, 0x7c, 0x1f, 0x03, 0x00, 0x01, 0x01,
        0x01, 0x00, 0x00, 0x03, 0x0f, 0x7f, 0xff, 0xfc, 0xf8, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xc0, 0xc0, 0xe0, 0xf0, 0xff, 0xff, 0xf7, 0xe0, 0xe0, 0xc0, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1c, 0x1c, 0x1c,
        0x1c, 0x1c, 0x1e, 0x1e, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x0f, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(qmk_logo, sizeof(qmk_logo));

}

static void print_status_narrow(void) {
    oled_write_ln_P(PSTR("SofleChoc _____"), false);

    // if (get_highest_layer(layer_state) == _ADJUST) {
    //     uint8_t mode  = rgb_matrix_get_mode();
    //     HSV     hsv   = rgb_matrix_get_hsv();
    //     uint8_t speed = rgb_matrix_get_speed();

    //     if (keymap_config.swap_lctl_lgui) {
    //         oled_write_ln_P(PSTR("MAC\n"), false);
    //     } else {
    //         oled_write_ln_P(PSTR("WIN\n"), false);
    //     }

    //     oled_write_ln("RGB", false);
    //     write_int_ln(PSTR("Mo"), mode);
    //     write_int_ln(PSTR("H "), hsv.h);
    //     write_int_ln(PSTR("S "), hsv.s);
    //     write_int_ln(PSTR("V "), hsv.v);
    //     write_int_ln(PSTR("Sp"), speed);
    //     oled_write_P(PSTR("\n\n\n"), false);
    // } else {
        //oled_write_P(PSTR("\n\n\n\n\n\n\n\n\n"), false);
    //}
    //oled_write_P(PSTR("\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    if (led_usb_state.caps_lock) {
        oled_write_ln_P(PSTR(" CAP "), true);
    } else {
        oled_write_ln_P(PSTR("     "), false);
    }
    //oled_write_P(PSTR("\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);

    // Print current layer
    switch (get_highest_layer(layer_state)) {
        // case _COLEMAK:
        case _GAME:
            oled_write_ln_P(PSTR("Game "), false);
            break;
        case _GAMEH:
            oled_write_ln_P(PSTR("GHelp"), false);
            break;
        case _QWERTY:
            oled_write_ln_P(PSTR("Alpha"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("Nav  "), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Sym  "), false);
            break;
        // case _ADJUST:
        //     oled_write_ln_P(PSTR("Adj  "), false);
        //     break;
        case _NUM:
            oled_write_ln_P(PSTR("Num  "), false);
            break;
        // case _SDOKU:
        //     oled_write_ln_P(PSTR("SDoku"), false);
        // break;
        default:
            oled_write_P(PSTR("???  "), false);
    }
    oled_write_ln_P(PSTR("_____"), false);
    //oled_write_ln_P(PSTR("Layout"), false);
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrty"), false);
            break;
        // case _COLEMAK:
        //     oled_write_ln_P(PSTR("Clmk"), false);
        //     break;
        case _GAME:
            oled_write_ln_P(PSTR("Game"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
            }

    return false;
}

#endif
