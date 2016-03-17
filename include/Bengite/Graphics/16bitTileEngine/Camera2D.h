#pragma once

#include <raylib.h>

#include "Core/Objects.h"
#include "Core/GameTime.h"

using namespace bengite::core;

namespace bengite { namespace graphics {

class Camera2D {
private:

	static bool _enabled;
	static float _zoom;
	static Rectangle _viewport;
	
	static Vector2 _position;

public:

	static void Initialize(const Rectangle&);
	static void Update(const GameTime&);
	
	static void SnapToPosition(const Vector2& position, const GameTime&);
	static void setZoom(const float&);
	static void setPosition(const Vector2& position);
	
	static float getZoom(void);
	static Rectangle getViewPort(void);
	static Vector2 getPosition(void);
	static Vector2 getMiddleScreen(void);
	static Point getCell(void);
	static Point getMiddleCell(void);
	static Point getWorldCell(void);
	static Point getWorldMiddleCell(void);

	static void zoomOut(void);
	static void zoomIn(void);

protected:
};

}}