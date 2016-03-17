#pragma once

#include <memory>
#include <json/json.h>
#include <functional>

#include "Core/GameTime.h"
#include "Core/Objects.h"
#include "Core/Events/Event.h"
#include "Graphics/16bitTileEngine/Tile.h"

using namespace std;
using namespace bengite::core;
using namespace bengite::graphics;

namespace bengite { namespace gameplay {
	
class Interactuable {	
private:
	
	
public:

	enum class TilePosition {Floor, Base, Top};
	Point 	getChunkPosition(void) const;
	Point 	getChunkCellPosition(void) const;
	Vector2 getPosition(void) const;
	
	void setChunkCellPosition(const Point&);
	void setLeftClick(const Funct<int, Interactuable>&);

	Interactuable();
	Interactuable(const Point&, const Point&, const Tile&);
	Interactuable(const Point&, const Point&, const int& tileSetIndex, const int& tileIndex);

	virtual void Update(const GameTime&);
	
	virtual Json::Value toJson(void) = 0;
	virtual void fromJson(Json::Value&) = 0;

protected:

	//shared_ptr<Chunk> _parentChunk;
	Point _chunkPosition;
	Point _chunkCellPosition;
	Tile _tile;
	TilePosition _tilePos;

	Event<int, Interactuable> _leftClick;
	void OnLeftClick(void);
	
};
	
}}
