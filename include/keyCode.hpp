#pragma once

#define DG_KEY_UNKNOWN                      0

// Printable keys
#define DG_KEY_SPACE                        32  /*   */
#define DG_KEY_EXMARK                       33  /* ! */
#define DG_KEY_QUOTE                        34  /* " */
#define DG_KEY_HASH                         35  /* # */
#define DG_KEY_DOLLAR                       36  /* $ */
#define DG_KEY_PERCENT                      37  /* % */
#define DG_KEY_AMPERSAND                    38  /* & */
#define DG_KEY_APOSTROPHE                   39  /* ' */
#define DG_KEY_LPARENTH                     40  /* ( */
#define DG_KEY_RPARENTH                     41  /* ) */
#define DG_KEY_STAR                         42  /* * */
#define DG_KEY_PLUS                         43  /* + */
#define DG_KEY_COMMA                        44  /* , */
#define DG_KEY_MINUS                        45  /* - */
#define DG_KEY_PERIOD                       46  /* . */
#define DG_KEY_SLASH                        47  /* / */
#define DG_KEY_0                            48  /* 0 */
#define DG_KEY_1                            49  /* 1 */
#define DG_KEY_2                            50  /* 2 */
#define DG_KEY_3                            51  /* 3 */
#define DG_KEY_4                            52  /* 4 */
#define DG_KEY_5                            53  /* 5 */
#define DG_KEY_6                            54  /* 6 */
#define DG_KEY_7                            55  /* 7 */
#define DG_KEY_8                            56  /* 8 */
#define DG_KEY_9                            57  /* 9 */
#define DG_KEY_COLON                        58  /* : */
#define DG_KEY_SEMICOLON                    59  /* ; */
#define DG_KEY_LESSTHAN                     60  /* < */
#define DG_KEY_EQUAL                        61  /* = */
#define DG_KEY_MORETHAN                     62  /* > */
#define DG_KEY_QUESTION                     63  /* ? */
#define DG_KEY_AT                           64  /* @ */
#define DG_KEY_A                            65  /* A */
#define DG_KEY_B                            66  /* B */
#define DG_KEY_C                            67  /* C */
#define DG_KEY_D                            68  /* D */
#define DG_KEY_E                            69  /* E */
#define DG_KEY_F                            70  /* F */
#define DG_KEY_G                            71  /* G */
#define DG_KEY_H                            72  /* H */
#define DG_KEY_I                            73  /* I */
#define DG_KEY_J                            74  /* J */
#define DG_KEY_K                            75  /* K */
#define DG_KEY_L                            76  /* L */
#define DG_KEY_M                            77  /* M */
#define DG_KEY_N                            78  /* N */
#define DG_KEY_O                            79  /* O */
#define DG_KEY_P                            80  /* P */
#define DG_KEY_Q                            81  /* Q */
#define DG_KEY_R                            82  /* R */
#define DG_KEY_S                            83  /* S */
#define DG_KEY_T                            84  /* T */
#define DG_KEY_U                            85  /* U */
#define DG_KEY_V                            86  /* V */
#define DG_KEY_W                            87  /* W */
#define DG_KEY_X                            88  /* X */
#define DG_KEY_Y                            89  /* Y */
#define DG_KEY_Z                            90  /* Z */
#define DG_KEY_LEFT_BRACKET                 91  /* [ */
#define DG_KEY_BACKSLASH                    92  /* \ */
#define DG_KEY_RIGHT_BRACKET                93  /* ] */
#define DG_KEY_CIRUMFLEX                    94  /* ^ */
#define DG_KEY_UNDERSCORE                   95  /* _ */
#define DG_KEY_GRAVE_ACCENT                 96  /* ` */
#define DG_KEY_LCURLY                       123 /* { */
#define DG_KEY_LINE                         124 /* | */
#define DG_KEY_RCURLY                       125 /* } */
#define DG_KEY_TILDE                        126 /* ~ */
#define DG_KEY_WORLD_1                      161 /* non-US #1 */
#define DG_KEY_WORLD_2                      162 /* non-US #2 */

