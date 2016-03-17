#include "Core\Math\BMath.h"

#include <math.h>
#include <sstream>

using namespace bengite::core;

float Math::Length(const Vector2& v) {
	
	return sqrt(v.x * v.x + v.y * v.y);
	
}

Vector2 Math::unitVector(const Vector2& v) {
	
	float length = Length(v);
	return (Vector2) {v.x / length, v.y / length};
	
}

float Math::dotProduct(const Vector2& v1, const Vector2& v2) {
	
	return (v1.x * v2.x + v1.y * v2.y);
	
}

/*Other Math functions*/
float Math::roundf(const float& num, const int& digits) {
	
	return static_cast<float>(round(num * (digits * 10)) / (digits * 10));
	
}

double Math::roundd(const double& num, const int& digits) {
	
	return static_cast<double>(round(num * (digits * 10)) / (digits * 10));
	
}

/*Numbers to strings*/
std::string Math::ftostr(const float& num) {
	
	std::stringstream ss (std::stringstream::in | std::stringstream::out);
	
	ss << num;
	
	return ss.str();
	
}