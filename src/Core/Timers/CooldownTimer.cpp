#include "Core/Timers/CooldownTimer.h"

using namespace bengite::core;

CooldownTimer::CooldownTimer(const float& startTime) 
	: _isDone(false), _startTime(startTime), _currentTimeLeft(startTime) {
	
	
	
}

void CooldownTimer::Update(const GameTime& gameTime) {
	
	_currentTimeLeft -= gameTime.ElapsedTimeSeconds();
	
	if(_currentTimeLeft <= 0) {
		
		if(!_isDone) OnDone();
		
		_isDone = true;
		
		if(_currentTimeLeft <= -_coolDownTime) {
			
			OnCooldownDone();
			Reset();
			
		}
		
	}
	
}

void CooldownTimer::OnDone(void) {
	
	_done.OnDone(true, this);
	
}

void CooldownTimer::OnCooldownDone(void) {
	
	_cooldownDone.OnDone(true, this);
	
}

void CooldownTimer::Reset(void) {
	
	_isDone = false;
	_currentTimeLeft = _startTime;
	
}

void CooldownTimer::setCooldownTime(const float& cooldownTime) {
	
	_coolDownTime = cooldownTime;
	Reset();
	
}

void CooldownTimer::setStartTime(const float& startTime) {
	
	_startTime = startTime;
	Reset();
	
}

void CooldownTimer::setDone(const Funct<int, CooldownTimer>& f) {
	
	_done.setEvent(f);
	
}

void CooldownTimer::setCooldownDone(const Funct<int, CooldownTimer>& f) {
	
	_cooldownDone.setEvent(f);
	
}

bool CooldownTimer::isDone() const {
	
	return _isDone;
	
}

float CooldownTimer::getStartTime() const {
	
	return _startTime;
	
}

float CooldownTimer::getCooldownTime() const {
	
	return _coolDownTime;
	
}

float CooldownTimer::getCurrentTime() const {
	
	return _currentTimeLeft;
	
}