#include "Core/Input/Mouse.h"

using namespace bengite::core;

Vector2 Mouse::_position;
Texture2D Mouse::_texture;

bool Mouse::_leftClick;
bool Mouse::_leftDown;
bool Mouse::_rightClick;
bool Mouse::_rightDown;
 
Vector2 Mouse::getPosition(void) {
	
	return _position;
	
}

Rectangle Mouse::getRectangle(void) {
	
	return (Rectangle){(int)_position.x, (int)_position.y, 1, 1};
	
}

void Mouse::LoadContent(void) {
	
	//TODO: Load texture PL0OX
	
}

void Mouse::Update(const GameTime& gameTime) {

	_position = GetMousePosition();
	
	_leftClick = IsMouseButtonReleased(0);
	_leftDown = IsMouseButtonDown(0);
	_rightClick = IsMouseButtonReleased(1);
	_rightDown = IsMouseButtonDown(1);
	
}

void Mouse::Draw(SpriteBatch& spriteBatch) {
	
	spriteBatch.Draw(_texture, _position, WHITE);
	
}


bool Mouse::isTouching(const Rectangle& rec) {
	
	return CheckCollisionRecs(getRectangle(), rec);
	
}

bool Mouse::LeftClick(void) {
	
	return _leftClick;
	
}

bool Mouse::LeftDown(void) {
	
	return _leftDown;
	
}

bool Mouse::RightClick(void)  {
	
	return _rightClick;
	
}

bool Mouse::RightDown(void) {
	
	return _rightDown;
	
}
