#include "resourcesManager.h"

resourcesManager::resourcesManager()
{
	pacTextureArray = new  Texture [pacTextureAmount];
	wallTexture = new Texture();
	ballTexture = new Texture();
	mapGeneratorShapeTexture = new Texture();
	heartTexture = new Texture();
	menuGraphicsTexture = new Texture();
	menuGraphicsTexture2 = new Texture();
	menuControlInfoTexture = new Texture();
	bonusTextureArray = new Texture[bonusTextureAmount];
	ghostsTextureArray = new Texture[ghostsTextureAmount];
	gateTexture = new Texture;

	statusStrapFont = new Font();
	menuOptionsFont = new Font();
	menuTitleFont = new Font();
}

resourcesManager::~resourcesManager()
{
	delete[] pacTextureArray;
	delete wallTexture;
	delete ballTexture;
	delete mapGeneratorShapeTexture;
	delete heartTexture;
	delete menuGraphicsTexture;
	delete menuGraphicsTexture2;
	delete menuControlInfoTexture;
	delete[] bonusTextureArray;
	delete[] ghostsTextureArray;
	delete gateTexture;


	delete statusStrapFont;
	delete menuOptionsFont;
	delete menuTitleFont;
}

void resourcesManager::loadGateTexture()
{
	if (!gateTexture->loadFromFile("resources/textures/gate.png"))
	{
		std::string error = "Unable to load gate texture.\n";
		throw error;

	}
}

void resourcesManager::loadPacTextures()
{
	//Ladowanie tekstur pacmana w odpowiedniej kolejnosci
	if (
	!(pacTextureArray[0].loadFromFile("resources/textures/pacmanStop.png"))
	|| !(pacTextureArray[1].loadFromFile("resources/textures/pacmanRight.png"))
	|| !(pacTextureArray[2].loadFromFile("resources/textures/pacmanRight2.png"))
	|| !(pacTextureArray[3].loadFromFile("resources/textures/pacmanLeft.png"))
	|| !(pacTextureArray[4].loadFromFile("resources/textures/pacmanLeft2.png"))
	|| !(pacTextureArray[5].loadFromFile("resources/textures/pacmanTop.png"))
	|| !(pacTextureArray[6].loadFromFile("resources/textures/pacmanTop2.png"))
	|| !(pacTextureArray[7].loadFromFile("resources/textures/pacmanBottom.png"))
	|| !(pacTextureArray[8].loadFromFile("resources/textures/pacmanBottom2.png"))
		)
	{
		std::string error = "Unable to load pacman texture.\n";
		throw error;
	}
}

void resourcesManager::loadBallTextures()
{
	if (!ballTexture->loadFromFile("resources/textures/ball.png"))
	{
		std::string error = "Unable to load ball texture.\n";
		throw error;

	}
}

void resourcesManager::loadWallTextures()
{
	if (!wallTexture->loadFromFile("resources/textures/wall.png"))
	{
		std::string error = "Unable to load wall texture.\n";
		throw error;

	}

}

void resourcesManager::loadMapGeneratorShapeTexture()
{
	if (!mapGeneratorShapeTexture->loadFromFile("resources/textures/mapGenerator.png"))
	{
		std::string error = "Unable to load mapGenerator texture.\n";
		throw error;
	}

}

void resourcesManager::loadHeartTexture()
{
	if (!heartTexture->loadFromFile("resources/textures/heart.png"))
	{
		std::string error = "Unable to load heart texture.\n";
		throw error;
	}
}

void resourcesManager::loadStatusStrapFont()
{
	if (!statusStrapFont->loadFromFile("resources/fonts/Aller_Rg.ttf"))
	{
		std::string error = "Unable to load font for loadStatusStrapFont.\n";
		throw error;
	}
}

void resourcesManager::loadMenuGraphicsTexture()
{
	if (!menuGraphicsTexture->loadFromFile("resources/textures/menuGraphics.png"))
	{
		std::string error = "Unable to load texture for menuGraphics2.\n";
		throw error;
	}
}