// Function keys
#define DG_KEY_ESCAPE                       256
#define DG_KEY_ENTER                        257
#define DG_KEY_TAB                          258
#define DG_KEY_BACKSPACE                    259
#define DG_KEY_INSERT                       260
#define DG_KEY_DELETE                       261
#define DG_KEY_RIGHT                        262
#define DG_KEY_LEFT                         263
#define DG_KEY_DOWN                         264
#define DG_KEY_UP                           265
#define DG_KEY_PAGE_UP                      266
#define DG_KEY_PAGE_DOWN                    267
#define DG_KEY_HOME                         268
#define DG_KEY_END                          269
#define DG_KEY_CAPS_LOCK                    280
#define DG_KEY_SCROLL_LOCK                  281
#define DG_KEY_NUM_LOCK                     282
#define DG_KEY_PRINT_SCREEN                 283
#define DG_KEY_PAUSE                        284
#define DG_KEY_F1                           290
#define DG_KEY_F2                           291
#define DG_KEY_F3                           292
#define DG_KEY_F4                           293
#define DG_KEY_F5                           294
#define DG_KEY_F6                           295
#define DG_KEY_F7                           296
#define DG_KEY_F8                           297
#define DG_KEY_F9                           298
#define DG_KEY_F10                          299
#define DG_KEY_F11                          300
#define DG_KEY_F12                          301
#define DG_KEY_F13                          302
#define DG_KEY_F14                          303
#define DG_KEY_F15                          304
#define DG_KEY_F16                          305
#define DG_KEY_F17                          306
#define DG_KEY_F18                          307
#define DG_KEY_F19                          308
#define DG_KEY_F20                          309
#define DG_KEY_F21                          310
#define DG_KEY_F22                          311
#define DG_KEY_F23                          312
#define DG_KEY_F24                          313
#define DG_KEY_F25                          314
#define DG_KEY_KP_0                         320
#define DG_KEY_KP_1                         321
#define DG_KEY_KP_2                         322
#define DG_KEY_KP_3                         323
#define DG_KEY_KP_4                         324
#define DG_KEY_KP_5                         325
#define DG_KEY_KP_6                         326
#define DG_KEY_KP_7                         327
#define DG_KEY_KP_8                         328
#define DG_KEY_KP_9                         329
#define DG_KEY_KP_DECIMAL                   330
#define DG_KEY_KP_DIVIDE                    331
#define DG_KEY_KP_MULTIPLY                  332
#define DG_KEY_KP_SUBTRACT                  333
#define DG_KEY_KP_ADD                       334
#define DG_KEY_KP_ENTER                     335
#define DG_KEY_KP_EQUAL                     336
#define DG_KEY_LEFT_SHIFT                   340
#define DG_KEY_LEFT_CONTROL                 341
#define DG_KEY_LEFT_ALT                     342
#define DG_KEY_LEFT_SUPER                   343
#define DG_KEY_RIGHT_SHIFT                  344
#define DG_KEY_RIGHT_CONTROL                345
#define DG_KEY_RIGHT_ALT                    346
#define DG_KEY_RIGHT_SUPER                  347
#define DG_KEY_MENU                         348

#define DG_KEY_LAST                         DG_KEY_MENU

#define DG_MOD_SHIFT                        0x0001
// If this bit is set one or more Control keys were held down.

#define DG_MOD_CONTROL                      0x0002
// If this bit is set one or more Alt keys were held down.

#define DG_MOD_ALT                          0x0004
// If this bit is set one or more Super keys were held down.

#define DG_MOD_SUPER                        0x0008
// If this bit is set the Caps Lock key is enabled.

#define DG_MOD_CAPS_LOCK                    0x0010
// If this bit is set the Num Lock key is enabled.

#define DG_MOD_NUM_LOCK                     0x0020

#define DG_MOUSE_BUTTON_1                   0
#define DG_MOUSE_BUTTON_2                   1
#define DG_MOUSE_BUTTON_3                   2
#define DG_MOUSE_BUTTON_4                   3
#define DG_MOUSE_BUTTON_5                   4
#define DG_MOUSE_BUTTON_6                   5
#define DG_MOUSE_BUTTON_7                   6
#define DG_MOUSE_BUTTON_8                   7
#define DG_MOUSE_BUTTON_LAST                DG_MOUSE_BUTTON_8
#define DG_MOUSE_BUTTON_LEFT                DG_MOUSE_BUTTON_1
#define DG_MOUSE_BUTTON_RIGHT               DG_MOUSE_BUTTON_2
#define DG_MOUSE_BUTTON_MIDDLE              DG_MOUSE_BUTTON_3

// joysticks Joysticks
#define DG_JOYSTICK_1                       0
#define DG_JOYSTICK_2                       1
#define DG_JOYSTICK_3                       2
#define DG_JOYSTICK_4                       3
#define DG_JOYSTICK_5                       4
#define DG_JOYSTICK_6                       5
#define DG_JOYSTICK_7                       6
#define DG_JOYSTICK_8                       7
#define DG_JOYSTICK_9                       8
#define DG_JOYSTICK_10                      9
#define DG_JOYSTICK_11                      10
#define DG_JOYSTICK_12                      11
#define DG_JOYSTICK_13                      12
#define DG_JOYSTICK_14                      13
#define DG_JOYSTICK_15                      14
#define DG_JOYSTICK_16                      15
#define DG_JOYSTICK_LAST                    DG_JOYSTICK_16

