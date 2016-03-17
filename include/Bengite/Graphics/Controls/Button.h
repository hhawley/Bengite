#pragma once

#include "Control.h"

namespace bengite { namespace graphics {
	
class Button : public Control {
private:


public:

	Button(const string& name, const string& text);
	
	void Update(const GameTime&);
	void Draw(const GameTime&, SpriteBatch&);

	Color getFocusColor(void) const;
	
	void setFocusColor(const Color&);

	Json::Value toJson(void) const; 
	void fromJson(Json::Value&);

protected:

	Color _focusColor;

};

}}