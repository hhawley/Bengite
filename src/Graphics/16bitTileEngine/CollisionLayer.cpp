#include "Graphics/16bitTileEngine/CollisionLayer.h"

#include "Content/ContentManager.h"

#include "Graphics/16bitTileEngine/Camera2D.h"

#include <algorithm>
#include <raylib.h>

using namespace bengite::graphics;
using namespace bengite::content;

CollisionLayer::CollisionLayer()
	: Layer(1), _tileSets(ContentManager::getTileSet()) {
	
	
	
}

CollisionLayer::CollisionLayer(const array<Tile, ChunkLength * ChunkLength>& tiles) 
	: Layer(1), _tiles(tiles), _tileSets(ContentManager::getTileSet()) {
	
	
	
}

CollisionLayer::CollisionLayer(const array<Tile, ChunkLength * ChunkLength>& tiles, 
		const shared_ptr<TileSet>& tileSets)
	: Layer(1), _tiles(tiles), _tileSets(tileSets) {
		
		
}

CollisionLayer::CollisionLayer(const shared_ptr<TileSet>& tileSets) 
	: Layer(1), _tileSets(tileSets) {
	
	
}

void CollisionLayer::Update(const GameTime&) {
	
	
	
}

void CollisionLayer::Draw(const GameTime& gameTime, SpriteBatch& spriteBatch) {
	
	Point cameraPt = Camera2D::getCell();
	
	Point viewPt = Point::toCell((Vector2) {
		Camera2D::getPosition().x + Camera2D::getViewPort().width,
		Camera2D::getPosition().y + Camera2D::getViewPort().height
	});
	
	Point min = (Point) {
		std::max((ChunkLength - 1) * _cellPosition.x, cameraPt.x - 1),
		std::max((ChunkLength - 1) * _cellPosition.y , cameraPt.y - 1)
	};
	Point max = (Point) {
		std::min(viewPt.x + 1, (ChunkLength - 1) * (_cellPosition.x + 1)),
		std::min(viewPt.y + 1, (ChunkLength - 1) * (_cellPosition.y + 1))
	};

	// if(max.x <= 0 || max.y <= 0 || min.x >= ChunkLength || min.y >= ChunkLength)
	// return;
	
	Tile tile;
	Rectangle destination = (Rectangle) {0, 0, TileLength, TileLength};
	
	for(register int y = min.y; y < max.y; y++) {
		
		for(register int x = min.x; x < max.x; x++) {
			
			tile = getTile(x - (ChunkLength - 1) * _cellPosition.x, y - (ChunkLength - 1) * _cellPosition.y);
			
			
			
			if(tile.getTileSet() == -1 || tile.getIndex() == -1)
				continue;
			
			destination.x = x * TileLength;
			destination.y = y * TileLength;
			
			spriteBatch.Draw(
				*((_tileSets.get() + tile.getTileSet())->getTexture()),
				(_tileSets.get() + tile.getTileSet())->getSourceRec(tile.getIndex()),
				destination, (Vector2){0.0f, 0.0f}, 0.0f, WHITE);
		}
		
	}
	
	
}

bool CollisionLayer::CheckForCollision(const Rectangle& rec) {
	
	//TODO: not implemented
	return false;
	
}

bool CollisionLayer::CheckForCollision(const Rectangle& rec, const Vector2& pos) {
	
	int cameraZoomInt = static_cast<int>(Camera2D::getZoom());
	Point cameraPt = Point::toCell(pos);
	
	Point min = (Point) {
		std::max(0, cameraPt.x - 2),
		std::max(0, cameraPt.y - 2)
	};
	Point max = (Point) {
		std::min(cameraPt.x + 2, ChunkLength),
		std::min(cameraPt.y + 2, ChunkLength)
	};
	
	if(max.x <= 0 || max.y <= 0 || min.x >= ChunkLength || min.y >= ChunkLength)
		return false;
	
	Point posZoom = (Point) { 
		static_cast<int>(pos.x * cameraZoomInt), 
		static_cast<int>(pos.y * cameraZoomInt)
	};
	
	Rectangle destination = (Rectangle) {0, 0, TileLength, TileLength};
	Rectangle entityRec = (Rectangle) {posZoom.x, posZoom.y, rec.width, rec.height};
	
	Tile tile;
	bool isCollision = false;
	
	for(register int y = min.y; y < max.y; y++) {
		
		for(register int x = min.x; x < max.x; x++) {
			
			tile = getTile(x, y);
			
			if(tile.getTileSet() == -1 || tile.getIndex() == -1)
				continue;
			
			destination.x = (x + ChunkLength * _cellPosition.x) * TileLength * cameraZoomInt - Camera2D::getPosition().x;
			destination.y = (y + ChunkLength * _cellPosition.y) * TileLength * cameraZoomInt - Camera2D::getPosition().x;
			
			isCollision |= CheckCollisionRecs(entityRec, destination);
			
		}
		
	}
	
	return isCollision;
	
}

Tile CollisionLayer::getTile(const int& x, const int& y) {
	
	return _tiles[y + x * ChunkLength];
	
}

void CollisionLayer::setTile(const int& x, const int& y, 
								const Tile& tile) {
	
	_tiles[y + x * ChunkLength] = tile;
	
}

void CollisionLayer::setTile(const int& x, const int& y, 
								const int& index, const int& tileSet) {
									
	_tiles[y + x * ChunkLength].setIndex(index);
	_tiles[y + x * ChunkLength].setTileSet(tileSet);								
									
}

void CollisionLayer::setTiles(const array<Tile, ChunkLength * ChunkLength>& tiles) {
	
	_tiles = tiles;
	
}

Json::Value CollisionLayer::toJson(void) const {
	
	Json::Value layerJson(Json::arrayValue);
	for(int x = 0; x < ChunkLength; x++) {
		for(int y = 0; y < ChunkLength; y++) {
			
			layerJson.append(_tiles[y + x * ChunkLength].toJson());
			
		}
		
	}
	
	return layerJson;
	
}

void CollisionLayer::fromJson(Json::Value& layerJson) {
	
	for(int x = 0; x < ChunkLength; x++) {
		
		for(int y = 0; y < ChunkLength; y++) {
			
			_tiles[y + x * ChunkLength].fromJson(layerJson[y + x * ChunkLength]);
			
		}
		
	}
	
}