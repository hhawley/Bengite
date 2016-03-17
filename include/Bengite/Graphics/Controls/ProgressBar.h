#pragma once

#include "Control.h"

namespace bengite { namespace graphics {
	
class ProgressBar : public Control {
private:


public:

	ProgressBar(const string& name, const float& max);
	
	void Update(const GameTime&);
	void Draw(const GameTime&, SpriteBatch&);

	bool 	isShowingNumber() const;
	float 	getMaxNumber() const;
	float 	getCurrentNumber() const;
	Color 	getTopColor() const;
	
	void setShowingNumber(const bool&);
	void setMaxNumber(const float&);
	void setCurrentNumber(const float&);
	void setTopColor(const Color&);

	
	Json::Value toJson(void) const; 
	void fromJson(Json::Value&);
protected:

	bool _showNum;
	float _maxNumber;
	float _currentNumber;
	Color _topColor;
	
};

}}