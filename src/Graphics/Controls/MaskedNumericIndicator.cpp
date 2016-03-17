#include "Graphics/Controls/MaskedNumericIndicator.h"

#include "Core/Math/BMath.h"
#include "Core/Objects.h"

using namespace bengite::core;
using namespace bengite::graphics;


MaskedNumericIndicator::MaskedNumericIndicator(const string& name, 
		const unsigned int& mask = 3, const float& num = 0) 
		: Control(name), _mask(mask), _number(num) {
	
	float roundNum = Math::roundf(num, mask);
	_text = Math::ftostr(roundNum);
		
}

void MaskedNumericIndicator::Update(const GameTime& gameTime) {
	
	
	
}

void MaskedNumericIndicator::Draw(const GameTime& gameTime, SpriteBatch& spriteBatch) {
	
	DrawText(_text.c_str(), 
		static_cast<int>(_position.x), static_cast<int>(_position.y), 
		10, WHITE);
	
}

float MaskedNumericIndicator::getNumber(void) const {
	
	return _number;
	
}

unsigned int MaskedNumericIndicator::getMask(void) const {
	
	return _mask;
	
}

void MaskedNumericIndicator::setText(const float& num) {
	
	_number = num;
	float roundNum = Math::roundf(num, _mask);
	_text = Math::ftostr(roundNum);
	
}

void MaskedNumericIndicator::setMask(const unsigned int& mask) {
	
	_mask = mask;
	setText(getNumber());
	
}

void MaskedNumericIndicator::setNumber(const float& num) {
	
	_number = num;
	float roundNum = Math::roundf(num, _mask);
	_text = Math::ftostr(roundNum);
	
}

Json::Value MaskedNumericIndicator::toJson(void) const {

	Json::Value controlJson;
	controlJson["name"] = getName();
	controlJson["text"] = getText();
	controlJson["position"] = raylibJson::vector2ToJson(getPosition());
	controlJson["color"] = raylibJson::colorToJson(getColor());
	controlJson["size"] = raylibJson::rectangleToJson(getSize());
	controlJson["enabled"] = isEnabled();
	controlJson["visible"] = isVisible();

	Json::Value finalJson;
	finalJson["maskedNumericIndicator"] = controlJson;
	return finalJson;

}

void MaskedNumericIndicator::fromJson(Json::Value& value) {

	setName(value.get("name", "").asString());
	setText(value.get("text", 0.0f).asFloat());
	setEnabled(value.get("enabled", true).asBool());
	setVisible(value.get("visible", true).asBool());

	auto v = value.get("position", -1);
	setPosition(raylibJson::jsonToVec2(v));

	v = value.get("color", -1);
	setColor(raylibJson::jsonToColor(v));

	v = value.get("size", -1);
	setSize(raylibJson::jsonToRectangle(v));
	
}
