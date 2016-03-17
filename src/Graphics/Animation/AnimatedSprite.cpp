#include "Graphics/Animation/AnimatedSprite.h"

#include "Content/ContentManager.h"

#include "json/jsonStream.h"

using namespace bengite::graphics;
using namespace bengite::content;

AnimationDict AnimatedSprite::getAnimations(void) const {
		
	return _animations;
		
}

Animation AnimatedSprite::getCurrentAnimation(void) const {
	
	return _animations[_currentKey];
	
}

int	AnimatedSprite::getCurrentKey(void) const {
	
	return _currentKey;
	
}

Vector2 AnimatedSprite::getPosition(void) const {
	
	return _position;
	
}

Vector2 AnimatedSprite::getVelocity(void) const {
	
	return _velocity;
	
}

Color AnimatedSprite::getColor(void) const {
	
	return _color;
	
}

bool AnimatedSprite::isAnimating(void) const {
	
	return _isAnimating;
	
}

void AnimatedSprite::setCurrentAnimation(const int& key) {
	
	_currentKey = key;
	
}

void AnimatedSprite::setAnimating(const bool& isAnimating) {
	
	_isAnimating = isAnimating;
	
}

void AnimatedSprite::setPosition(const Vector2& position) {
	
	_position = position;
	
}

void AnimatedSprite::setSpeed(const Vector2& velocity) {
	
	_velocity = velocity;
	
}

void AnimatedSprite::setColor(const Color& color) {
	
	_color = color;
	
}

AnimatedSprite::AnimatedSprite()
	: DrawObject(1), _currentKey(0), _resourceName(""), _color(WHITE) {
	
	
}

AnimatedSprite::AnimatedSprite(const string& path) 
	: DrawObject(1), _currentKey(0), _resourceName(path), _color(WHITE) {
	
	
	
}

void AnimatedSprite::LoadContent() {
	
	if(_resourceName != "") {
		
		auto jsonValue = JsonStream::OpenJson("Content\\" + _resourceName + ".json");
		fromJson(jsonValue);
	
	} else {
		
		auto jsonValue = JsonStream::OpenJson("Content\\BaseAnimation.json");
		fromJson(jsonValue);
		
	}
	
}


void AnimatedSprite::Update(const GameTime& gameTime) {
	
	if(_isAnimating)
		_animations[_currentKey].Update(gameTime);
	else 
		_animations[_currentKey].setCurrentFrame(0);
	
}

void AnimatedSprite::Draw(const GameTime& gameTime, 
	SpriteBatch& spriteBatch) {
	
	spriteBatch.Draw(*_texture, _animations[_currentKey].getCurrentFrame(), _position, _color);
	
}

Json::Value AnimatedSprite::toJson() const {
	
	Json::Value spriteJson;
	
	spriteJson["TextureName"] = _resourceName;
	
	Json::Value animationsJson(Json::arrayValue);
	for(auto& it : _animations) {
		
		Json::Value animationJson;
		animationJson["FrameCount"] = it.getFrameCount();
		animationJson["OffSetX"] = it.getFrames()[0].x;
		animationJson["OffSetY"] = it.getFrames()[0].y;
		
		animationsJson.append(animationJson);
		
	}
	
	spriteJson["Animations"] = animationsJson;
	
	return spriteJson;
	
}

void AnimatedSprite::fromJson(Json::Value& spriteJson) {
	
	_resourceName = spriteJson["TextureName"].asString();
	_texture = ContentManager::getTexture(_resourceName);
	
	_animations.clear();
	for(auto& animationJson : spriteJson["Animations"]) {
		
		Animation an(animationJson["FrameCount"].asInt(),
			animationJson["OffSetX"].asInt(),
			animationJson["OffSetY"].asInt());
			
		_animations.push_back(an);
		
	}
	
}
