#pragma once 

#include <array>
#include <memory>

#include "Core/GameTime.h"
#include "Core/Objects.h"
#include "Graphics/16bitTileEngine/Chunk.h"

using namespace bengite::graphics;

namespace bengite { namespace core {
	
typedef shared_ptr<Chunk> ChunkPtr;
	
class World {
private:

	
	static const int maxChunks = 9;
	static const int maxTotalChunks = 18;
	array<ChunkPtr, maxChunks> _loadedWorld;
	Point _currentMapCell;
	Point _lastMapCell;

public:

	World();

	void Initialize();
	void LoadContent();
	void Update(const GameTime&);
	
	void Save();
	

protected:

	void loadChunk(const Point&);
	void unloadChunk(const Point&);
	
};
	
}}