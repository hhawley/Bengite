#pragma once

#include "Core/GameTime.h"
#include "Core/Events/Event.h"

namespace bengite { namespace core {
	
class CountDown {
private:

public:
	CountDown(const float&);
	
	void Update(const GameTime&);
	
	void Reset(void);
	
	void setStartTime(const float&);
	void setDone(const Funct<int, CountDown>&);
	
	bool 	isDone() const;
	float 	getStartTime() const;
	float 	getCurrentTime() const;
	

protected:
	
	void OnDone(void);

	bool _isDone;
	float _startTime;
	float _currentTimeLeft;
	Event<bool, CountDown> _done;
};

}}
	
	

