#pragma once

#include <memory>
#include <raylib.h>
#include <json/json.h>
#include <string>

#include "Graphics/Animation/AnimatedSprite.h"

using namespace bengite::graphics;

namespace bengite { namespace core {
	
class Player {
private:


public:

	Vector2 getPosition(void) const;
	
	void setPosition(const Vector2&);

	Player();
	
	virtual void Initialize(void);
	virtual void LoadContent(void);
	virtual void Update(const GameTime&);
	
	virtual Json::Value toJson(const string&);
	virtual void fromJson(const string&);
	
	
protected:
	
	AnimatedSprite _sprite;
	
};
	
	
}}