#pragma once

#include "GameTime.h"
#include "SpriteBatch.h"
#include "Timers/Timer.h"

#include "Graphics/Animation/AnimatedSprite.h"

using namespace bengite::core;
using namespace bengite::graphics;

namespace bengite { namespace gameplay {
	
class BasePlant {
private:


public:

	BasePlant(const unsigned int&);

	virtual void Initialize();
	virtual void LoadContent();
	virtual void Update(const GameTime&);
	virtual void Draw(const GameTime&, SpriteBatch&);
	
	bool isDiseased() const;
	bool canHarvest() const;
	bool isDead() const;
	
protected:

	AnimatedSprite _topSprite;
	AnimatedSprite _bottomSprite;
	
	unsigned int _type;
	unsigned int _phases;
	unsigned int _currentPhase;
	float _growTime;
	float _growTimeMultiplier;
	Timer _growTimer;
	
	bool _isDiseased;
	float _chanceToDisease;
	
	float _maxWater;
	float _currentWaterLevel;
	
	unsigned int _harvestItems;
	unsigned int _harvestSeeds;
	bool _canHarvest;
	
	bool _isDead;
	
};
	
}}