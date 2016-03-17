/*
*	Class: Control
*	Description: The mother of all game controls. This don't depend on
*	DrawObject as they are intended to be a separate object from them.
*	They will always be drawn on top of game objects else. That means
*	DrawLevel = infinite
*/

#pragma once

#include <string>
#include <raylib.h>
#include <json/json.h>

#include "Core/GameTime.h"
#include "Core/Events/Event.h"

#include "Graphics/DrawObject.h"
#include "Graphics/SpriteBatch.h"

using namespace std;
using namespace bengite::core;

namespace bengite { namespace graphics {
	
class Control : public DrawObject {
private:
	
	
public:
	
	Control(const string& name);
	virtual ~Control();
	
	virtual void Update(const GameTime&) = 0;
	virtual void Draw(const GameTime&, SpriteBatch&) = 0;
	
	/* Getters */ 
	string 		getName() const;
	string 		getText() const;
	Rectangle 	getSize() const;
	Vector2 	getPosition() const;
	Color		getColor() const;
	bool 		hasFocus() const;
	bool 		isEnabled() const;
	bool 		isVisible() const;
	
	/* Setters */
	void setName(const string&);
	void setText(const string&);
	void setSize(const Rectangle&);
	void setPosition(const Vector2&);
	void setColor(const Color&);
	void setFocus(const bool&);
	void setEnabled(const bool&);
	void setVisible(const bool&);
	
	void setRightClick(const Funct<int, Control>&);
	void setLeftClick(const Funct<int, Control>&);


	virtual Json::Value toJson(void) const = 0;
	virtual void fromJson(Json::Value&) = 0;
	
protected:

	/* Events */
	void OnRightClick(void);
	void OnLeftClick(void);
	
	string _name;
	
	string _text;
	Rectangle _size;
	Vector2 _position;
	
	bool _focus;
	bool _enabled;
	bool _visible;
	
	Color _color;
	
	Event<int, Control> _rightClick; 
	Event<int, Control> _leftClick;
	
};

}}