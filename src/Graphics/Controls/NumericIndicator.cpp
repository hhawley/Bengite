#include "Graphics/Controls/NumericIndicator.h"

#include "Core/Math/BMath.h"
#include "Core/Objects.h"

using namespace bengite::core;
using namespace bengite::graphics;

NumericIndicator::NumericIndicator(const string& name, const float& num) 
	: Control(name), _number(num) {
	
	_text = Math::ftostr(num);
	
}

void NumericIndicator::Update(const GameTime& gameTime) {
	
	
	
}

void NumericIndicator::Draw(const GameTime& gameTime, SpriteBatch& spriteBatch) {
	
	DrawText(_text.c_str(), 
		static_cast<int>(_position.x), static_cast<int>(_position.y), 
		10, WHITE);
	
}

float NumericIndicator::getNumber(void) const {
	
	return _number;
	
}

void NumericIndicator::setText(const float& num) {
	
	_number = num;
	_text = Math::ftostr(num);
	
}

void NumericIndicator::setNumber(const float& num) {
	
	_number = num;
	_text = Math::ftostr(num);
	
}


Json::Value NumericIndicator::toJson(void) const {

	Json::Value controlJson;
	controlJson["name"] = getName();
	controlJson["text"] = getText();
	controlJson["position"] = raylibJson::vector2ToJson(getPosition());
	controlJson["color"] = raylibJson::colorToJson(getColor());
	controlJson["size"] = raylibJson::rectangleToJson(getSize());
	controlJson["enabled"] = isEnabled();
	controlJson["visible"] = isVisible();

	Json::Value finalJson;
	finalJson["numericIndicator"] = controlJson;
	return finalJson;

}

void NumericIndicator::fromJson(Json::Value& value) {

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
