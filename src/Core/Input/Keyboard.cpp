#include "Core/Input/Keyboard.h"

using namespace bengite::core;

#if PLATFORM_ANDROID

// It will get it from a header located in keyboardAndroid.h in 
// the android project, IT IS NOT INCLUDED HERE
extern "C" void displayKeyboard(bool show);

void Keyboard::Show(void) {

	displayKeyboard(true);

}

void Keyboard::Hide(void) {

	displayKeyboard(false);

}

#endif

bool Keyboard::isKeyPressed(const Keys& key) {

#if PLATFORM_DESKTOP
	return IsKeyPressed(key);
#elif PLATFORM_ANDROID
	return IsButtonPressed(key);
#endif

}

bool Keyboard::isKeyDown(const Keys& key) {
#if PLATFORM_DESKTOP
	return IsKeyDown(key);
#elif PLATFORM_ANDROID
	return IsButtonDown(key);
#endif

}

bool Keyboard::isKeyReleased(const Keys& key) {

#if PLATFORM_DESKTOP
	return IsKeyReleased(key);
#elif PLATFORM_ANDROID
	return IsButtonReleased(key);
#endif

}

bool Keyboard::isKeyUp(const Keys& key) {

#if PLATFORM_DESKTOP
	return IsKeyUp(key);
#elif PLATFORM_ANDROID
	return !IsButtonDown(key);
#endif

}

std::vector<Keys> Keyboard::PressedKeys() {

	std::vector<Keys> pressedKeys;

	if(isKeyPressed(Keys::Space)) {
		pressedKeys.push_back(Keys::Space);
	}

	if(isKeyPressed(Keys::Escape)) {
		pressedKeys.push_back(Keys::Escape);
	}

	if(isKeyPressed(Keys::Enter)) {
		pressedKeys.push_back(Keys::Enter);
	}

	if(isKeyPressed(Keys::Backspace)) {
		pressedKeys.push_back(Keys::Backspace);
	}

	if(isKeyPressed(Keys::Right)) {
		pressedKeys.push_back(Keys::Right);
	}

	if(isKeyPressed(Keys::Right)) {
		pressedKeys.push_back(Keys::Right);
	}

	if(isKeyPressed(Keys::Down)) {
		pressedKeys.push_back(Keys::Down);
	}

	if(isKeyPressed(Keys::Up)) {
		pressedKeys.push_back(Keys::Up);
	}

	int i = 0;
	for(i = 40; i <= 47; i++) {
		if(isKeyPressed(static_cast<Keys>(i))) {
			pressedKeys.push_back(static_cast<Keys>(i));
		}	
	}
	
	if(isKeyPressed(Keys::Braket_Open)) {
		pressedKeys.push_back(Keys::Braket_Open);
	}

	if(isKeyPressed(Keys::Braket_Close)) {
		pressedKeys.push_back(Keys::Braket_Close);
	}	

	if(isKeyPressed(Keys::Circumflex)) {
		pressedKeys.push_back(Keys::Circumflex);
	}

	for(i = KEY_F1; i <= KEY_F12; i++ ) {

		if(isKeyPressed(static_cast<Keys>(i))) {
			pressedKeys.push_back(static_cast<Keys>(i));
		}

	}

	if(isKeyDown(Keys::Shift_L) || isKeyDown(Keys::Shift_R)) {

		if(isKeyPressed(Keys::Equal)) {
			pressedKeys.push_back(Keys::Plus);
		}

		if(isKeyPressed(Keys::Six)) {
			pressedKeys.push_back(Keys::Circumflex);
		}

		if(isKeyPressed(Keys::Eight)) {
			pressedKeys.push_back(Keys::Asterisk);
		}

		if(isKeyPressed(Keys::Nine)) {
			pressedKeys.push_back(Keys::Parentesis_Open);
		}

		if(isKeyPressed(Keys::Zero)) {
			pressedKeys.push_back(Keys::Parentesis_Close);
		}

	} else {

		if(isKeyPressed(Keys::Equal)) {
			pressedKeys.push_back(Keys::Equal);
		}
	
		for(i = KEY_ZERO; i <= KEY_NINE; i++) {

			if(isKeyPressed(static_cast<Keys>(i))) {
				pressedKeys.push_back(static_cast<Keys>(i));
			}
		
		}

	}

	// for(i = KEY_LEFT_SHIFT; i <= KEY_RIGHT_ALT; i++) {

	// 	if(IsKeyPressed(i)) {
	// 		pressedKeys.push_back(static_cast<Keys>(i));
	// 	}
	// }


	for(i = KEY_A; i <= KEY_Z; i++) {

		if(isKeyPressed(static_cast<Keys>(i))) {
			pressedKeys.push_back(static_cast<Keys>(i + 32));
		}
		
	}


	return pressedKeys;

}

char Keyboard::keyToChar(const Keys& key) {

	return static_cast<char>(key);

}