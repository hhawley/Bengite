#pragma once

#include <raylib.h>

namespace bengite { namespace core {
	
class SpriteBatch{
private:
	
	Vector2 _trasnlationVec;
	
public:
	
	SpriteBatch();
	
	void Begin();
	void Begin(const Vector2& Translation);
	
	void Clear(const Color& color);
	
	void Draw(const Texture2D&, const int& PosX, const int& PosY, const Color& Tint);
	void Draw(const Texture2D&, const Vector2& Pos, const Color& Tint);
	void Draw(const Texture2D&, const Vector2& Pos, const float& rotation, const float& scale, const Color& Tint);
	void Draw(const Texture2D&, const Rectangle& SourceRec, const Vector2& Position, const Color& Tint);
	void Draw(const Texture2D&, const Rectangle& SourceRec, const Rectangle& DestRec, const Vector2& origin, const float& rotation, const Color& Tint);
	
	void End();
	
protected:
};

}}