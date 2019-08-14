
#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include"../gameObjects/pacman.h"
#include "../gameObjects/ball.h"
#include"../gameObjects/wall.h"

constexpr short pacTextureAmount = 9;
constexpr short bonusTextureAmount = 4;
constexpr short ghostsTextureAmount = 4;

using namespace sf;
class resourcesManager
{
	
	resourcesManager();
	
	Texture* pacTextureArray;
	Texture* wallTexture;
	Texture* ballTexture;
	Texture* mapGeneratorShapeTexture;
	Texture* heartTexture;
	Texture* menuGraphicsTexture;
	Texture* menuGraphicsTexture2;
	Texture* menuControlInfoTexture;
	Texture* bonusTextureArray;
	Texture* ghostsTextureArray;
	Texture* gateTexture;
	Font* statusStrapFont;
	Font* menuTitleFont;
	Font* menuOptionsFont;
	
	void loadGateTexture();
	void loadPacTextures();
	void loadBallTextures();
	void loadWallTextures();
	void loadMapGeneratorShapeTexture();
	void loadHeartTexture();
	void loadStatusStrapFont();
	void loadMenuGraphicsTexture();
	void loadMenuTiteFont();
	void loadMenuOptionsFont();
	void loadMenuGraphicsTexture2();
	void loadMenuControllInfoTexture();
	void loadBonusTextureArray();
	void loadGhostTextureArray();

public:
	static resourcesManager& getInstance();
	resourcesManager(const resourcesManager& obj) = delete;
	resourcesManager& operator=(const resourcesManager& obj) = delete;

	~resourcesManager();
	
	void loadAll();
	
	Texture* getPacTexture();
	Texture* getWallTexture();
	Texture* getBallTexture();
	Texture* getMapGeneratorShapeTexture();
	Texture* getHeartTexture();
	Texture* getMenuGraphicsTexture();
	Texture* getMenuGraphicsTexture2();
	Texture* getMenuControlInfoTexture();
	Texture* getBonusTextureArray();
	Texture* getGhostsTextureArray();
	Texture* getGateTexture();
	Font* getStatusStrapFont();
	Font* getMenuTitleFont();
	Font* getMenuOptionsFont();
};

