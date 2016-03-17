#include "Content/ContentManager.h"

#include <vector>

#ifdef _WIN32
#include <dirent.h>
#endif

using namespace bengite::content; 
using namespace bengite::graphics;

TileSetPtr ContentManager::_mainTileSet =  nullptr;
Text2DDictionary ContentManager::_textures; 

void ContentManager::Initialize(void) {
	
	LoadTileSets();
	LoadTextures();
	
}

void ContentManager::Unload(void) {
	
	for(auto& texture : _textures)
		UnloadTexture(*texture.second);
	
}

TileSetPtr ContentManager::getTileSet(void) {
 
	return _mainTileSet;
 
}

Texture2DPtr ContentManager::getTexture(const string& name) {
	
	return _textures.find(name) == _textures.end() ? _textures["errorTexture"] : _textures[name];
	
}

void ContentManager::LoadTextures() {
	
#ifdef _WIN32
	string dirName = "";
	vector<string> dirNames;
	
	DIR* dir;
	struct dirent* ent;
	
	if((dir = opendir(".\\Content\\")) != NULL) {
		
		while((ent = readdir(dir)) != NULL) {
			
			dirName = ent->d_name;
			dirNames.push_back(dirName);
			
		}
		
		closedir(dir);
		
		for(auto& name : dirNames) {
			
			if(name.rfind(".png") != string::npos) {
				
				dirName = ".\\Content\\" + name;
				
				_textures.insert( 
				{name,
				make_shared<Texture2D>(LoadTexture(dirName.c_str()))
				});
				
			}
				
		}	
		
	} 
#endif

	Color* pixels = new Color[TileLength * TileLength];
	
	for(int i = 0; i < TileLength; i++)
		for(int j = 0; j < TileLength; j++)
			if(i % (TileLength / 2) == 1 || j % (TileLength / 2)  == 1)
				pixels[i + j * TileLength] = PURPLE;
			else pixels[i + j * TileLength] = BLACK;
	
	Image errorTexture = LoadImageEx(pixels, TileLength, TileLength);
	_textures.insert( 
		{ "errorTexture",
		make_shared<Texture2D>(LoadTextureFromImage(errorTexture))
		});
		
	delete pixels;
	
}

void ContentManager::LoadTileSets() {

	_mainTileSet.reset(
	new TileSet(
	std::make_shared<Texture2D>(
	LoadTexture(".\\Content\\TileSet.png")
	)));

	
}