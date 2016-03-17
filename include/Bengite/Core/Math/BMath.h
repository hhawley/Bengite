/*
*	Name: Static Math
*	Description: Math functions for raylib
*	structs and some num-string related functions.
*/

#pragma once

#include <raylib.h>
#include <string>

namespace bengite { namespace core {
	
class Math {
public:
	
	/*Vector2 Functions*/
	static float Length(const Vector2& v);
	static Vector2 unitVector(const Vector2& v);
	static float dotProduct(const Vector2&, const Vector2&);
	
	/*Other Math functions*/
	static float roundf(const float&, const int&);
	static double roundd(const double&, const int&);
	
	/*Numbers to strings*/
	static std::string ftostr(const float&);
};
	
	
}}