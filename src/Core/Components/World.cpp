#include "Core/Components/World.h"

#include "Graphics/16bitTileEngine/Camera2D.h"
#include "json/jsonStream.h"

#include <json/json.h>
#include <iostream>

using namespace bengite::core;
using namespace bengite::content;

World::World() {
	

	
}

void World::Initialize() {

	//Checks if world exists and creates it.
	Json::Value mainChunk = JsonStream::OpenJson("Content\\Map\\0_0.json");

	for(int y = 0; y < 3; y++) {
		for(int x = 0; x < 3; x++) {
			_loadedWorld[x + y * 3].reset(new Chunk((Point){x - 1, 1 - y}));
		}
	}

	if(mainChunk.isNull()) {

		array<Tile, 8 * 8> tiles;

		for(auto& v : tiles)
			v = (Tile){1, 0};

		for(auto& chunk : _loadedWorld)
			chunk->getTileLayer().setTiles(tiles);

		for(int i = 1; i < 7; i++)
			for(int j = 1; j < 7; j++)
				tiles[j + 8 * i] = (Tile){0,0};


		_loadedWorld[4]->getTileLayer().setTiles(tiles);

		Save();

	} else {

		for(const auto& chunk : _loadedWorld)
			loadChunk(chunk->getCellPosition());

	}

}

void World::LoadContent() {

	for(const auto& chunk : _loadedWorld) {

		if(chunk.get() != nullptr) {
			chunk->LoadContent();
		}

	}

}

/// Updates the current chunks and checks if player has moved
void World::Update(const GameTime& gameTime) {

	_lastMapCell = _currentMapCell;
	_currentMapCell = Camera2D::getWorldMiddleCell();

	/*Checks for new cells that have to be loaded*/
	if(_currentMapCell != _lastMapCell) {

		for(int y = 0; y < 3; y++) {

			for(int x = 0; x < 3; x++) {

				loadChunk(_currentMapCell + (Point){x - 1, 1 - y});

			}

		}

		Save();

	}

	for(const auto& chunk : _loadedWorld) {

		chunk->Update(gameTime);

	}


}

///Saves all loaded chunks
///
void World::Save() {

	for(const auto& chunk : _loadedWorld) {

		if(chunk.get() != nullptr) {

			auto value = chunk->toJson();

			ostringstream path;

			path << "Content\\Map\\" << chunk->getCellPosition().x << "_" << chunk->getCellPosition().y << ".json";

			JsonStream::SaveJson(path.str(), value);

		}

	}

}

/// Loads the chunk is map cell position.
/// TODO: can be improved greatly
void World::loadChunk(const Point& cellPosition) {


	ostringstream path;
	path << "Content\\Map\\" << cellPosition.x << "_" << cellPosition.y << ".json";
	Json::Value loadChunk = JsonStream::OpenJson(path.str());

	Point cellDif = cellPosition - _currentMapCell;
	cellDif.x ++;
	cellDif.y = 1 - cellDif.y;
	const int index = cellDif.x + cellDif.y * 3;
	std::cout << cellPosition.x << ", " << cellPosition.y <<  std::endl;

	if(loadChunk.isNull()) {

		array<Tile, 8 * 8> tiles;

		for(auto& v : tiles)
			v = (Tile){1, 0};

		_loadedWorld[index]->setCellPosition(cellPosition);
		_loadedWorld[index]->getTileLayer().setTiles(tiles);

		std::cout << "Created new chunk" << std::endl;

	} else {

		_loadedWorld[index]->setCellPosition(cellPosition);
		_loadedWorld[index]->fromJson(loadChunk);

		std::cout << "Loaded Chunk" << std::endl;

	}

}

