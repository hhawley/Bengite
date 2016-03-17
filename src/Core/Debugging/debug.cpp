#include "Core/Debugging/debug.h"

#include "Graphics/16bitTileEngine/Camera2D.h"

#include <iostream>
#include <sstream>

using namespace bengite::core;
using namespace bengite::graphics;

bool debug::_showCoordinates = true;
bool debug::_showCellCoordinates = true;
bool debug::_showMapCellCoordinates = true;

// bool debug::_showCoordinates = false;
// bool debug::_showCellCoordinates = false;
// bool debug::_showMapCellCoordinates = false;

void debug::showCoordinates(const bool& showCoord) {
	
	_showCoordinates = showCoord;
	
}

void debug::showCellCoordinates(const bool& showCellCoord) {	

	_showCellCoordinates = showCellCoord;
	
}

void debug::showMapCellCoordinates(const bool& showMapCellCoord) {
	
	_showMapCellCoordinates = showMapCellCoord;
	
}

void debug::log(const std::string& message, const MessageType& logKey) {
	
	switch(logKey) {
		case MessageType::Log:
			std::cout << "[LOG]:" << message << std::endl;
			break;

		case MessageType::Warning:
			std::cout << "[WARNING]:" << message << std::endl;
			break;

		case MessageType::Error:
			std::cout << "[ERROR]:" << message << std::endl;
			break;

		default:
			break;
	}
	
	
}

void debug::Draw() {
	
	if(_showCoordinates) {
		
		std::ostringstream coordTxt;
		coordTxt << "Coordinates: (" << Camera2D::getPosition().x << ", " << Camera2D::getPosition().y << ")";
		
		DrawText(coordTxt.str().c_str(), 0, 0, 10, WHITE);
		
	}
	
	if(_showCellCoordinates) {
		
		std::ostringstream coordTxt;
		coordTxt << "Cell Coordinates: (" << Camera2D::getCell().x << ", " << Camera2D::getCell().y << ")";
		
		DrawText(coordTxt.str().c_str(), 0, 10, 10, RED);
		
	}
	
	if(_showMapCellCoordinates) {
		
		std::ostringstream coordTxt;
		coordTxt << "World Cell Coordinates: (" << Camera2D::getWorldCell().x << ", " << Camera2D::getWorldCell().y << ")";
		
		DrawText(coordTxt.str().c_str(), 0, 20, 10, BLUE);
		
	}
}