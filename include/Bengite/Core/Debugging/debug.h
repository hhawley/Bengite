#pragma once

#include <string>
#include <raylib.h>

namespace bengite { namespace core {

enum MessageType {Log,  Warning, Error};
class debug {
private:

	static bool _showCoordinates;
	static bool _showCellCoordinates;
	static bool _showMapCellCoordinates;

public:

	static void showCoordinates(const bool&);
	static void showCellCoordinates(const bool&);
	static void showMapCellCoordinates(const bool&);

	static void log(const std::string&, const MessageType&);

	static void Draw();


};	
	
}}