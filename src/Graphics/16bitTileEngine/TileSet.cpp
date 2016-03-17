#include "Graphics/16bitTileEngine/TileSet.h"

using namespace bengite::graphics;

Texture2DPtr TileSet::getTexture() const {
	
	return _image;
	
}

Rectangle TileSet::getSourceRec(const int& index) const {
	
	return _sourceRectangles[index];
	
}

TileSet::TileSet(Texture2D* texture) 
	: _image(texture) {
	
	for(int y = 0; y < TileSetLengthTiles; y++) {
		for(int x = 0; x < TileSetLengthTiles; x++)
			_sourceRectangles[x + y * TileSetLengthTiles] = (Rectangle) 
				{x * TileLength, y * TileLength, TileLength, TileLength};
	}
	
}

TileSet::TileSet(Texture2DPtr texture) 
	: _image(texture) {
	
	for(int y = 0; y < TileSetLengthTiles; y++) {
		for(int x = 0; x < TileSetLengthTiles; x++)
			_sourceRectangles[x + y * TileSetLengthTiles] = (Rectangle) 
				{x * TileLength, y * TileLength, TileLength, TileLength};
	}
	
}
	