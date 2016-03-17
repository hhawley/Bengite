#include "Agriculture/Ground.h"
#include "Input/Mouse.h"

using namespace bengite::gameplay;

Ground::Ground(const Point& cellPosition) 
	: _cellPosition(cellPosition), _currentPlant(nullptr) { 
	
	
	
}

void Ground::Initialize() {
	
	
	
}

void Ground::Update(const GameTime& gameTime) {
	
	if(_currentPlant.get() != nullptr) {
		
		_currentPlant->Update(gameTime);
		
	}
	
	Rectangle posRec = (Rectangle){_cellPosition.x * 64, _cellPosition.y * 64, 64, 64};
	if(Mouse::isTouching(posRec)) {
		
		if(Mouse::LeftClick()) {
			
			if(_currentPlant.get() == nullptr) {
				
				PlantSeed(1);
				
			} else {
				
				if(_currentPlant->isDead()) {
				
					_currentPlant.reset();
					return;
				
				} else if(_currentPlant->canHarvest()) {
				
					Harvest();
				
				}
				
			}
		}
		
		
	}
	
}


void Ground::PlantSeed(const unsigned int& id) {
	
	_currentPlant.reset(new BasePlant(id));
	_currentPlant->Initialize();
	_currentPlant->LoadContent();
	
}

void Ground::Harvest(void) {

	//TODO: add harvest logic!
		
}