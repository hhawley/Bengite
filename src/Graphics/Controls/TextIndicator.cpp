#include "Graphics/Controls/TextIndicator.h"

#include "Core/Objects.h"

using namespace bengite::graphics;

TextIndicator::TextIndicator(const string& name, const string& text) 
	: Control(name) {
	
	_text = text;
	
}

void TextIndicator::Update(const GameTime&) {
	
	
	
}

void TextIndicator::Draw(const GameTime&, SpriteBatch&) {
	
	DrawText(_text.c_str(), 
		static_cast<int>(_position.x), static_cast<int>(_position.y), 
		10, _color);
	
}

Json::Value TextIndicator::toJson(void) const {

	Json::Value controlJson;
	controlJson["name"] = getName();
	controlJson["text"] = getText();
	controlJson["position"] = raylibJson::vector2ToJson(getPosition());
	controlJson["color"] = raylibJson::colorToJson(getColor());
	controlJson["size"] = raylibJson::rectangleToJson(getSize());
	controlJson["enabled"] = isEnabled();
	controlJson["visible"] = isVisible();


	Json::Value finalJson;
	finalJson["textIndicator"] = controlJson;
	return finalJson;

}

void TextIndicator::fromJson(Json::Value& value) {
	setName(value.get("name", "").asString());
	setText(value.get("text", "").asString());
	setEnabled(value.get("enabled", true).asBool());
	setVisible(value.get("visible", true).asBool());

	auto v = value.get("position", -1);
	setPosition(raylibJson::jsonToVec2(v));

	v = value.get("color", -1);
	setColor(raylibJson::jsonToColor(v));

	v = value.get("size", -1);
	setSize(raylibJson::jsonToRectangle(v));
}