#include "Graphics/16bitTileEngine/Camera2D.h"

#include "Graphics/16bitTileEngine/16BitConfig.h"

#include <cmath>

using namespace bengite::core;
using namespace bengite::graphics;


bool Camera2D::_enabled = false;
float Camera2D::_zoom = 1.0f;
Rectangle Camera2D::_viewport;
Vector2 Camera2D::_position;

void Camera2D::Initialize(const Rectangle& viewPortRect) {
	
	_viewport =  viewPortRect;
	_zoom = 1.0f;
	_enabled = true;
	
	
}

void Camera2D::Update(const GameTime& gameTime) {
	
	
	
}

void Camera2D::SnapToPosition(const Vector2& position, const GameTime& gameTime) {
	
	_position.x = position.x - (_viewport.width - TileLength) / 2;
	_position.y = position.y - (_viewport.height - TileLength) / 2;
	
}

void Camera2D::setZoom(const float& zoom) {
	
	_zoom = zoom;
	
}

void Camera2D::setPosition(const Vector2& position) {
	
	_position = position;
	
}

float Camera2D::getZoom(void) {
	
	return _zoom;
	
}

Rectangle Camera2D::getViewPort(void) {
	
	return _viewport;
	
}

Vector2 Camera2D::getPosition(void) {
	
	return _position;
	
}

Vector2 Camera2D::getMiddleScreen(void) {
	
	return (Vector2) {_position.x + (_viewport.width) / 2.0f, 
		_position.y + (_viewport.height) / 2.0f};
	
}

Point Camera2D::getCell(void) {
	
	return (Point){
		static_cast<int>(floor(_position.x / (_zoom * TileLength))), 
		static_cast<int>(floor(_position.y / (_zoom * TileLength)))
	};
	
}

Point Camera2D::getMiddleCell(void) {
	
	return (Point){
		static_cast<int>(floor(getMiddleScreen().x / (_zoom * TileLength))), 
		static_cast<int>(floor(getMiddleScreen().y / (_zoom * TileLength)))
	};
	
}

Point Camera2D::getWorldCell(void) {
	
	return (Point){
		static_cast<int>(floor(_position.x / (_zoom * TileLength * (ChunkLength - 1)))), 
		static_cast<int>(_position.y / (_zoom * TileLength * (ChunkLength - 1)))
	};
	
}

Point Camera2D::getWorldMiddleCell(void) {
	
	return (Point){
		static_cast<int>(floor(getMiddleScreen().x / (_zoom * TileLength * (ChunkLength - 1)))), 
		static_cast<int>(floor(getMiddleScreen().y / (_zoom * TileLength * (ChunkLength - 1))))
	};
	
}

void Camera2D::zoomOut(void) {
	
	_zoom -= 0.25f;
	
}

void Camera2D::zoomIn(void) {
	
	_zoom += 0.25f;
	
}

