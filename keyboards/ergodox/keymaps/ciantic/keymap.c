#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#include "keymap_german.h"

#include "keymap_nordic.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
};

enum custom_macros {
  VERSION = 0,
  PARENTHESIS,
  PHPSTART,
  PHPEND,
  BACKTICK,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = KEYMAP(KC_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_NO, MO(1), KC_A, KC_S, KC_D, KC_F, KC_G, OSM(MOD_LSFT), KC_Z, KC_X, KC_C, KC_V, KC_B, OSM(MOD_LGUI), OSM(MOD_LCTL), KC_NONUS_BSLASH, OSM(MOD_LGUI), OSM(MOD_LALT), MO(3), KC_NO, KC_NO, KC_NO, KC_SPACE, OSL(4), KC_ESCAPE, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_BSPACE, KC_NO, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NONUS_HASH, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE, KC_NO, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, OSM(MOD_RSFT), MO(3), OSM(MOD_RALT), KC_APPLICATION, KC_NO, OSM(MOD_LCTL), KC_NO, KC_NO, KC_NO, KC_NO, OSL(4), KC_SPACE),
  [1] = KEYMAP(KC_NO, LALT(LCTL(LGUI(LSFT(KC_1)))), LALT(LCTL(LGUI(LSFT(KC_2)))), LALT(LCTL(LGUI(LSFT(KC_3)))), LALT(LCTL(LGUI(LSFT(KC_4)))), LALT(LCTL(LGUI(LSFT(KC_5)))), KC_NO, KC_NO, LALT(LCTL(LGUI(LSFT(KC_Q)))), LALT(LCTL(LGUI(LSFT(KC_W)))), LALT(LCTL(LGUI(LSFT(KC_E)))), LALT(LCTL(LGUI(LSFT(KC_R)))), LALT(LCTL(LGUI(LSFT(KC_T)))), KC_NO, KC_NO, KC_NO, LALT(LCTL(LSFT(KC_S))), KC_LALT, KC_LSHIFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_HUI, KC_NO, KC_NO, KC_NO, KC_LGUI, KC_NO, RGB_MOD, RGB_SLD, RGB_VAI, KC_LCTL, RGB_TOG, RGB_VAD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DELETE, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_NO, KC_ENTER, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDOWN, KC_NO, KC_NO, KC_BSPACE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_SYSTEM_SLEEP, KC_NO, KC_NO, KC_NO, KC_NO),
  [2] = KEYMAP(KC_NO,KC_NUMLOCK,KC_KP_7,KC_KP_8,KC_KP_9,KC_NO,KC_NO,KC_NO,KC_NO,KC_KP_4,KC_KP_5,KC_KP_6,KC_NO,KC_NO,KC_NO,KC_NO,KC_KP_1,KC_KP_2,KC_KP_3,KC_NO,KC_NO,KC_NO,KC_NO,KC_KP_0,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO),
 [3] = KEYMAP(KC_NO,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_NO,KC_NO,KC_NONUS_HASH,LSFT(KC_3),LSFT(KC_6),KC_NO,KC_NO,KC_NO,LSFT(KC_1),LSFT(KC_2),RALT(KC_2),RALT(KC_4),LSFT(KC_5),MO(5),KC_NONUS_BSLASH,LSFT(KC_NONUS_BSLASH),RALT(KC_NONUS_BSLASH),KC_NONUS_BSLASH,LSFT(KC_NONUS_BSLASH),LSFT(KC_NONUS_BSLASH),KC_TRNS,KC_NO,KC_TRNS,KC_TRNS,KC_TRNS,KC_NO,KC_NO,KC_NO,KC_SPACE,KC_NO,KC_NO,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_F12,LSFT(KC_RBRACKET),KC_NO,M(BACKTICK),LSFT(KC_7),RALT(KC_8),RALT(KC_9),KC_NO,RALT(KC_RBRACKET),LSFT(KC_0),RALT(KC_7),LSFT(KC_8),LSFT(KC_9),RALT(KC_0),KC_NONUS_HASH,KC_ENTER,KC_TRNS,RALT(KC_MINUS),LSFT(KC_MINUS),KC_MINUS,LSFT(KC_NONUS_HASH),MO(5),KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_SPACE),
 [4] = KEYMAP(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRANSPARENT,KC_NO,KC_1,KC_2,KC_3,KC_4,KC_5,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_NO,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_F11,KC_F12,KC_TRANSPARENT,KC_TRANSPARENT,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_0,KC_6,KC_7,KC_8,KC_9,KC_0,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),
 [5] = KEYMAP(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRNS,KC_TRNS,M(PHPSTART),M(PHPEND),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,M(PARENTHESIS),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT)
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (record->event.pressed) {
    switch(id) {
      case VERSION:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      break;
      case PARENTHESIS:
        // ();
        return MACRO(D(LSFT), T(8), T(9), T(COMMA), U(LSFT), T(LEFT), T(LEFT), END);
      break;
      case PHPSTART:
        // <?php 
        return MACRO(T(NONUS_BSLASH), D(LSFT), T(MINUS), U(LSFT), T(P), T(H), T(P), T(SPACE), END);
      break;
      case PHPEND:
        // ?>
        return MACRO(D(LSFT), T(MINUS), T(NONUS_BSLASH), U(LSFT), END);
      break;
      case BACKTICK:
        // `
        return MACRO(D(LSFT), T(EQUAL), U(LSFT), T(SPACE), END);
      break;
    }
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
    
  }
  return true;
}

void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

};
