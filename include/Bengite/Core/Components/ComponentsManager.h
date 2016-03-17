#pragma once

#include <memory>

#include "Core/GameTime.h"
#include "Player.h"
#include "World.h"

using namespace std;

namespace bengite { namespace core {
	
class ComponentsManager {
private:

public:

	static shared_ptr<Player> CurrentPlayer;
	static shared_ptr<World> CurrentWorld;
	
	static void Initialize();
	static void LoadContent();
	static void Update(const GameTime&);
	

protected:
	
};
	
}}