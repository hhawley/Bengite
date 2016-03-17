#include "Core/Game.h"

#include "Core/RNG.h"
#include "Core/Debugging/debug.h"
#include "Core/GameStateManager.h"

#include "Graphics/Controls/ControlManager.h"

#include "Content/ContentManager.h"

#include <raylib.h>
#include <iostream>

using namespace bengite::core;
using namespace bengite::content;

#if PLATFORM_ANDROID

Game::Game(const uint32&, const uint32&, android_app* app) {

	InitWindow(Width, Height, app);

}


#elif DPLATFORM_DESKTOP
Game::Game(const uint32& w = 800, const uint32& h = 600) :
			_GameTime(new GameTime),
			Width(w), Height(h)  {
	
	InitWindow(Width, Height, "A Game");
	
}
#endif

int Game::run() {
	try {
		RNG::Initialize();
		ContentManager::Initialize();
		this->Initialize();
		this->LoadContent();
		debug::log("Finished loading.", MessageType::Log);
		
	} catch (...) {

		std::cout << "Failed at initializing or loading content" << std::endl;
		return 2;
		
	}
	
	try {
		
		while(!WindowShouldClose()) {
			
			
			this->Update(*_GameTime);
			GameStateManager::Update(*_GameTime);
			ControlManager::Update(*_GameTime);

			this->Draw(*_GameTime);
			
			_GameTime->Update();
			
		}	
		
		
	} catch (...) {

		std::cout << "Error in game logic" << std::endl;
		return 1;
		
	}
	
	ControlManager::clear();
	ContentManager::Unload();
	CloseWindow();
	
	return 0;
}