// @defgroup gamepad_buttons Gamepad buttons
#define DG_GAMEPAD_BUTTON_A                 0
#define DG_GAMEPAD_BUTTON_B                 1
#define DG_GAMEPAD_BUTTON_X                 2
#define DG_GAMEPAD_BUTTON_Y                 3
#define DG_GAMEPAD_BUTTON_LEFT_BUMPER       4
#define DG_GAMEPAD_BUTTON_RIGHT_BUMPER      5
#define DG_GAMEPAD_BUTTON_BACK              6
#define DG_GAMEPAD_BUTTON_START             7
#define DG_GAMEPAD_BUTTON_GUIDE             8
#define DG_GAMEPAD_BUTTON_LEFT_THUMB        9
#define DG_GAMEPAD_BUTTON_RIGHT_THUMB       10
#define DG_GAMEPAD_BUTTON_DPAD_UP           11
#define DG_GAMEPAD_BUTTON_DPAD_RIGHT        12
#define DG_GAMEPAD_BUTTON_DPAD_DOWN         13
#define DG_GAMEPAD_BUTTON_DPAD_LEFT         14
#define DG_GAMEPAD_BUTTON_LAST              DG_GAMEPAD_BUTTON_DPAD_LEFT

#define DG_GAMEPAD_BUTTON_CROSS             DG_GAMEPAD_BUTTON_A
#define DG_GAMEPAD_BUTTON_CIRCLE            DG_GAMEPAD_BUTTON_B
#define DG_GAMEPAD_BUTTON_SQUARE            DG_GAMEPAD_BUTTON_X
#define DG_GAMEPAD_BUTTON_TRIANGLE          DG_GAMEPAD_BUTTON_Y

#define DG_GAMEPAD_BUTTON_A                 0
#define DG_GAMEPAD_BUTTON_B                 1
#define DG_GAMEPAD_BUTTON_X                 2
#define DG_GAMEPAD_BUTTON_Y                 3
#define DG_GAMEPAD_BUTTON_LEFT_BUMPER       4
#define DG_GAMEPAD_BUTTON_RIGHT_BUMPER      5
#define DG_GAMEPAD_BUTTON_BACK              6
#define DG_GAMEPAD_BUTTON_START             7
#define DG_GAMEPAD_BUTTON_GUIDE             8
#define DG_GAMEPAD_BUTTON_LEFT_THUMB        9
#define DG_GAMEPAD_BUTTON_RIGHT_THUMB       10
#define DG_GAMEPAD_BUTTON_DPAD_UP           11
#define DG_GAMEPAD_BUTTON_DPAD_RIGHT        12
#define DG_GAMEPAD_BUTTON_DPAD_DOWN         13
#define DG_GAMEPAD_BUTTON_DPAD_LEFT         14
#define DG_GAMEPAD_BUTTON_LAST              DG_GAMEPAD_BUTTON_DPAD_LEFT

#define DG_GAMEPAD_BUTTON_CROSS             DG_GAMEPAD_BUTTON_A
#define DG_GAMEPAD_BUTTON_CIRCLE            DG_GAMEPAD_BUTTON_B
#define DG_GAMEPAD_BUTTON_SQUARE            DG_GAMEPAD_BUTTON_X
#define DG_GAMEPAD_BUTTON_TRIANGLE          DG_GAMEPAD_BUTTON_Y

// gamepad_axes Gamepad axes
#define DG_GAMEPAD_AXIS_LEFT_X              0
#define DG_GAMEPAD_AXIS_LEFT_Y              1
#define DG_GAMEPAD_AXIS_RIGHT_X             2
#define DG_GAMEPAD_AXIS_RIGHT_Y             3
#define DG_GAMEPAD_AXIS_LEFT_TRIGGER        4
#define DG_GAMEPAD_AXIS_RIGHT_TRIGGER       5
#define DG_GAMEPAD_AXIS_LAST                DG_GAMEPAD_AXIS_RIGHT_TRIGGER

#define DG_MOUSE_BUTTON_1                   0
#define DG_MOUSE_BUTTON_2                   1
#define DG_MOUSE_BUTTON_3                   2
#define DG_MOUSE_BUTTON_4                   3
#define DG_MOUSE_BUTTON_5                   4
#define DG_MOUSE_BUTTON_6                   5
#define DG_MOUSE_BUTTON_7                   6
#define DG_MOUSE_BUTTON_8                   7
#define DG_MOUSE_BUTTON_LAST                DG_MOUSE_BUTTON_8
#define DG_MOUSE_BUTTON_LEFT                DG_MOUSE_BUTTON_1
#define DG_MOUSE_BUTTON_RIGHT               DG_MOUSE_BUTTON_2
#define DG_MOUSE_BUTTON_MIDDLE              DG_MOUSE_BUTTON_3

