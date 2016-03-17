/*
*	Name: Game abstract class
*	Description: Abstract class for all the
*	game functions. Run function is meant to
* 	run all the game related functions.
*/

#pragma once

#include <memory>
#include <raylib.h>

#include "Core/GameTime.h"

typedef unsigned int uint32;

using namespace std;

namespace bengite { namespace core {
	
class Game {
private:
	
	shared_ptr<GameTime> _GameTime;
	
public:

#if PLATFORM_ANDROID
	Game(const uint32&, const uint32&, android_app*);
#elif DPLATFORM_DESKTOP
	Game(const uint32&, const uint32&);
#endif
	int run(void);
	
protected:

	uint32 Width;
	uint32 Height;
	
	virtual void Initialize() = 0;
	virtual void LoadContent() = 0;
	
	virtual void Update(const GameTime&) = 0;
	virtual void Draw(const GameTime&) = 0;


	
};

}}