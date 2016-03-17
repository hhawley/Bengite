#include "Core/GameTime.h"

#include <raylib.h>

using namespace bengite::core;

float GameTime::ElapsedTimeSeconds() const {
	
	return (_totalTime - _lastTotalTime);
	
} 

float GameTime::ElapsedTimeMS() const {
	
	return (_totalTime - _lastTotalTime) * 1000.0f;
	
}

float GameTime::ElapsedTimeMinutes() const { 

	return (_totalTime - _lastTotalTime) / 60.0f;

}

float GameTime::TotalTimeSeconds() const {
	
	return _totalTime;
	
}

float GameTime::TotalTimeMS() const {
	
	return _totalTime * 1000.0f;
	
}

float GameTime::TotalTimeMinutes() const {
	
	return _totalTime / 60.0f;
	
}

GameTime::GameTime() {
	
	_totalTime = _lastTotalTime = 0.0f;
	
}


void GameTime::Update() {
	
	_lastTotalTime = _totalTime;
	_totalTime += GetFrameTime();
	
}
