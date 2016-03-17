#pragma once

#if PLATFORM_DESKTOP

#include <raylib.h>

#include "Core/GameTime.h"
#include "Graphics/SpriteBatch.h"

namespace bengite { namespace core {
	
class Mouse {
private:
	static Vector2 _position;
	static Texture2D _texture;
	
	static bool _leftClick;
	static bool _leftDown;
	static bool _rightClick;
	static bool _rightDown;
	
public:
	
	static Vector2 getPosition(void);
	static Rectangle getRectangle(void);

	static void LoadContent(void);
	static void Update(const GameTime&);
	static void Draw(SpriteBatch&);
	
	static bool isTouching(const Rectangle&);
	
	static bool LeftClick(void);
	static bool LeftDown(void);
	static bool RightClick(void);
	static bool RightDown(void);
	

protected:
};

}}

#endif
