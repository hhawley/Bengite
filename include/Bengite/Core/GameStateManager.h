#pragma once

#include <map>
#include <memory>
#include <string>

#include "Core/GameState.h"
#include "Core/GameTime.h"

using namespace std;
using namespace bengite::core;

typedef shared_ptr<GameState> GameStatePtr;
typedef map<string, GameStatePtr> GameStateMap;
typedef unique_ptr<GameStateMap> GameStateMapPtr;

namespace bengite { namespace core {

class GameStateManager {
private:

	static GameStateMapPtr _gameStates;
	static GameStatePtr _currentGameState;

public:

	static void add(const string&, GameState*);
	static void start(const string&);

	static void Update(const GameTime&);

protected:
	

};

}}