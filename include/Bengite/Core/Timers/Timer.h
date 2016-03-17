#pragma once

#include "Core/GameTime.h"
#include "Core/Events/Event.h"

namespace bengite { namespace core {
	
class Timer {
private:

public:
	Timer(const float&);
	
	void Update(const GameTime&);
	
	void Reset(void);
	
	void setStartTime(const float&);
	void setDone(const Funct<int, Timer>&);
	
	bool 	isDone() const;
	float 	getStartTime() const;
	float 	getCurrentTime() const;

protected:

	void OnDone(void);

	bool _isDone;
	float _startTime;
	float _currentTimeLeft;
	Event<bool, Timer> _done;
};

}}