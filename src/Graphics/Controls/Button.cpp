#include "Graphics/Controls/Button.h"

#include "Core/Input/Mouse.h"
#include "Core/Objects.h"

using namespace bengite::core;
using namespace bengite::graphics;

Button::Button(const string& name, const string& text)
	: Control(name) {
	_text = text;
	
}
	
void Button::Update(const GameTime&) {
#if PLATFORM_DESKTOP
	if(Mouse::isTouching(getSize())) {
		_focus = true;
		
		if(Mouse::LeftClick()) {
			OnLeftClick();
		} else if (Mouse::RightClick()) {
			OnRightClick();
		}
		
	} else _focus = false;
#endif
	
}

void Button::Draw(const GameTime&, SpriteBatch&) {
	
	if(_focus)
		DrawRectangleRec(getSize(), _focusColor);
	else 
		DrawRectangleRec(getSize(), _color);
	
	int size_w = MeasureText(_text.c_str(), 10);
	size_w = (_size.width - size_w) / 2;
	
	int size_h = (_size.height - 10) / 2;
	
	DrawText(_text.c_str(), (int)_position.x + size_w, (int)_position.y + size_h, 10, WHITE);
	
}

Color Button::getFocusColor(void) const {
	
	return _focusColor;
	
}

void Button::setFocusColor(const Color& focusColor) {
	
	_focusColor = focusColor;
	
}

Json::Value Button::toJson(void) const {

	Json::Value controlJson;
	controlJson["name"] = getName();
	controlJson["text"] = getText();
	controlJson["position"] = raylibJson::vector2ToJson(getPosition());
	controlJson["color"] = raylibJson::colorToJson(getColor());
	controlJson["size"] = raylibJson::rectangleToJson(getSize());
	controlJson["enabled"] = isEnabled();
	controlJson["visible"] = isVisible();

	controlJson["focusColor"] = raylibJson::colorToJson(getFocusColor());

	Json::Value finalJson;
	finalJson["button"] = controlJson;
	return finalJson;

}

void Button::fromJson(Json::Value& value) {
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

	v = value.get("focusColor", -1);
	setFocusColor(raylibJson::jsonToColor(v));
}
