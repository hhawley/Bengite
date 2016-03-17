#include "Gameplay/Interactuable.h"

#include "Core/Input/Mouse.h"
#include "Core/Math/BMath.h"
#include "Core/Components/ComponentsManager.h"

using namespace bengite::gameplay;

Point Interactuable::getChunkPosition(void) const {

	return _chunkPosition;

}

Point Interactuable::getChunkCellPosition(void) const {
	
	return _chunkCellPosition;
	
}

Vector2 Interactuable::getPosition(void) const {
	
	return (Vector2){
		static_cast<float>(_chunkCellPosition.x * TileLength + _chunkPosition.x * ChunkLength),
		static_cast<float>(_chunkCellPosition.y * TileLength + _chunkPosition.y * ChunkLength)};
	
}

void Interactuable::setChunkCellPosition(const Point& cellPt) {
	
	_chunkCellPosition = cellPt;
	
}

void Interactuable::setLeftClick(const Funct<int, Interactuable>& f) {
	
	_leftClick.setEvent(f);
	
}

Interactuable::Interactuable() {

} 

Interactuable::Interactuable(const Point& chunkPosition, const Point& cellPosition, const Tile& tile) 
	: _chunkPosition(chunkPosition), _chunkCellPosition(cellPosition), _tile(tile) {
	
	
	
}

Interactuable::Interactuable(const Point& chunkPosition, const Point& cellPosition, const int& tileSetIndex, const int& tileIndex) 
	: _chunkPosition(chunkPosition), _chunkCellPosition(cellPosition), _tile(tileSetIndex, tileIndex) {



}

void Interactuable::Update(const GameTime& gameTime) {
	
	const Point pos = (Point){
		_chunkCellPosition.x * TileLength + _chunkPosition.x * ChunkLength,
		_chunkCellPosition.y * TileLength + _chunkPosition.y * ChunkLength};
	const Rectangle tileRec = (Rectangle){pos.x, pos.y, TileLength, TileLength};
	

#if PLATFORM_DESKTOP
	if(Mouse::isTouching(tileRec)) {
		
		auto pPos = ComponentsManager::CurrentPlayer->getPosition();
		pPos.x = pPos.x - pos.x;
		pPos.y = pPos.y - pos.y;
	
		float length = Math::Length(pPos);
		
		if(Mouse::LeftClick() && length < TileLength) {
			
			OnLeftClick();
			
		} 
		
	}
#endif
	
}

void Interactuable::OnLeftClick(void) {
	
	_leftClick.OnDone(1, this);
	
}
