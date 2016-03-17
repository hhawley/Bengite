#include "Graphics\DrawingManager.h"

#include <algorithm>
#include <iostream>

using namespace bengite::graphics;
using namespace std::placeholders;

vector<DrawFct> DrawingManager::_Level_Minus;
vector<DrawFct> DrawingManager::_Level_Zero;
vector<DrawFct> DrawingManager::_Level_One;
vector<DrawFct> DrawingManager::_Level_Two;
vector<DrawFct> DrawingManager::_Level_Control;

void DrawingManager::Draw(const GameTime& gameTime,
							SpriteBatch& spriteBatch) {

	for(auto& d_minus : _Level_Minus) {

		d_minus(gameTime, spriteBatch);

	}

	for(auto& d_zero : _Level_Zero) {

		d_zero(gameTime, spriteBatch);

	}

	for(auto& d_one : _Level_One) {

		d_one(gameTime, spriteBatch);

	}

	for(auto& d_two : _Level_Two) {

		d_two(gameTime, spriteBatch);

	}

	for(auto& control : _Level_Control) {

		control(gameTime, spriteBatch);

	}

}

void DrawingManager::addDraw(DrawObject& object) {

	DrawFct f = bind(&DrawObject::Draw, ref(object), _1, _2);

	switch(object.getDrawLevel()) {

	case -1:
		_Level_Minus.push_back(f);
		break;

	case 0:

		_Level_Zero.push_back(f);
		break;

	case 1:

		_Level_One.push_back(f);
		break;

	case 2:

		_Level_Two.push_back(f);
		break;
	case 3:

		_Level_Control.push_back(f);
		break;

	default: break;
	}

}

void DrawingManager::clear(void) {

	_Level_Minus.clear();
	_Level_Zero.clear();
	_Level_One.clear();
	_Level_Two.clear();
	_Level_Control.clear();

}