// joysticks Joysticks
#define DG_JOYSTICK_1                       0
#define DG_JOYSTICK_2                       1
#define DG_JOYSTICK_3                       2
#define DG_JOYSTICK_4                       3
#define DG_JOYSTICK_5                       4
#define DG_JOYSTICK_6                       5
#define DG_JOYSTICK_7                       6
#define DG_JOYSTICK_8                       7
#define DG_JOYSTICK_9                       8
#define DG_JOYSTICK_10                      9
#define DG_JOYSTICK_11                      10
#define DG_JOYSTICK_12                      11
#define DG_JOYSTICK_13                      12
#define DG_JOYSTICK_14                      13
#define DG_JOYSTICK_15                      14
#define DG_JOYSTICK_16                      15
#define DG_JOYSTICK_LAST                    DG_JOYSTICK_16

// gamepad_buttons Gamepad buttons
#define DG_GAMEPAD_BUTTON_A                 0
#define DG_GAMEPAD_BUTTON_B                 1
#define DG_GAMEPAD_BUTTON_X                 2
#define DG_GAMEPAD_BUTTON_Y                 3
#define DG_GAMEPAD_BUTTON_LEFT_BUMPER       4
#define DG_GAMEPAD_BUTTON_RIGHT_BUMPER      5
#define DG_GAMEPAD_BUTTON_BACK              6
#define DG_GAMEPAD_BUTTON_START             7
#define DG_GAMEPAD_BUTTON_GUIDE             8
#define DG_GAMEPAD_BUTTON_LEFT_THUMB        9
#define DG_GAMEPAD_BUTTON_RIGHT_THUMB       10
#define DG_GAMEPAD_BUTTON_DPAD_UP           11
#define DG_GAMEPAD_BUTTON_DPAD_RIGHT        12
#define DG_GAMEPAD_BUTTON_DPAD_DOWN         13
#define DG_GAMEPAD_BUTTON_DPAD_LEFT         14
#define DG_GAMEPAD_BUTTON_LAST              DG_GAMEPAD_BUTTON_DPAD_LEFT

#define DG_GAMEPAD_BUTTON_CROSS             DG_GAMEPAD_BUTTON_A
#define DG_GAMEPAD_BUTTON_CIRCLE            DG_GAMEPAD_BUTTON_B
#define DG_GAMEPAD_BUTTON_SQUARE            DG_GAMEPAD_BUTTON_X
#define DG_GAMEPAD_BUTTON_TRIANGLE          DG_GAMEPAD_BUTTON_Y
#define DG_GAMEPAD_BUTTON_A                 0
#define DG_GAMEPAD_BUTTON_B                 1
#define DG_GAMEPAD_BUTTON_X                 2
#define DG_GAMEPAD_BUTTON_Y                 3
#define DG_GAMEPAD_BUTTON_LEFT_BUMPER       4
#define DG_GAMEPAD_BUTTON_RIGHT_BUMPER      5
#define DG_GAMEPAD_BUTTON_BACK              6
#define DG_GAMEPAD_BUTTON_START             7
#define DG_GAMEPAD_BUTTON_GUIDE             8
#define DG_GAMEPAD_BUTTON_LEFT_THUMB        9
#define DG_GAMEPAD_BUTTON_RIGHT_THUMB       10
#define DG_GAMEPAD_BUTTON_DPAD_UP           11
#define DG_GAMEPAD_BUTTON_DPAD_RIGHT        12
#define DG_GAMEPAD_BUTTON_DPAD_DOWN         13
#define DG_GAMEPAD_BUTTON_DPAD_LEFT         14
#define DG_GAMEPAD_BUTTON_LAST              DG_GAMEPAD_BUTTON_DPAD_LEFT

#define DG_GAMEPAD_BUTTON_CROSS             DG_GAMEPAD_BUTTON_A
#define DG_GAMEPAD_BUTTON_CIRCLE            DG_GAMEPAD_BUTTON_B
#define DG_GAMEPAD_BUTTON_SQUARE            DG_GAMEPAD_BUTTON_X
#define DG_GAMEPAD_BUTTON_TRIANGLE          DG_GAMEPAD_BUTTON_Y

// @defgroup gamepad_axes Gamepad axes
#define DG_GAMEPAD_AXIS_LEFT_X              0
#define DG_GAMEPAD_AXIS_LEFT_Y              1
#define DG_GAMEPAD_AXIS_RIGHT_X             2
#define DG_GAMEPAD_AXIS_RIGHT_Y             3
#define DG_GAMEPAD_AXIS_LEFT_TRIGGER        4
#define DG_GAMEPAD_AXIS_RIGHT_TRIGGER       5
#define DG_GAMEPAD_AXIS_LAST                DG_GAMEPAD_AXIS_RIGHT_TRIGGER
