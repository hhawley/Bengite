#include "Core/Timers/CountDown.h"

using namespace bengite::core;

CountDown::CountDown(const float& startTime) 
	: _isDone(false), _startTime(startTime), _currentTimeLeft(startTime) {
	
	
	
}

void CountDown::Update(const GameTime& gameTime) {
	
	_currentTimeLeft -= gameTime.ElapsedTimeSeconds();
	
	if(_currentTimeLeft <= 0) {
		
		_isDone = true;
		OnDone();
		
	}
	
}

void CountDown::OnDone(void) {
	
	_done.OnDone(true, this);
	
}

void CountDown::Reset(void) {
	
	_isDone = false;
	_currentTimeLeft = _startTime;
	
}

void CountDown::setStartTime(const float& startTime) {
	
	_startTime = startTime;
	Reset();
	
}

void CountDown::setDone(const Funct<int, CountDown>& f) {
	
	_done.setEvent(f);
	
}

bool CountDown::isDone() const {
	
	return _isDone;
	
}

float CountDown::getStartTime() const {
	
	return _startTime;
	
}

float 	CountDown::getCurrentTime() const {
	
	return _currentTimeLeft;
	
}