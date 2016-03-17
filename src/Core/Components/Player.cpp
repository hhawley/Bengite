#include "Core/Components/Player.h"

#include "Graphics/DrawingManager.h"
#include "json/jsonStream.h"

using namespace bengite::core;
using namespace bengite::content;

enum PlayerAnim { Idle = 0, Down = 1, Right = 2, Left = 3, Up = 4};

Vector2 Player::getPosition(void) const {
	
	return _sprite.getPosition();
	
}

void Player::setPosition(const Vector2& position) {
	
	_sprite.setPosition(position);
	
}

Player::Player() :
	_sprite("") {
	
	
	
}

void Player::Initialize(void) {
	
	
}

void Player::LoadContent() {
	
	_sprite.LoadContent();
	
	DrawingManager::addDraw(_sprite);
	
}

void Player::Update(const GameTime& gameTime) {
	
	_sprite.Update(gameTime);
	
}

Json::Value Player::toJson(const string& path) {
	
	Json::Value playerJson = JsonStream::OpenJson(path);
	
	return playerJson;
	
}

void Player::fromJson(const string& path) {
	
	
	
}

