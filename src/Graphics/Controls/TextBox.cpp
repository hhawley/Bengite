#include "Graphics/Controls/TextBox.h"

#include "Core/Input/Mouse.h"
#include "Core/Input/Keyboard.h"
#include "Core/Objects.h"

using namespace bengite::core;
using namespace bengite::graphics;

TextBox::TextBox(const string& name)
	: Control(name), _maxChars(64) {


}

void TextBox::Update(const GameTime& gameTime) {
#if PLATFORM_DESKTOP
	if(Mouse::isTouching(getSize())) {
		
	
		if(Mouse::LeftClick()) {
			_focus = true;
			OnLeftClick();
		} else if (Mouse::RightClick()) {
			OnRightClick();
		}
		
	} 

	if(_focus) {
		auto keys = Keyboard::PressedKeys();

		for(const auto& key : keys) {


			if(key == Keys::Enter) {
				_focus = false;
				break;
			} else if(key == Keys::Backspace) {
				if(_text.size() > 0)
					_text.pop_back();
				
				continue;
			}


			if(_text.size() == _maxChars) { continue; }
			else { _text += Keyboard::keyToChar(key); }
			

		}
	}
#endif

}

void TextBox::Draw(const GameTime& gameTime, SpriteBatch& spriteBatch) {

	if(_focus)
		DrawRectangleRec(getSize(), _focusColor);
	else 
		DrawRectangleRec(getSize(), _color);

	int size_w = MeasureText(_text.c_str(), 10);
	size_w = (_size.width - size_w) / 2;
	
	int size_h = (_size.height - 10) / 2;
	
	DrawText(_text.c_str(), (int)_position.x + size_w, (int)_position.y + size_h, 10, WHITE);

}

unsigned int TextBox::getMaxChars() const {

	return _maxChars;

}

Color TextBox::getFocusColor() const {

	return _focusColor;

}


void TextBox::setMaxChars(const int& maxChars) {

	_maxChars = maxChars;

}

void TextBox::setFocusColor(const Color& focusColor) {

	_focusColor = focusColor;

}

Json::Value TextBox::toJson(void) const {

	Json::Value controlJson;
	controlJson["name"] = getName();
	controlJson["text"] = getText();
	controlJson["position"] = raylibJson::vector2ToJson(getPosition());
	controlJson["color"] = raylibJson::colorToJson(getColor());
	controlJson["size"] = raylibJson::rectangleToJson(getSize());
	controlJson["enabled"] = isEnabled();
	controlJson["visible"] = isVisible();

	controlJson["maxChars"] = getMaxChars();
	controlJson["focusColor"] = raylibJson::colorToJson(getFocusColor());

	Json::Value finalJson;
	finalJson["textBox"] = controlJson;
	return finalJson;

}

void TextBox::fromJson(Json::Value& value) {

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

	setMaxChars(value.get("maxChars", 64).asUInt());

	v = value.get("focusColor", -1);
	setFocusColor(raylibJson::jsonToColor(v));

}