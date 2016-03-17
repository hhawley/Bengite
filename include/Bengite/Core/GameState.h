#pragma once

#include <memory>

#include "Core/GameTime.h"

using namespace std;

namespace bengite { namespace core {

class GameState {
private:


public:
	GameState() {}

	virtual void Initialize() = 0;
	virtual void LoadContent() = 0;
	virtual void Update(const GameTime&) = 0;

protected:
	

};

}}