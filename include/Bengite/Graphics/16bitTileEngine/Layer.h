#pragma once

#include <json/json.h>

#include "Core/GameTime.h"
#include "Core/Objects.h"

#include "Graphics/SpriteBatch.h"
#include "Graphics/DrawObject.h"
#include "Graphics/16bitTileEngine/16BitConfig.h"

using namespace bengite::core;

namespace bengite { namespace graphics {

class Layer : public DrawObject {
private:

public:

	Layer(const unsigned int& i) : DrawObject(i) {}
	
	virtual void Update(const GameTime&) = 0;
	virtual void Draw(const GameTime&, SpriteBatch&) = 0;
	
	void setCellPosition(const Point& cellPosition) { _cellPosition = cellPosition; }
	
	Point getCellPosition(void) const { return _cellPosition; }
	Vector2 getPosition(void) const { return 
		(Vector2){
		static_cast<float>(TileLength * _cellPosition.x), 
		static_cast<float>(TileLength * _cellPosition.y)}; }
		
	
	
protected:

	Point _cellPosition;

};

}}