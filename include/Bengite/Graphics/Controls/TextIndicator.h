#pragma once

#include "Control.h"

namespace bengite { namespace graphics {
	
class TextIndicator : public Control {
private:


public:

	TextIndicator(const string& name, const string& text);
	
	void Update(const GameTime&);
	void Draw(const GameTime&, SpriteBatch&);
	
	
	Json::Value toJson(void) const; 
	void fromJson(Json::Value&);

protected:

};

}}