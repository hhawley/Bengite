#pragma once

#include <functional>
#include <vector>
#include <memory>

#include "Core/GameTime.h"

#include "Graphics/SpriteBatch.h"
#include "Graphics/DrawObject.h"

using namespace std;
using namespace bengite::core;

namespace bengite { namespace graphics { 

typedef shared_ptr<function<void(const GameTime&, 
	SpriteBatch&)>> DrawPtr;
			
typedef function<void(const GameTime&, 
	SpriteBatch&)> DrawFct;
			
typedef vector<DrawFct>::iterator DrawIterator;

class DrawingManager {
private:

	static vector<DrawFct> _Level_Minus;
	static vector<DrawFct> _Level_Zero;
	static vector<DrawFct> _Level_One;
	static vector<DrawFct> _Level_Two;
	static vector<DrawFct> _Level_Control;
	
public:

	static void Draw(const GameTime&, SpriteBatch&);
	
	//static void addDraw(DrawFct&, const short int&);
	static void addDraw(DrawObject&);
	
	static void clear(void);

protected:
	
};

}}