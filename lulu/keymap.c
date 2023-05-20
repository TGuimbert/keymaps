// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum/keymap_extras/keymap_bepo.h"
#include QMK_KEYBOARD_H

#define IGNORE_MOD_TAP_INTERRUPT

enum layers {
    _QWERTY,
    _RAISE,
    _LOWER,
    _ADJUST
};

#define RAISE MO(_RAISE)
#define LOWER TG(_LOWER)

#define TG_O MT(MOD_LALT, BP_O)
#define TG_U MT(MOD_LGUI, BP_U)
#define TG_A MT(MOD_LCTL, BP_A)
#define TG_I MT(MOD_LSFT, BP_I)
#define TG_T MT(MOD_RSFT, BP_T)
#define TG_S MT(MOD_RCTL, BP_S)
#define TG_N MT(MOD_RGUI, BP_N)
#define TG_R MT(MOD_LALT, BP_R)
#define TG_Q MT(MOD_RALT, BP_Q)
#define TG_C MT(MOD_RALT, BP_C)
#define TG_COMM LT(_LOWER, BP_COMM)
#define TG_QUOT LT(_LOWER, BP_QUOT)
#define TG_E LT(_RAISE, BP_E)


#define TG_LDAQ MT(MOD_LALT, BP_LDAQ)
#define TG_LEFT MT(MOD_LGUI, KC_LEFT)
#define TG_DOWN MT(MOD_LCTL, KC_DOWN)
#define TG_RGHT MT(MOD_LSFT, KC_RGHT)
#define TG_P4 MT(MOD_RSFT, KC_P4)
#define TG_P5 MT(MOD_RCTL, KC_P5)
#define TG_P6 MT(MOD_RGUI, KC_P6)
#define TG_SLSH MT(MOD_LALT, BP_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 
/* FR-GODOX
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   $  |   &  |   (  |   )  |      |                    |      |   @  |   "  |   =  |   %  |SCREEN|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   À  |   B  |   É  |   .  |   -  |                    |   ^  |   V  |   L  |   M  |   X  |  Ç   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   O  |   U  |   A  |   I  |   J  |-------.    ,-------|   G  |   T  |   S  |   N  |   R  |  F   |
 * |------+------+------+------+------+------|Play/|||    |  BOOT |------+------+------+------+------+------|
 * |LOWER |   Q  |   Y  |   È  |   P  |   K  |-------|    |-------|   W  |   D  |   Ê  |   H  |   C  |  Z   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI |ENTER |   E  | /   ,   /       \  '   \  |Space |BackSP|Delete|
 *                   |      |      | RAISE|/ LOWER /         \ LOWER\ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_QWERTY] = LAYOUT(
   KC_ESC,  BP_DLR, BP_AMPR, BP_LPRN, BP_RPRN, XXXXXXX,                   XXXXXXX,   BP_AT, BP_DQUO,  BP_EQL, BP_PERC, KC_PSCR,
   KC_TAB, BP_AGRV,    BP_B, BP_EACU,  BP_DOT, BP_MINS,                   BP_DCIR,    BP_V,    BP_L,    BP_M,    BP_X, BP_CCED,
   KC_ESC,    TG_O,    TG_U,    TG_A,    TG_I,    BP_J,                      BP_G,    TG_T,    TG_S,    TG_N,    TG_R,    BP_F,
    LOWER,    TG_Q,    BP_Y, BP_EGRV,    BP_P,    BP_K, KC_MPLY, QK_BOOT,    BP_W,    BP_D, BP_ECIR,    BP_H,    TG_C,    BP_Z,
                             KC_LGUI,  KC_ENT,    TG_E, TG_COMM, TG_QUOT,  KC_SPC, KC_BSPC,  KC_DEL
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   {  |   }  |  UP  |   (  |   )  |                    |   -  |   7  |   8  |   9  |   *  |NUMLOC|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   «  | LEFT | DOWN | RIGHT|   »  |-------.    ,-------|   =  |   4  |   5  |   6  |   /  |   \  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   [  |   ]  |   <  |   >  |      |-------|    |-------|      |   1  |   2  |   3  |   +  |   %  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |  0   |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  _______, BP_LCBR, BP_RCBR,   KC_UP, BP_LPRN, BP_RPRN,                   BP_MINS,   KC_P7,   KC_P8,   KC_P9, BP_ASTR, KC_NUM,
  _______, TG_LDAQ, TG_LEFT, TG_DOWN, TG_RGHT, BP_RDAQ,                    BP_EQL,   TG_P4,   TG_P5,   TG_P6, TG_SLSH, BP_BSLS,
  _______, BP_LBRC, BP_RBRC, BP_LABK, BP_RABK, _______, _______, _______, XXXXXXX,   KC_P1,   KC_P2,   KC_P3, BP_PLUS, BP_PERC,
                             _______, _______, _______, _______, _______,   KC_P0, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |MOD   | MODR |  S+  |  S-  |  B+  |  B-  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|RGB_TOG|    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  RGB_MOD, RGB_RMOD,RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
