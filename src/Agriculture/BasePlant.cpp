#include "Agriculture/BasePlant.h"
#include "Core/RNG.h"
#include "Graphics/DrawingManager.h"
#include "Content/ContentManager.h"

using namespace bengite::gameplay;
using namespace bengite::content;

/* Test Plant
unsigned int _type = 0
float _phases = 3
float _growTime =  2 mins
float _growTimeMultiplier =  1.0x

bool _isDiseased = false
float _chanceToDisease =  50%

float _maxWater =  1 litter

unsigned int harvestItems = 1 food
harvestSeeds = 2 seeds

bool _isDead = false
*/
enum BasePlantCycles {Seedling, Youngling, Harvest, Dead};

BasePlant::BasePlant(const unsigned int& id = 0) 
	:
	_topSprite(2), _bottomSprite(1),
	_type(id), _phases(4), _currentPhase(0),
	_growTime(120), _growTimeMultiplier(1.0f),
	_growTimer(_growTime / _phases), 
	_isDiseased(false), _chanceToDisease(50), 
	_maxWater(1), _currentWaterLevel(0), 
	_harvestItems(1), _harvestSeeds(2), _canHarvest(false),
	_isDead(false) {
	
	
	
}

void BasePlant::Initialize() {
	
	_growTimer.setDone([&](bool e, Timer* sender){
		
		if(_isDiseased)
			_isDead = true;
		else {
			
			if(RNG::getFloat() <= _chanceToDisease) {
				
				_isDiseased = true;
				_canHarvest = false;
				return;
				
			}
			
			if(_currentPhase == _phases) {
				
				_isDead = true;
				_canHarvest = false;
				return;
				
			}
		
			_currentPhase = _currentPhase < _phases ? 
				_currentPhase + 1 : _phases;
				
			if(_currentPhase == _phases - 1)
				_canHarvest = true;
			
			_bottomSprite.setCurrentAnimation(_currentPhase);
			
			if(_currentPhase > 1) {
				
				_topSprite.setCurrentAnimation(_currentPhase);
				
			}

			
		}
		
	});
	
}

void BasePlant::LoadContent() {
	
	Animation t_anim3(3, 0, 128*2);
	AnimationDict topAnimations(5, t_anim3);
	
	Animation t_anim4(3, 0, 192*2);
	topAnimations[BasePlantCycles::Harvest] = t_anim4;

	_topSprite.LoadContent(ContentManager::getTexture("basePlant.png"), topAnimations);
	_topSprite.setAnimating(true);
	
	Animation b_anim1(3, 0, 64);
	AnimationDict bottomAnimations(5, b_anim1);
	
	Animation b_anim2(3, 0, 64*2 + 64);
	bottomAnimations[BasePlantCycles::Youngling] = b_anim2;
		
	Animation b_anim3(3, 0, 128*2 + 64);
	bottomAnimations[BasePlantCycles::Harvest] = b_anim3;
	
	Animation b_anim4(3, 0, 192*2 + 64);
	bottomAnimations[BasePlantCycles::Dead] = b_anim4;
		
	_bottomSprite.LoadContent(ContentManager::getTexture("basePlant.png"), bottomAnimations);
	_bottomSprite.setAnimating(true);
	
	DrawingManager::addDraw(_bottomSprite);
	DrawingManager::addDraw(_topSprite);
	
}

void BasePlant::Update(const GameTime& gameTime) {
	
	if(!_isDead)
		_growTimer.Update(gameTime);
	
}

void BasePlant::Draw(const GameTime& gameTime, 
	SpriteBatch& spriteBatch) {
	
	
	
}
