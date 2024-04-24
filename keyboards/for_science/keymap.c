/* Copyright 2017 Paul James (paul@peej.co.uk)
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

#include "features/custom_shift_keys.h"

enum layers {
    HD_RHODIUM,
    LAYER, // for now keeping the original from peej; got no better name for it atm
    _MOD_LAYER,
    _FUNCT
};

// custom shifts here | https://getreuer.info/posts/keyboards/custom-shift-keys/index.html
const custom_shift_key_t custom_shift_keys[] = {
  {KC_HASH , KC_AT}, // Shift # is @
  {KC_DOT, KC_COLN}, // Shift . is :
  {KC_SLSH, KC_ASTR }, // Shift / is *
  {KC_COMM, KC_SCLN}, // Shift , is ; 
  {KC_MINS, KC_PLUS}, // Shift - is + 
};
// ! and ? are missing so far (in Rhodium on j and x)
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);
// end oƒ custom shifts

// Custom keycodes, mainly for Home Row Mods (HRM)
//Control
#define CTL_C LCTL(KC_C)
#define CTL_M RCTL(KC_M)
//Alt / Option
#define ALT_S LALT(KC_S)
#define ALT_I RALT(KC_I)
//Gui / Command
#define GUI_N LGUI(KC_N)
#define GUI_E RGUI(KC_E)
//Shift
#define SHFT_T LSFT_T(KC_T)
#define SHFT_A RSFT_T(KC_A)

// other custom codes
#define LAY_SPC LT(LAYER, KC_SPACE)
// end of custom keycodes
    
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
*	Rhodium keymap according to https://sites.google.com/alanreiser.com/handsdown/home/hands-down-neu
*	'z bq  h  g  "   #@ .: /* j! x?  
*	c  s  n  t  k   ,; a  e  i  m  
*	p  f  l  d  v   -+ u  o  y  w  
*				r   ␣  
*/

/*
 * ,----------------------------------------   ----------------------------------------.
 * |  Tab  |  Esc  |   (   |   {   |   [   |   |   ]   |   }   |   )   |   '   | BkSp  |
 * |   ~   |   `   |   <   |   _   |   -   |   |   +   |   =   |   >   |   \   |  Del  |
 * |-------+-------+-------+-------+-------+   |-------+-------+-------+-------+-------|
 * |   Q   |   W   |   E   |   R   |   T   |   |   Y   |   U   |   I   |   O   |   P   |
 * |   1   |   2   |   3   |   4   |   5   |   |   6   |   7   |   8   |   9   |   0   |
 * |-------+-------+-------+-------+-------+   |-------+-------+-------+-------+-------|
 * |   A   |   S   |   D   |   F   |   G   |   |   H   |   J   |   K   |   L   | Enter |
 * |  F1   |  F2      F3   |  F4   |  F5   |   | PgUp  | Home  |  Up   |  End  |   ;   |
 * |-Shift-+-------+-------+-------+-------+   |-------+-------+-------+-------+-------|
 * |   Z   |   X   |   C   |   V   |   B   |   |   N   |   M   |   ,   |   .   |   /   |
 * |  F6   |  F7   |  F8   |  F9   |  F10  |   | PgDn  | Left  | Down  | Right |       |
 * `-Shift---Layer-+-------+-------+-------+   |-------+-------+-------+---------Layer-'
 *                 | Ctrl  |  Gui  |  Alt  |   | Space | Layer | Shift |
 *                 |       |       |       |   | Funct |       |       |
 *                 `------------------------   `-Layer-----------------'
 */

// For home row mods (HRM) I use CAGS (Ctrl - Alt/Option - Gui/Command - Shift)
[HD_RHODIUM] = LAYOUT_split_4x5_3(
    KC_NO,   KC_ESC,    KC_NO,   KC_NO,   KC_NO,      KC_NO, 	KC_NO, 	   KC_NO, 	KC_NO,   KC_BSPC,
    KC_QUOT, KC_B,    KC_H,    KC_G,    KC_DQUO,    KC_HASH,    KC_DOT,    KC_SLSH,     KC_J,    KC_X,
    CTL_C,   ALT_S,   GUI_N,   SHFT_T,  KC_K,       KC_COMM,    SHFT_A,    GUI_E,    	ALT_I,   CTL_M,
    KC_P,    KC_F,    KC_L,    KC_D,    KC_V,       KC_MINS,    KC_U,      KC_O, 	KC_Y,    KC_W,
                      KC_LCTL, KC_R,    KC_ENT,     LAY_SPC,    LAY_SPC,   KC_RSFT
),

[LAYER] = LAYOUT_split_4x5_3(
    KC_TILD, KC_GRV,  KC_LABK, KC_UNDS, KC_MINS,    KC_PLUS, KC_EQL,  KC_RABK, KC_BSLS, KC_DEL,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    SFT_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_SCLN,
    SFT_F6,  LAY_F7,  KC_F8,   KC_F9,   KC_F10,     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______,
                      _______, _______, _______,    FUNCT,   _______, _______
),

[_MOD_LAYER] = LAYOUT_split_4x5_3(
    KC_TILD, _______, _______, _______, _______,    KC_Q,    _______, _______, _______, _______,
    KC_TAB,  _______, _______, _______, _______,    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
                      _______, _______, _______,    _______, _______, _______
),

[_FUNCT] = LAYOUT_split_4x5_3(
    QK_BOOT,   _______, _______, _______, LOCK,       MAC_LCK, _______, _______, _______, MAGIC_SWAP_LALT_LGUI,
    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
                      _______, _______, _______,    _______, _______, _______
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (get_mods() & MOD_MASK_CAG) {
        if (record->event.pressed) {
            layer_on(_MOD_LAYER);
        } else {
            layer_off(_MOD_LAYER);
        }
    }

    if (record->event.pressed) {
        if (keycode == KC_BSPC && (get_mods() & MOD_MASK_ALT)) {
            tap_code(KC_DEL);
            return false;
        }
    }

    return true;
};
