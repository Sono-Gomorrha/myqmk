// Personal Combo definitions

const uint16_t PROGMEM Q_combo[] = {KC_B, KC_H, COMBO_END};
const uint16_t PROGMEM Z_combo[] = {KC_QUOT, KC_B COMBO_END};
const uint16_t PROGMEM QUES_combo[] = {KC_J, KC_X COMBO_END};
const uint16_t PROGMEM EXCLM_combo[] = {KC_SLASH, KC_J COMBO_END};
const uint16_t PROGMEM UMLA_combo[] = {KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM UMLU_combo[] = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM UMLO_combo[] = {KC_O, KC_Y, COMBO_END};
const uint16_t PROGMEM DE_SS_combo[] = {KC_C, KC_S, COMBO_END};
combo_t key_combos[] = {
    COMBO(Q_combo, KC_Q),
    COMBO(Z_combo, KC_Z), 
    COMBO(QUES_combo, KC_QUES),
    COMBO(EXCLM_combo, KC_EXCLM),
    COMBO(UMLA_combo, ALGR(US_Q))
    COMBO(UMLU_combo, ALGR(US_Y)), 
    COMBO(UMLO_combo, ALGR(US_P)), 
    COMBO(DE_SS_combo, DE_SS), 
};

// Custom copy and paste? Screenshot, etc.
// unicode for capital eszet?
