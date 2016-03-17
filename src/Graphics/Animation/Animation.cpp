#include "Graphics/Animation/Animation.h"

#include "Graphics/16bitTileEngine/16BitConfig.h"

using namespace bengite::graphics;

vector<Rectangle> Animation::getFrames(void) const {
	
	return _frames;
	
}

int Animation::getFrameCount(void) const {
	
	return _frameCount;
	
}

int Animation::getFPS(void) const {
	
	return _fps;
	
}

Rectangle Animation::getCurrentFrame(void) const {
	
	return _frames[_currentFrame];
	
}

void Animation::setFPS(const int& fps) {
	
	_fps = fps < 1 ? 1 : fps > 60 ? 60 : fps;
	_frameLength = _frameCount / static_cast<float>(_fps);
	
}

void Animation::setCurrentFrame(const int& frame) {
	
	_currentFrame = frame < 0 ? 0 : frame > _frameCount ? _frameCount - 1 : frame;
	
}

Animation::Animation(void) 
	: _frameCount(3), _frames(3, (Rectangle){0,0,0,0}),
	  _fps(10), _frameLength(3 / static_cast<float>(_fps)) {
	
	for(int i = 0; i < _frameCount; i++) {
		
		_frames[i] = (Rectangle){(TileLength * i), 0, TileLength, TileLength};
		
	}
	
	Reset();
	
}

Animation::Animation(const int& frameCount, const int& offSetX, 
	const int& offSetY) 
	: _frameCount(frameCount), _frames(frameCount, (Rectangle){0,0,0,0}),
	  _fps(10), _frameLength(frameCount / static_cast<float>(_fps)) {
	
	
	for(int i = 0; i < _frameCount; i++) {
		
		_frames[i] = (Rectangle){offSetX + (TileLength * i), offSetY, TileLength, TileLength};
		
	}
	
	Reset();
	
}

void Animation::Update(const GameTime& gameTime) {
	
	_frameTime += gameTime.ElapsedTimeSeconds();
	
	if(_frameTime >= _frameLength) {
		
		_frameTime = 0;
		_currentFrame = _currentFrame >= _frameCount - 1 ? 1 : _currentFrame + 1;
		
	}
	
}

void Animation::Reset(void) {
	
	_currentFrame = 0;
	_frameTime = 0;
	
}
