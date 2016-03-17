/*
*	Class: DrawObject
*	Description: An abstract class intended to be the
*	mother of all game drawing objects so we can manage them
*	easily. 
*/

#pragma once

#include "Core/GameTime.h"

#include "Graphics/SpriteBatch.h"

using namespace bengite::core;

namespace bengite { namespace graphics {
	
class DrawObject {
private:

public:

	DrawObject() : _drawLevel(0) {}
	DrawObject(const short int& level) : _drawLevel(level) {}
	virtual void Draw(const GameTime& gameTime, 
		SpriteBatch& spriteBatch) {}

	short int getDrawLevel(void) const { return _drawLevel; }
	
protected:

	short int _drawLevel;
	
};
	
}}