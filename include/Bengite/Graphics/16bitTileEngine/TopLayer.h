#pragma once 

#include <memory>
#include <array>
#include <json/json.h>

#include "Core/GameTime.h"

#include "Graphics/SpriteBatch.h"
#include "Graphics/16bitTileEngine/16BitConfig.h"
#include "Graphics/16bitTileEngine/Layer.h"
#include "Graphics/16bitTileEngine/Tile.h"
#include "Graphics/16bitTileEngine/TileSet.h"

using namespace std;
using namespace bengite::core;

namespace bengite { namespace graphics {
	
class TopLayer : public Layer {
private:

	array<Tile, ChunkLength * ChunkLength> _tiles;
	shared_ptr<TileSet> _tileSets;

public:

	TopLayer();
	TopLayer(const array<Tile, ChunkLength * ChunkLength>& tiles);
	TopLayer(const shared_ptr<TileSet>& tileSets);
	TopLayer(const array<Tile, ChunkLength * ChunkLength>& tiles, 
		const shared_ptr<TileSet>& tileSets);
	
	void Update(const GameTime&);
	void Draw(const GameTime&, SpriteBatch&);

	Tile getTile(const int&, const int&);
	
	void setTile(const int&, const int&, const Tile&);
	void setTile(const int&, const int&, const int&, const int&);
	void setTiles(const array<Tile, ChunkLength * ChunkLength>& tiles);
	
	Json::Value toJson(void) const;
	void fromJson(Json::Value&);
	
protected:

};

}}