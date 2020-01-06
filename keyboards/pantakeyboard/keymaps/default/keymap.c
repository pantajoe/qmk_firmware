
#include QMK_KEYBOARD_H

#define ______ KC_TRNS
#define ALT_F4 LALT(KC_F4)

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEF 0 // default layer
#define _FL  1 // function 1 layer
#define _SL  2 // function 2 layer (Function Keys)
#define _TL  3 // function 3 layer (large umlauts)

// Tap Dance Declarations
enum {
  TD_ESC_CAPS = 0
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_ESC_CAPS]   = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
  // Other declarations would go here, separated by commas, if you have them
};

// custom macros
enum custom_keycodes {
  A_UML = SAFE_RANGE, // ä = ALT + 0228
  O_UML,              // ö = ALT + 0246
  U_UML,              // ü = ALT + 0252
  SH_A_UML,           // Ä = ALT + 0196
  SH_O_UML,           // Ö = ALT + 0214
  SH_U_UML,           // Ü = ALT + 0220
  SZ_GER,             // ß = ALT + 0223
  EUR                 // € = ALT + 0128
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _DEF: Default Layer
    * ,-----------------------------------------------------------.
    * |~ |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| Back   |
    * |-----------------------------------------------------------|
    * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| \   |
    * |-----------------------------------------------------------|
    * |Esc   | A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Return |
    * |-----------------------------------------------------------|
    * |Sft    |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| Fn1|up|sft|
    * |-----------------------------------------------------------|
    * |Ctrl | Alt| GUI|      Space            |GUI|Alt|lef|dow|rig|
    * `-----------------------------------------------------------'
    */
  [_DEF] = LAYOUT(
    KC_GRV,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    TD(TD_ESC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_LSFT,         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   MO(_FL),
    KC_LCTL,         KC_LALT, KC_LGUI,                            KC_SPC,                    KC_RGUI, KC_RALT, KC_LEFT, KC_DOWN, KC_RIGHT
  ),
  // first layer
  [_FL] = LAYOUT(
    ______,   KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI,  KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP,  KC_DEL,
    RGB_TOG,  ALT_F4,             ______,           EUR,     ______,  RGB_HUD, RGB_HUI,  U_UML,               ______,              O_UML,               ______,        ______,            ______,           ______,
    ______,   A_UML,              SZ_GER,           ______,  ______,  ______,  ______,   ______,              ______,              ______,              ______,        ______,                              ______,
    MO(_TL),  ______,             ______,           ______,  ______,  ______,  KC_TILDE, ______,              ______,              ______,              ______,        MO(_SL),           KC_PGUP,          ______,
    ______,   ______,             MAGIC_SWAP_LCTL_LGUI,               ______,                                 MAGIC_UNSWAP_LCTL_LGUI,                   ______,        KC_HOME,           KC_PGDN,          KC_END
  ),
  // second layer
  [_SL] = LAYOUT(
    KC_WAKE, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_SLEP,
    ______,  ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
    ______,  ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
    ______,  ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
    ______,  ______, ______,                         ______,                 ______, ______, ______, ______, ______
  ),
  // third layer
  [_TL] = LAYOUT(
    ______, ______,   ______, ______, ______, ______, ______, ______,   ______, ______,   ______, ______, ______, ______,
    ______, ______,   ______, ______, ______, ______, ______, SH_U_UML, ______, SH_O_UML, ______, ______, ______, ______,
    ______, SH_A_UML, ______, ______, ______, ______, ______, ______,   ______, ______,   ______, ______, ______,
    ______, ______,   ______, ______, ______, ______, ______, ______,   ______, ______,   ______, ______, ______, ______,
    ______, ______,   ______,                         ______,                   ______,   ______, ______, ______, ______
  )
};

// A_UML,    // ä = ALT + 0228
// O_UML,    // ö = ALT + 0246
// U_UML,    // ü = ALT + 0252
// SH_A_UML, // Ä = ALT + 0196
// SH_O_UML, // Ö = ALT + 0214
// SH_U_UML, // Ü = ALT + 0220
// SZ_GER,   // ß = ALT + 0223
// EUR,      // € = ALT + 0128
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case A_UML:
        if(record->event.pressed) {
          // if num lock is active
          if (!!(1 << USB_LED_NUM_LOCK)) {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_8)));
          } else {
            SEND_STRING(SS_TAP(X_NUMLOCK) SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_8)));
          }
        }
        return false;
        break;
      case O_UML:
        if(record->event.pressed) {
          // if num lock is active
          if (!!(1 << USB_LED_NUM_LOCK)) {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_TAP(X_KP_6)));
          } else {
            SEND_STRING(SS_TAP(X_NUMLOCK) SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_TAP(X_KP_6)));
          }
        }
        return false;
        break;
      case U_UML:
        if(record->event.pressed) {
          if (!!(1 << USB_LED_NUM_LOCK)) {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_5) SS_TAP(X_KP_2)));
          } else {
            SEND_STRING(SS_TAP(X_NUMLOCK) SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_5) SS_TAP(X_KP_2)));
          }
        }
        return false;
        break;
      case SH_A_UML:
        if(record->event.pressed) {
          if (!!(1 << USB_LED_NUM_LOCK)) {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_6)));
          } else {
            SEND_STRING(SS_TAP(X_NUMLOCK) SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_6)));
          }
        }
        return false;
        break;
      case SH_O_UML:
        if(record->event.pressed) {
          if (!!(1 << USB_LED_NUM_LOCK)) {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_4)));
          } else {
            SEND_STRING(SS_TAP(X_NUMLOCK) SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_4)));
          }
        }
        return false;
        break;
      case SH_U_UML:
        if(record->event.pressed) {
          if (!!(1 << USB_LED_NUM_LOCK)) {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_0)));
          } else {
            SEND_STRING(SS_TAP(X_NUMLOCK) SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_0)));
          }
        }
        return false;
        break;
      case SZ_GER:
        if(record->event.pressed) {
          if (!!(1 << USB_LED_NUM_LOCK)) {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_3)));
          } else {
            SEND_STRING(SS_TAP(X_NUMLOCK) SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_3)));
          }
        }
        return false;
        break;
      case EUR:
        if(record->event.pressed) {
          if (!!(1 << USB_LED_NUM_LOCK)) {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_2) SS_TAP(X_KP_8)));
          } else {
            SEND_STRING(SS_TAP(X_NUMLOCK) SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_2) SS_TAP(X_KP_8)));
          }
        }
        return false;
        break;
    }
  }

  return true;
};
