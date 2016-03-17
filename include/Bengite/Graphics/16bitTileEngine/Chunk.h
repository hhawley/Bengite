#pragma once

#include <array>
#include <vector>
#include <memory>
#include <json/json.h>

#include "Core/Objects.h"
#include "Core/GameTime.h"

#include "Graphics/16bitTileEngine/TileLayer.h"
#include "Graphics/16bitTileEngine/CollisionLayer.h"
#include "Graphics/16bitTileEngine/TopLayer.h"

#include "Gameplay/Interactuable.h"

using namespace std;

using namespace bengite::gameplay;

namespace bengite { namespace graphics {

typedef unique_ptr<Interactuable> InteractuablePtr;
typedef vector<InteractuablePtr> Interactuables;

class Chunk {
private:

	Point _cellPosition;
	TileLayer _currentTileLayer;
	TopLayer _currentTopLayer;
	CollisionLayer _currentCollisionLayer;
	
	Interactuables _interactuables;

public:

	Chunk();
	Chunk(const Point&);

	void LoadContent();
	void Update(const GameTime&);
	
	Point 			getCellPosition() const;
	TileLayer& 		getTileLayer();
	CollisionLayer& getCollisionLayer();
	TopLayer& 		getTopLayer();
	
	void setCellPosition(const Point&);
	
	Json::Value toJson(void) const;
	void fromJson();
	void fromJson(Json::Value&);

protected:
		
};
	
}}