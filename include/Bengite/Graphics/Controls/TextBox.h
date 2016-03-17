#pragma once

#include <string>
#include <raylib.h>

#include "Core/GameTime.h"
#include "Graphics/SpriteBatch.h"
#include "Graphics/Controls/Control.h"

using namespace std;
using namespace bengite::core;

namespace bengite { namespace graphics {

class TextBox : public Control {
private:

	unsigned int _maxChars;
	Color _focusColor;

public:
	TextBox(const string&);

	void Update(const GameTime&);
	void Draw(const GameTime&, SpriteBatch&);

	unsigned int getMaxChars() const;
	Color getFocusColor() const;

	void setMaxChars(const int&);
	void setFocusColor(const Color&);

	
	Json::Value toJson(void) const; 
	void fromJson(Json::Value&);

protected:
};

}}