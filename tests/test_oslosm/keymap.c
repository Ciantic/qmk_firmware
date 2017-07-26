/* Copyright 2017 Fred Sundvik
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

#include "quantum.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = {
        // 0    1      2      3        4        5        6       7            8      9
        {OSL(1),OSL(2),KC_C, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,       KC_NO, KC_NO},
        {KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,       KC_NO, KC_NO},
        {KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,       KC_NO, KC_NO},
        {KC_NO,  KC_NO,  KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,       KC_NO, KC_NO},
    },
    [1] = {
        // 0      1        2      3        4        5        6       7            8      9
        {KC_TRNS, KC_TRNS, KC_A,  KC_B,   KC_NO,   KC_NO,   KC_NO,  KC_NO,       KC_NO, KC_NO},
        {KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,       KC_NO, KC_NO},
        {KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,       KC_NO, KC_NO},
        {KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,       KC_NO, KC_NO},
    },
    [2] = {
        // 0      1        2      3        4        5        6       7            8      9
        {KC_TRNS, KC_TRNS, KC_D,  KC_E,   KC_NO,   KC_NO,   KC_NO,  KC_NO,       KC_NO, KC_NO},
        {KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,       KC_NO, KC_NO},
        {KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,       KC_NO, KC_NO},
        {KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,       KC_NO, KC_NO},
    }
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    return MACRO_NONE;
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
}