void resourcesManager::loadMenuTiteFont()
{
	if (!menuTitleFont->loadFromFile("resources/fonts/Slackey.ttf"))
	{
		std::string error = "Unable to load font for menuTitleFont.\n";
		throw error;
	}
}

void resourcesManager::loadMenuOptionsFont()
{
	if (!menuOptionsFont->loadFromFile("resources/fonts/adamwarrenpro.ttf"))
	{
		std::string error = "Unable to load font for menuOptionsFont.\n";
		throw error;
	}
}

void resourcesManager::loadMenuGraphicsTexture2()
{
	if (!menuGraphicsTexture2->loadFromFile("resources/textures/menuGraphics2.png"))
	{
		std::string error = "Unable to load texture for menuGraphics2.\n";
		throw error;
	}
}

void resourcesManager::loadMenuControllInfoTexture()
{
	if (!menuControlInfoTexture->loadFromFile("resources/textures/controll.png"))
	{
		std::string error = "Unable to load texture for menuControlInfo.\n";
		throw error;
	}
}

void resourcesManager::loadBonusTextureArray()
{
	if (
		!(bonusTextureArray[0].loadFromFile("resources/textures/cherry.png"))
		|| !(bonusTextureArray[1].loadFromFile("resources/textures/banana.png"))
		|| !(bonusTextureArray[2].loadFromFile("resources/textures/dot.png"))
		|| !(bonusTextureArray[3].loadFromFile("resources/textures/strawberry.png"))
		)
	{
		std::string error = "Unable to load bonus texture.\n";
		throw error;
	}
}

void resourcesManager::loadGhostTextureArray()
{
	if (
		!(ghostsTextureArray[0].loadFromFile("resources/textures/redGhost.png"))
		|| !(ghostsTextureArray[1].loadFromFile("resources/textures/blueGhost.png"))
		|| !(ghostsTextureArray[2].loadFromFile("resources/textures/greyGhost.png"))
		|| !(ghostsTextureArray[3].loadFromFile("resources/textures/pinkGhost.png"))
		)
	{
		std::string error = "Unable to load ghosts texture.\n";
		throw error;
	}
}

resourcesManager& resourcesManager::getInstance()
{
	static resourcesManager obj;
	return obj;
}

void resourcesManager::loadAll()
{
	try
	{
		this->loadPacTextures();
		this->loadBallTextures();
		this->loadWallTextures();
		this->loadMapGeneratorShapeTexture();
		this->loadHeartTexture();
		this->loadStatusStrapFont();
		this->loadMenuGraphicsTexture();
		this->loadMenuGraphicsTexture2();
		this->loadMenuTiteFont();
		this->loadMenuOptionsFont();
		this->loadMenuControllInfoTexture();
		this->loadBonusTextureArray();
		this->loadGhostTextureArray();
		this->loadGateTexture();
	}
	catch (std::string error)
	{
		throw error;
	}

}

Texture* resourcesManager::getPacTexture()
{
	return pacTextureArray;
}

Texture* resourcesManager::getBallTexture()
{
	return ballTexture;
}

Texture* resourcesManager::getMapGeneratorShapeTexture()
{
	return mapGeneratorShapeTexture;
}

Texture* resourcesManager::getHeartTexture()
{
	return heartTexture;
}

Texture* resourcesManager::getMenuGraphicsTexture()
{
	return menuGraphicsTexture;
}

Texture* resourcesManager::getMenuGraphicsTexture2()
{
	return menuGraphicsTexture2;
}

Texture* resourcesManager::getMenuControlInfoTexture()
{
	return menuControlInfoTexture;
}

Texture* resourcesManager::getBonusTextureArray()
{
	return bonusTextureArray;
}

Texture* resourcesManager::getGhostsTextureArray()
{
	return ghostsTextureArray;
}

Texture* resourcesManager::getGateTexture()
{
	return this->gateTexture;
}

Font* resourcesManager::getStatusStrapFont()
{
	return statusStrapFont;
}

Font* resourcesManager::getMenuTitleFont()
{
	return menuTitleFont;
}

Font* resourcesManager::getMenuOptionsFont()
{
	return menuOptionsFont;
}

Texture* resourcesManager::getWallTexture()
{
	return wallTexture;
}
