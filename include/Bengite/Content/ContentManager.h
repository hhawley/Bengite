#pragma once

/*
*	Name: Content Manager static class
*	Description: Manages the textures, tilesets, and animatedSprites
*	loads them and unloads them. 
*	Details: The Textures have to be located at ./Content/
*	and so the main tile set shall be named "TileSet.png". Amen.
*/


#include <memory>
#include <unordered_map>
#include <string>
#include <raylib.h>

#include "Graphics/16bitTileEngine/TileSet.h"

using namespace std;
using namespace bengite::graphics;

namespace bengite { namespace content {
	
typedef shared_ptr<Texture2D> Texture2DPtr;
typedef shared_ptr<TileSet> TileSetPtr;
typedef unordered_map<string, Texture2DPtr> Text2DDictionary;

class ContentManager {
private:
	
	static TileSetPtr _mainTileSet;
	static Text2DDictionary _textures; 

public:

	static void Initialize(void);
	static void Unload(void);
	
	static TileSetPtr getTileSet(void);
	static Texture2DPtr getTexture(const string&);
	
protected:
	
	static void LoadTextures();
	static void LoadTileSets();
	
};

}}