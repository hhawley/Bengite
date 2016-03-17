#include "Core/Components/ComponentsManager.h"

using namespace bengite::core;

shared_ptr<Player> ComponentsManager::CurrentPlayer;
shared_ptr<World> ComponentsManager::CurrentWorld;

void ComponentsManager::Initialize() {
	
	CurrentPlayer->Initialize();
	CurrentWorld->Initialize();
	
}

void ComponentsManager::LoadContent() {
	
	CurrentPlayer->LoadContent();
	CurrentWorld->LoadContent();
	
}

void ComponentsManager::Update(const GameTime&) {
	
	
	
}