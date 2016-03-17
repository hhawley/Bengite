#pragma once

#include <vector>
#include <raylib.h>

#include "Core/GameTime.h"

using namespace std;
using namespace bengite::core;

namespace bengite { namespace graphics {
	
class Animation {
private:

	int _frameCount;
	vector<Rectangle> _frames; 
	int _fps;
	float _frameLength;
	float _frameTime;
	
	int _currentFrame;
	
public:

	vector<Rectangle> getFrames(void) const;
	int getFrameCount(void) const;
	int getFPS(void) const;
	Rectangle getCurrentFrame(void) const;
	
	void setFPS(const int&);
	void setCurrentFrame(const int&);
	
	Animation();
	Animation(const int& frameCount, const int& offSetX, const int& offSetY);
	
	void Update(const GameTime&);
	
	void Reset(void);

protected:
};

}}