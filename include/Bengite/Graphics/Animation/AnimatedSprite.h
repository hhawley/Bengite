#pragma once

#include <vector>
#include <memory>
#include <json/json.h>
#include <raylib.h>

#include "Core/GameTime.h"

#include "Graphics/DrawObject.h"
#include "Graphics/SpriteBatch.h"
#include "Graphics/Animation/Animation.h"

using namespace std;
using namespace bengite::core;

namespace bengite { namespace graphics {
	
/* Hash type required to make the Animation Dictionary*/
// struct EnumClassHash {
	// template<typename T>
	// size_t operator()(T t) const {
		
		// return static_cast<size_t>(t);
		
	// }
	
// };


//typedef unordered_map<Animation::AnimationKey, Animation, EnumClassHash> AnimationDict; 
typedef vector<Animation> AnimationDict; 

class AnimatedSprite : public DrawObject {
private:
	
public:

	AnimationDict 	getAnimations(void) const;
	Animation 		getCurrentAnimation(void) const;
	int				getCurrentKey(void) const;
	Vector2 		getPosition(void) const;
	Vector2 		getVelocity(void) const;
	Color 			getColor(void) const;
	bool 			isAnimating(void) const;
	
	void setCurrentAnimation(const int&);
	void setAnimating(const bool&);
	void setPosition(const Vector2&);
	void setSpeed(const Vector2&);
	void setColor(const Color&);
	
	AnimatedSprite();
	AnimatedSprite(const string&);
	
	void LoadContent();
	void Update(const GameTime&);
	void Draw(const GameTime&, SpriteBatch&);
	
	Json::Value toJson() const;
	void fromJson(Json::Value&);

protected:

	AnimationDict _animations;
	int _currentKey;
	bool _isAnimating;
	
	string _resourceName;
	shared_ptr<Texture2D> _texture;
	Vector2 _position;
	Vector2 _velocity;
	
	Color _color;


};

}}