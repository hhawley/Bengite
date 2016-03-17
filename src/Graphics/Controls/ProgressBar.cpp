#include "Graphics/Controls/ProgressBar.h"

#include "Core/Math/BMath.h"
#include "Core/Objects.h"

using namespace bengite::core;
using namespace bengite::graphics;

ProgressBar::ProgressBar(const string& name, const float& max = 100.0f) 
	: Control(name), _showNum(false), _maxNumber(max), _currentNumber(0),
	_topColor((Color){0, 255, 0, 255}) {
	
	_color = (Color){255, 0, 0, 255};
	
}

void ProgressBar::Update(const GameTime& gameTime) {
	
	
	
}

void ProgressBar::Draw(const GameTime& gameTime, SpriteBatch& spriteBatch) {

	DrawRectangleRec(getSize(), _color);
	
	Rectangle topSize = (Rectangle){static_cast<int>(_position.x),
		static_cast<int>(_position.y),
		static_cast<int>((_currentNumber * _size.width) / _maxNumber),
		_size.height};
	
	DrawRectangleRec(topSize, _topColor);
	
	if(_showNum) {
		_text = Math::ftostr(_currentNumber) + "/" + Math::ftostr(_maxNumber);
		int size_w = MeasureText(_text.c_str(), 10);
		size_w = (_size.width - size_w) / 2;
		
		int size_h = (_size.height - 10) / 2;
		
		DrawText(_text.c_str(), 
			(int)_position.x + size_w, (int)_position.y + size_h, 
			10, WHITE);
	}
	
}

bool ProgressBar::isShowingNumber() const {
	
	return _showNum;
	
}

float ProgressBar::getMaxNumber() const {
	
	return _maxNumber;
	
}

float ProgressBar::getCurrentNumber() const {
	
	return _currentNumber;
	
}

Color ProgressBar::getTopColor() const {
	
	return _topColor;
	
}

void ProgressBar::setShowingNumber(const bool& value) {
	
	_showNum = value;
	
}

void ProgressBar::setMaxNumber(const float& num) {
	
	_maxNumber = num;
	
}

void ProgressBar::setCurrentNumber(const float& num) {
	
	_currentNumber = num > _maxNumber ? _maxNumber : num < 0 ? 0 : num;
	
}

void ProgressBar::setTopColor(const Color& color) {
	
	_topColor =  color;
	
}

Json::Value ProgressBar::toJson(void) const {

	Json::Value controlJson;

	controlJson["name"] = this->_name;
	controlJson["text"] = this->_text;
	controlJson["position"] = raylibJson::vector2ToJson(this->_position);
	controlJson["color"] = raylibJson::colorToJson(this->_color);
	controlJson["size"] = raylibJson::rectangleToJson(this->_size);
	controlJson["enabled"] = this->_enabled;
	controlJson["visible"] = this->_visible;

	controlJson["showNum"] = this->_showNum;
	controlJson["maxNum"] = this->_maxNumber;
	controlJson["currentNum"] = this->_currentNumber;
	controlJson["topColor"] = raylibJson::colorToJson(this->_topColor);

	Json::Value finalJson;
	finalJson["progressBar"] = controlJson;
	return finalJson;


}

void ProgressBar::fromJson(Json::Value& value) {

	this->_name = value.get("name", "").asString();
	this->_text = value.get("text", "").asString();
	this->_enabled = value.get("enabled", true).asBool();
	this->_visible = value.get("visible", true).asBool();

	auto v = value.get("position", -1);
	this->_position = raylibJson::jsonToVec2(v);

	v = value.get("color", -1);
	this->_color = raylibJson::jsonToColor(v);

	v = value.get("size", -1);
	this->_size = raylibJson::jsonToRectangle(v);

	this->_showNum = value.get("showNum", false).asBool();
	this->_maxNumber = value.get("maxNum", 100).asInt();
	this->_currentNumber = value.get("currentNum", 100).asInt();

	v = value.get("topColor", -1);
	this->_topColor = raylibJson::jsonToColor(v);

}
