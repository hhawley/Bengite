#include "Graphics/16bitTileEngine/Chunk.h"

#include "Graphics/DrawingManager.h"

#include "json/jsonStream.h"

#include <string>

using namespace bengite::core;
using namespace bengite::content;
using namespace bengite::graphics;

Chunk::Chunk() :
	_cellPosition((Point){1e8, 1e8}),
	_currentTileLayer(),
	_currentTopLayer(),
	_currentCollisionLayer() {



}

Chunk::Chunk(const Point& cellPosition) :
	_cellPosition(cellPosition),
	_currentTileLayer(),
	_currentTopLayer(),
	_currentCollisionLayer() {

	_currentTileLayer.setCellPosition(_cellPosition);
	_currentCollisionLayer.setCellPosition(_cellPosition);
	_currentTopLayer.setCellPosition(_cellPosition);

}

void Chunk::LoadContent() {

	DrawingManager::addDraw(_currentTileLayer);
	DrawingManager::addDraw(_currentTopLayer);
	DrawingManager::addDraw(_currentCollisionLayer);

}

void Chunk::Update(const GameTime& gameTime) {

	_currentTileLayer.Update(gameTime);
	_currentTopLayer.Update(gameTime);
	_currentCollisionLayer.Update(gameTime);

}

Point Chunk::getCellPosition() const {

	return _cellPosition;

}

TileLayer& Chunk::getTileLayer()  {

	return _currentTileLayer;

}

CollisionLayer& Chunk::getCollisionLayer() {

	return _currentCollisionLayer;

}

TopLayer& Chunk::getTopLayer() {

	return _currentTopLayer;

}

void Chunk::setCellPosition(const Point& cellPosition) {

	_cellPosition = cellPosition;
	_currentTileLayer.setCellPosition(cellPosition);
	_currentCollisionLayer.setCellPosition(cellPosition);
	_currentTopLayer.setCellPosition(cellPosition);

}

Json::Value Chunk::toJson(void) const {

	Json::Value chunkJson;
	Json::Value pointJson(Json::arrayValue);
	pointJson.append(_cellPosition.x);
	pointJson.append(_cellPosition.y);

	// chunkJson["Chunk"]["CellPosition"] = pointJson;

	chunkJson["Class"] = "Chunk";
	chunkJson["TileLayer"] = _currentTileLayer.toJson();
	chunkJson["CollisionLayer"] = _currentCollisionLayer.toJson();
	chunkJson["TopLayer"] = _currentTopLayer.toJson();

	return chunkJson;

}

void Chunk::fromJson(Json::Value& chunkJson) {

	_currentTileLayer.fromJson(chunkJson["TileLayer"]);
	_currentCollisionLayer.fromJson(chunkJson["CollisionLayer"]);
	_currentTopLayer.fromJson(chunkJson["TopLayer"]);

}
