#pragma once

#include <raylib.h>
#include <json/json.h>

namespace bengite { namespace core {
	
struct Point {
	
	int x;
	int y;
	
	Point() : x(0), y(0) {}
	Point(const int& X, const int& Y) : x(X), y(Y) {}
	
	Point operator+(const Point&) const;
	Point operator-(const Point&) const;
	
	bool operator!=(const Point&) const;
	bool operator==(const Point&) const;
	
	static Point toCell(const Vector2& v);
	static Point toCell(const Vector2& v, const float& zoom);
	
};

struct raylibJson {
	static Json::Value vector2ToJson(const Vector2&);
	static Json::Value vector3ToJson(const Vector3&);
	static Json::Value rectangleToJson(const Rectangle&);
	static Json::Value colorToJson(const Color&);

	static Vector2 jsonToVec2(const Json::Value&);
	static Vector3 jsonToVec3(const Json::Value&);
	static Rectangle jsonToRectangle(const Json::Value&);
	static Color jsonToColor(const Json::Value&);

};
	
}}