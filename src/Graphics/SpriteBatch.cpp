#include "Graphics/SpriteBatch.h"
	
using namespace bengite::core;

SpriteBatch::SpriteBatch() {
	
}

void SpriteBatch::Begin() {
	
	_trasnlationVec = (Vector2){0.0f, 0.0f};
	BeginDrawing();
	
}

void SpriteBatch::Begin(const Vector2& Translation) {
	
	_trasnlationVec = Translation;
	BeginDrawing();
	
}

void SpriteBatch::Clear(const Color& color) {
	
	ClearBackground(color);
	
}

void SpriteBatch::Draw(	const Texture2D& Texture, const int& PosX, 
						const int& PosY, const Color& Tint) {
							
	DrawTexture(Texture, PosX - _trasnlationVec.x, PosY - _trasnlationVec.y, Tint);
	
}

void SpriteBatch::Draw(	const Texture2D& Texture, const Vector2& Pos, 
						const Color& Tint) {
							
	DrawTextureV(Texture, (Vector2){Pos.x - _trasnlationVec.x, Pos.y - _trasnlationVec.y}, Tint);
	
}
void SpriteBatch::Draw(	const Texture2D& Texture, const Vector2& Pos, 
						const float& Rotation, const float& Scale, 
						const Color& Tint) {
							
	DrawTextureEx(Texture, (Vector2){Pos.x - _trasnlationVec.x, Pos.y - _trasnlationVec.y}, 
	Rotation, Scale, Tint);						
	
}
void SpriteBatch::Draw(	const Texture2D& Texture, const Rectangle& SourceRec, 
						const Vector2& Position, const Color& Tint) {
							
	DrawTextureRec(Texture, SourceRec, (Vector2){Position.x - _trasnlationVec.x,
	Position.y - _trasnlationVec.y}, Tint);						
	
}
void SpriteBatch::Draw(	const Texture2D& Texture, const Rectangle& SourceRec, 
						const Rectangle& DestRec, const Vector2& Origin, 
						const float& Rotation, const Color& Tint) {
							
	DrawTexturePro(
	Texture, SourceRec, 
	(Rectangle){DestRec.x - static_cast<int>(_trasnlationVec.x), DestRec.y - static_cast<int>(_trasnlationVec.y), DestRec.width, DestRec.height}, 
	Origin, Rotation, Tint);						
	
}

void SpriteBatch::End() {
	
	EndDrawing();
	
}
