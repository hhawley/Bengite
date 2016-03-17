#include "Graphics/16bitTileEngine/Tile.h"

using namespace bengite::graphics;

Tile::Tile() 
	: _tile(-1), _tileSet(-1) {
	
	
}

Tile::Tile(const int& tile, const int& tileSet)
	: _tile(tile), _tileSet(tileSet) {
	
}

int Tile::getTileSet(void) const {
	
	return _tileSet;
	
}

int Tile::getIndex(void) const {
	
	return _tile;
	
}

void Tile::setIndex(const int& tile) {
	
	_tile = tile;
	
}
void Tile::setTileSet(const int& tileSet) {
	
	_tileSet = tileSet;
	
}

Json::Value Tile::toJson() const {
	
	Json::Value tileJson;
	
	tileJson["Index"] = _tile;
	tileJson["TileSetIndex"] = _tileSet;
	
	return tileJson;
	
}

void Tile::fromJson(Json::Value& tileJson) {
	
	_tile = tileJson.get("Index", -1).asInt();
	_tileSet = tileJson.get("TileSetIndex", -1).asInt();
	
}