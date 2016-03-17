#include "Core/GameStateManager.h"
#include "Graphics/DrawingManager.h"
#include "Graphics/Controls/ControlManager.h"

using namespace bengite::core;
using namespace bengite::graphics;

GameStateMapPtr GameStateManager::_gameStates(new GameStateMap);
GameStatePtr GameStateManager::_currentGameState =  nullptr;


void GameStateManager::add(const string& gameStateName, GameState* gameState) {

	_gameStates->operator[](gameStateName).reset(gameState);

}

void GameStateManager::start(const string& gameStateName) {

	DrawingManager::clear();
	ControlManager::clear();
	
	_currentGameState = _gameStates->operator[](gameStateName);
	_currentGameState->Initialize();
	_currentGameState->LoadContent();

}

void GameStateManager::Update(const GameTime& gameTime) {
	
	if(_currentGameState)
		_currentGameState->Update(gameTime);

}