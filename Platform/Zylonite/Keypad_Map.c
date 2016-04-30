
static const U8 g_DKTable[KEYPAD_DIR_NUMBER] = {'1', '2', '3'};
static const U8 g_MKTable[KEYPAD_ROW_NUMBER][KEYPAD_COL_NUMBER] = {
        {'A', 'B', 'C', '(', '!', 'D', KEY_SOFT_LEFT,     KEY_ARROW_UP},
        {'E', 'F', 'G', 'l', '3', 'H', KEY_SOFT_RIGHT,    KEY_ARROW_DOWN},
        {'I', 'J', 'K', '4', '6', 'L', KEY_ACTION_HOME,   KEY_ARROW_LEFT},
        {'M', 'N', 'O', '7', '9', 'P', KEY_ACTION_RETURN, KEY_ARROW_RIGHT},
        {')', '2', '5', '8', '0', ' ', '?', '?'},
        {'Q', 'R', 'S', '1', '#', 'T', KEY_PHONE_ANSWER,  KEY_ACTION_OK},
        {'U', 'V', 'W', '.', 0x8, 'X', KEY_PHONE_HANGUP,  KEY_BLACK_2},
        {'?', 'Y', 'Z', '?', '?', '?', KEY_BLACK_1,       KEY_BLACK_3}
};

