#include "Core/Timers/Timer.h"

using namespace bengite::core;

Timer::Timer(const float& startTime) 
	: _isDone(false), _startTime(startTime), _currentTimeLeft(startTime) {
	
	
	
}

void Timer::Update(const GameTime& gameTime) {
	
	_currentTimeLeft -= gameTime.ElapsedTimeSeconds();
	
	if(_currentTimeLeft <= 0) {
		
		_isDone = true;
		OnDone();
		Reset();
		
	}
	
}

void Timer::OnDone(void) {
	
	_done.OnDone(true, this);
	
}

void Timer::Reset(void) {
	
	_isDone = false;
	_currentTimeLeft = _startTime;
	
}

void Timer::setStartTime(const float& startTime) {
	
	_startTime = startTime;
	Reset();
	
}

void Timer::setDone(const Funct<int, Timer>& f) {
	
	_done.setEvent(f);
	
}

bool Timer::isDone() const {
	
	return _isDone;
	
}

float Timer::getStartTime() const {
	
	return _startTime;
	
}

float Timer::getCurrentTime() const {
	
	return _currentTimeLeft;
	
}