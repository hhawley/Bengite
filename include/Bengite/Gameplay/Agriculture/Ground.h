#pragma once

#include <memory>

#include "GameTime.h"
#include "SpriteBatch.h"
#include "BasePlant.h"
#include "Objects.h"

using namespace std;
using namespace bengite::core;
using namespace bengite::graphics;

namespace bengite { namespace gameplay {
	
class Ground {
private:


public:

	Ground(const Point&);
	
	void Initialize();
	void Update(const GameTime&);
	
	void PlantSeed(const unsigned int&);
	void Harvest(void);
	

protected:
	
	Point _cellPosition;
	unique_ptr<BasePlant> _currentPlant;
	
};
	
}}