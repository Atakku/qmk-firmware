/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

enum layers{
    BASE_MAC,
    BASE_WIN,
    L_MOD,
    L_RGB,
};

#define KC_MOD MO(L_MOD)
#define KC_RGB MO(L_RGB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE_MAC] = LAYOUT_ansi_67(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX,          XXXXXXX,
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX),

    [BASE_WIN] = LAYOUT_ansi_67(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,    KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,   KC_BSLS,          KC_HOME,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,             KC_ENT,           KC_DEL,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,             KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGB,   KC_MOD,    KC_LEFT, KC_DOWN, KC_RGHT),

    [L_MOD] = LAYOUT_ansi_67(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,    _______,          KC_MPLY,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   _______,          KC_PGUP,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______,          KC_PGDN,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______,
        _______, _______, _______,                            _______,                            _______, _______,  _______,   _______, _______, _______),

    [L_RGB] = LAYOUT_ansi_67(
        RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,          RGB_TOG,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX,          XXXXXXX,
        KC_LSFT,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE_MAC] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) }, // Do nothing
    [BASE_WIN] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }, // Volume down & Volume up
    [L_MOD]    = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) }, // Prev track & Next track
    [L_RGB]    = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) }, // RGB hue left & RGB hue right
};
#endif
