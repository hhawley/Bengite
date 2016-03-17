#pragma once

#include "Control.h"

namespace bengite { namespace graphics {
	
class MaskedNumericIndicator : public Control {
private:
	

public:

	MaskedNumericIndicator(const string& name, 
		const unsigned int& mask, const float& num);
	
	void Update(const GameTime&);
	void Draw(const GameTime&, SpriteBatch&);
	
	float getNumber(void) const;
	unsigned int getMask(void) const;
	
	void setText(const float&);
	void setMask(const unsigned int&);
	void setNumber(const float&);

	
	Json::Value toJson(void) const; 
	void fromJson(Json::Value&);

protected:

	unsigned int _mask;
	float _number;
	
};

}}