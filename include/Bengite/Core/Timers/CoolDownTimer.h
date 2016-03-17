#pragma once

#include "Core/GameTime.h"
#include "Core/Events/Event.h"

namespace bengite { namespace core {
	
class CooldownTimer {
private:

public:

	CooldownTimer(const float&);
	
	void Update(const GameTime&);

	void Reset(void);
	
	void setStartTime(const float&);
	void setCooldownTime(const float&);
	void setDone(const Funct<int, CooldownTimer>&);
	void setCooldownDone(const Funct<int, CooldownTimer>&);
	
	bool 	isDone() const;
	float 	getStartTime() const;
	float 	getCooldownTime() const;
	float 	getCurrentTime() const;
	
	

protected:
		
	void OnDone(void);
	void OnCooldownDone(void);

	bool _isDone;
	float _startTime;
	float _coolDownTime;
	float _currentTimeLeft;
	Event<bool, CooldownTimer> _done;
	Event<bool, CooldownTimer> _cooldownDone;
};

}}