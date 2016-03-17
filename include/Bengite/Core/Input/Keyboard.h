#pragma once

#include <raylib.h>
#include <vector>

namespace bengite { namespace core {
enum Keys {
	Space = KEY_SPACE,
	Zero = KEY_ZERO,
	One = KEY_ONE,
	Two = KEY_TWO,
	Three = KEY_THREE,
	Four = KEY_FOUR,
	Five = KEY_FIVE,
	Six = KEY_SIX, 
	Seven = KEY_SEVEN,
	Eight = KEY_EIGHT,
	Nine = KEY_NINE,
	A = 97,//KEY_A,
	B = 98,//KEY_B,
	C = 99,//KEY_C,
	D = 100,//KEY_D,
	E = 101,//KEY_E,
	F = 102,//KEY_F,
	G = 103,//KEY_G,
	H = 104,//KEY_H,
	I = 105,//KEY_I,
	J = 106,//KEY_J,
	K = 107,//KEY_K,
	L = 108,//KEY_L,
	M = 109,//KEY_M,
	N = 110,//KEY_N,
	O = 111,//KEY_O,
	P = 112,//KEY_P,
	Q = 113,//KEY_Q,
	R = 114,//KEY_R,
	S = 115,//KEY_S,
	T = 116,//KEY_T,
	U = 117,//KEY_U,
	V = 118,//KEY_V,
	W = 119,//KEY_W,
	X = 120,//KEY_X,
	Y = 121,//KEY_Y,
	Z = 122,//KEY_Z,
	Escape = KEY_ESCAPE,
	Enter = KEY_ENTER,
	Backspace = KEY_BACKSPACE,
	Right = KEY_RIGHT,
	Left = KEY_LEFT,
	Down = KEY_DOWN,
	Up = KEY_UP,
	F1 = KEY_F1,
	F2 = KEY_F2,
	F3 = KEY_F3,
	F4 = KEY_F4,
	F5 = KEY_F5,
	F6 = KEY_F6,
	F7 = KEY_F7,
	F8 = KEY_F8,
	F9 = KEY_F9,
	F10 = KEY_F10,
	F11 = KEY_F11,
	F12 = KEY_F12,
	Shift_L = KEY_LEFT_SHIFT,
	Shift_R = KEY_RIGHT_SHIFT,
	Control_L = KEY_LEFT_CONTROL,
	Control_R = KEY_RIGHT_CONTROL,
	Alt_F = KEY_LEFT_ALT,
	Alt_R = KEY_RIGHT_ALT,
	Parentesis_Open = 40,
	Parentesis_Close = 41,
	Asterisk = 42,
	Plus = 43,
	Comma = 44,
	Minus = 45,
	Period = 46,
	Slash = 47,
	Equal = 61,
	Braket_Open = 91,
	Braket_Close = 93,
	Circumflex = 94
};

class Keyboard {
private:

public:

#if PLATFORM_ANDROID
	static void Show(void);
	static void Hide(void);
#endif
	static bool isKeyPressed(const Keys&);
	static bool isKeyDown(const Keys&);
	static bool isKeyReleased(const Keys&);
	static bool isKeyUp(const Keys&);
	static std::vector<Keys> PressedKeys();
	static char keyToChar(const Keys&); 


};

}}
