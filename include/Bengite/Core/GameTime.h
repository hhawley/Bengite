#pragma once

namespace bengite { namespace core {
	
class GameTime{
private:
	
	float _lastTotalTime;
	float _totalTime;
	
public:
	
	float ElapsedTimeSeconds() const; 
	float ElapsedTimeMS() const; 
	float ElapsedTimeMinutes() const; 
	
	float TotalTimeSeconds() const; 
	float TotalTimeMS() const; 
	float TotalTimeMinutes() const; 
	
	GameTime();
	
	void Update();
	
protected:
	
};

}}