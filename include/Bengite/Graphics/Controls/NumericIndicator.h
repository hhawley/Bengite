#pragma once

#include "Control.h"

namespace bengite { namespace graphics {
	
class NumericIndicator : public Control {
private:


public:

	NumericIndicator(const string& name, const float& num);
	
	void Update(const GameTime&);
	void Draw(const GameTime&, SpriteBatch&);
	
	float getNumber(void) const;
	
	void setText(const float&);
	void setNumber(const float&);
	
	
	Json::Value toJson(void) const; 
	void fromJson(Json::Value&);

protected:
	float _number;

};

}}