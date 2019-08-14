
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "./appManagers/resourcesManager.h"
#include "./appManagers/windowManager.h"

#include "./templateFunctions/vectorLoaderTemplate.h"

#include "constantsDef.h"

#include "mapGeneratorModule/mapGenerator.h"

int main()
{
	sf::Clock clock;
	clock.restart();
	//Tworzenie glownego okna
	RenderWindow mainWindow(VideoMode(windowWidth, windowHeight), windowTitle);
	mainWindow.setFramerateLimit(windowFrameLimit);

	//Przygotowanie textur
	resourcesManager& programResources = resourcesManager::getInstance();
	try 
	{
		programResources.loadAll();
	}
	catch (std::string error)
	{
		std::cout << error;
		system("pause");
	}
	
	//Generowanie Mapy
	//mapGenerator map;
	//map.fillMapCreator(programResources.getMapGeneratorShapeTexture());
	//map.renderWindowMapCreator();
	//S-save
	//Z-restore
	//P-put to file
	//Right Mouse- make path
	//map.renderWindowBallVectorCreator(programResources.getWallTexture(),mapFile);
	/*S-save
	Z-restore
	Enter-place normal bonus
	P-put to file
	V-special bonus*/

	//Przygotowanie wektorów
	std::vector <wall> wallVector;
	std::vector <ball> ballVector;
	std::vector <bonus> bonusVector;
	std::vector <ghost> ghostVector;
	try
	{
		wallVector = createVector<wall>(mapFile, programResources.getWallTexture());
		ballVector = createVector<ball>(ballFile, programResources.getBallTexture());
		bonusVector = createVector<bonus>(bonusFile, programResources.getBonusTextureArray());
		ghostVector = createVector<ghost>(ghostFile, programResources.getGhostsTextureArray());
	}
	catch (std::string error)
	{
		std::cout << error << std::endl;
	}
	
	//Zmiana tekstury dla 2 fragmentów mapy tworz¹cych bramê dla duszków
	size_t size = wallVector.size();
	wallVector[size - 1].changeTexture(programResources.getGateTexture());
	wallVector[size - 2].changeTexture(programResources.getGateTexture());
	
	//Zmiana tekstur duszków Domyœlny typ to czerwony
	ghostVector[1].changeTexture(blue);
	ghostVector[2].changeTexture(gray);
	ghostVector[3].changeTexture(pink);

	pacman pac(pacmanStartX, pacmanStartY, programResources.getPacTexture(), clock);
	
	bonus specialBonus(specialBonusX, specialBonusY, programResources.getBonusTextureArray());
	specialBonus.changeTextureType(bonus::randomBonusType());
	
	statusStrapBoard strap(scoreX,scoreY,charSize,firstLifeX,firstLifeY,spacing, programResources.getStatusStrapFont(), programResources.getHeartTexture(),pac.getLifes());
	



	windowManager& Game = windowManager::getInstance();
	
	//okno menu
	Game.makeMenu(mainWindow, programResources.getMenuGraphicsTexture(),programResources.getMenuGraphicsTexture2(),programResources.getMenuControlInfoTexture() ,programResources.getMenuTitleFont(), programResources.getMenuOptionsFont());
	
	//okno gry
	Game.makeGameWindow(mainWindow, pac, ballVector, wallVector, bonusVector,specialBonus,ghostVector,strap,clock);
	
	//okno gameover
	std::string playerName;
	playerName=Game.makeOverBoard(mainWindow, programResources.getMenuTitleFont(), programResources.getMenuOptionsFont(),pac.getScore() , clock);

	//okno scoreboard
	try{ Game.makeScoreBoard(mainWindow, programResources.getMenuTitleFont(), programResources.getMenuOptionsFont(), pac.getScore(), playerName, statusStrapFile); }
	catch (std::string error)
	{
		std::cout << error;
		system("pause");
	}
	
	return 0;
}