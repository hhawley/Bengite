#pragma once

#include <functional>
#include <memory>

using namespace std;

namespace bengite { namespace core {
	
// template <typename eventArgs, typename object>
// using FunctPtr = shared_ptr<function<void(eventArgs, object*)>>; 

template <typename eventArgs, typename object>
using Funct = function<void(eventArgs, object*)>; 


template <typename eventArgs, typename object>
class Event{
private:
	
public:
	Event();
	
	void OnDone(const eventArgs&, object*);
	
	void setEvent(const Funct<eventArgs, object>&);
	Funct<eventArgs, object> getEvent(void);
	
	void operator=(const Funct<eventArgs, object>&);
	
protected:
	Funct<eventArgs, object> _toDo;
};

template <typename eventArgs, typename object>
Event<eventArgs, object>::Event() {}

template <typename eventArgs, typename object>
void Event<eventArgs, object>::OnDone(const eventArgs& e, object* sender) {
	
	if(_toDo)
		_toDo(e, sender);
	
}

template <typename eventArgs, typename object>
void Event<eventArgs, object>::setEvent(const Funct<eventArgs, object>& f) {
	
	_toDo = f;
	
}

template <typename eventArgs, typename object>
Funct<eventArgs, object> Event<eventArgs, object>::getEvent(void) {
	
	return _toDo;
	
}

template <typename eventArgs, typename object>
void Event<eventArgs, object>::operator=(const Funct<eventArgs, object>& f) {
	
	_toDo = f;
	
}

}}