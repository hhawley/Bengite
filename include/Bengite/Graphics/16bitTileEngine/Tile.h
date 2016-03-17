#pragma once

#include <json/json.h>

namespace bengite { namespace graphics {
	
class Tile {
private:

public:

	Tile();
	Tile(const int&, const int&);
	
	int getTileSet(void) const;
	int getIndex(void) const;
	
	void setIndex(const int&);
	void setTileSet(const int&);
	
	Json::Value toJson() const;
	void fromJson(Json::Value&);
	
protected:

	int _tile;
	int _tileSet;
	
};

}}