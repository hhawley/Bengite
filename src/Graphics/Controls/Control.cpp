#include "Graphics/Controls/Control.h"
#include "Graphics/DrawingManager.h"

using namespace bengite::graphics;

Control::Control(const string& name) 
	: 	DrawObject(3),
		_name(name), _text(""), _size(), _position(), 
		_focus(false), _enabled(true), _visible(true), _color(WHITE){


}


Control::~Control() {}


void Control::OnRightClick(void) {
	
	_rightClick.OnDone(2, this);
	
}

void Control::OnLeftClick(void) {
	
	_leftClick.OnDone(1, this);
	
}

void Control::setRightClick(const Funct<int, Control>& f) {
	
	_rightClick.setEvent(f);
	
}

void Control::setLeftClick(const Funct<int, Control>& f) {
	
	_leftClick.setEvent(f);
	
}


/* Getters */ 
string Control::getName() const {
	
	return _name;
	
}

string Control::getText() const {
	
	return _text;
	
}

Rectangle Control::getSize() const {
	
	return (Rectangle){(int)_position.x, (int)_position.y, _size.width, _size.height};
	
}

Vector2 Control::getPosition() const {
	
	return _position;
	
}

Color Control::getColor() const {
	
	return _color;
	
}

bool Control::hasFocus() const {
	
	return _focus;
	
}

bool Control::isEnabled() const {
	
	return _enabled;
	
}

bool Control::isVisible() const {
	
	return _visible;
	
}


/* Setters */
void Control::setName(const string& name) {
	
	_name = name;
	
}

void Control::setText(const string& text) {
	
	_text = text;
	
}

void Control::setSize(const Rectangle& size) {
	
	_size = size;
	
}

void Control::setPosition(const Vector2& position) {
	
	_position = position;
	
}

void Control::setColor(const Color& color) {
	
	_color = color;
	
}

void Control::setFocus(const bool& focus) {
	
	_focus = focus;
	
}

void Control::setEnabled(const bool& enabled) {
	
	_enabled = enabled;
	
}

void Control::setVisible(const bool& visible) {
	
	_visible = visible;
	
}
