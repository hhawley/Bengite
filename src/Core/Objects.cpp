#include "Core/Objects.h"

#include "Graphics/16bitTileEngine/Camera2D.h"
#include "Graphics/16bitTileEngine/16BitConfig.h"

using namespace bengite::core;
using namespace bengite::graphics;

Point Point::operator+(const Point& p2) const {
	
	return (Point){this->x + p2.x, this->y + p2.y};
	
}

Point Point::operator-(const Point& p2) const {
	
	return (Point){this->x - p2.x, this->y - p2.y};
	
}

bool Point::operator!=(const Point& p2) const {
	
	return this->x != p2.x || this->y != p2.y;
	
}

bool Point::operator==(const Point& p2) const {
	
	return this->x == p2.x && this->y == p2.y;
	
}

Point Point::toCell(const Vector2& v) {
	return (Point){
		static_cast<int>(v.x / (Camera2D::getZoom() * TileLength)),
		static_cast<int>(v.y / (Camera2D::getZoom() * TileLength)) 
	};
}

Point Point::toCell(const Vector2& v, const float& zoom) {
	return (Point) {
		static_cast<int>(v.x / (zoom * TileLength)),
		static_cast<int>(v.y / (zoom * TileLength))
	};
}

Json::Value raylibJson::vector2ToJson(const Vector2& vec) {

	Json::Value vecJson(Json::arrayValue);
	vecJson.append(vec.x);
	vecJson.append(vec.y);
	return vecJson;

}

Json::Value raylibJson::vector3ToJson(const Vector3& vec) {

	Json::Value vecJson(Json::arrayValue);
	vecJson.append(vec.x);
	vecJson.append(vec.y);
	vecJson.append(vec.z);
	return vecJson;

}

Json::Value raylibJson::rectangleToJson(const Rectangle& rec) {

	Json::Value recJson(Json::arrayValue);
	recJson.append(rec.x);
	recJson.append(rec.y);
	recJson.append(rec.width);
	recJson.append(rec.height);
	return recJson;

}

Json::Value raylibJson::colorToJson(const Color& color) {

	Json::Value colorJson(Json::arrayValue);
	colorJson.append(color.r);
	colorJson.append(color.g);
	colorJson.append(color.b);
	colorJson.append(color.a);
	return colorJson;

}

Vector2 raylibJson::jsonToVec2(const Json::Value& value) {

	try {
		return (Vector2){value[0].asFloat(), value[1].asFloat()};
	} catch(...) {
		return (Vector2){0.0f, 0.0f};
	}


}

Vector3 raylibJson::jsonToVec3(const Json::Value& value) {
	try{
		return (Vector3){value[0].asFloat(), value[1].asFloat(), value[2].asFloat()};
	} catch(...) {
		return (Vector3){0.0f, 0.0f, 0.0f};
	}
}

Rectangle raylibJson::jsonToRectangle(const Json::Value& value) {

	try{
		return (Rectangle){value[0].asInt(), value[1].asInt(), value[2].asInt(), value[3].asInt()};
	} catch(...) {
		return (Rectangle){0, 0, 0, 0};
	}

}

Color raylibJson::jsonToColor(const Json::Value& value) {

	try {
		return (Color){static_cast<unsigned char>(value[0].asUInt()), 
			static_cast<unsigned char>(value[1].asUInt()), 
			static_cast<unsigned char>(value[2].asUInt()), 
			static_cast<unsigned char>(value[3].asUInt())};
	} catch(...) {
		return (Color){255, 255, 255, 255};
	}

}