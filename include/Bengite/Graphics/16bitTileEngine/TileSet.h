#pragma once

#include <array>
#include <memory>
#include <raylib.h>

#include "Graphics/16bitTileEngine/16BitConfig.h"

using namespace std;

namespace bengite { namespace graphics {
	
using Texture2DPtr = shared_ptr<Texture2D>;

class TileSet {
private:

	Texture2DPtr _image;
	array<Rectangle, TileLength * TileLength> _sourceRectangles;

public:

	TileSet(Texture2D* texture);
	TileSet(Texture2DPtr texture);
	
	Texture2DPtr getTexture() const;
	Rectangle getSourceRec(const int& index) const;


protected:
};

}}