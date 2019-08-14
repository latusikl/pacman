#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <vector>
#include <regex>

#include "../gameObjects/ball.h"
#include "../gameObjects/pacman.h"
#include "../gameObjects/bonus.h"
#include "../gameObjects/ghost.h"
#include "../gameObjects/wall.h"

#include "../windowBoards/statusStrapBoard.h"
#include "../windowBoards/menuBoard.h"
#include "../windowBoards/scoreBoard.h"
#include "../windowBoards/gameOverBoard.h"

#include "../templateFunctions/vectorRemoverTemplate.h"

#include "collisionTests.h"
#include "animationManager.h"
#include "collisionManager.h"

using namespace sf;
class windowManager
{
	//Funkcja wyswietla podmenu z kontrola pacmana
	void makeSubMenu(sf::RenderWindow& mainWindow, Sprite controlInfo, Text back);
	
	//Funkcja wyswietla podmenu z informacjami ogolnymi
	void makeSubMenu(sf::RenderWindow& mainWindow, Text generalInfo, Text back);

	
	


	windowManager() = default;

public:
	static windowManager& getInstance();
	windowManager(const windowManager& obj) = delete;
	windowManager& operator=(const windowManager& obj) = delete;


	~windowManager()=default;

	//Funkcja wyswietla menu glowne
	void makeMenu(sf::RenderWindow& mainWindow, sf::Texture* menuGraphicsTexture, sf::Texture* menuGraphicsTexture2, sf::Texture* controlTexture, sf::Font* titleFont, sf::Font* optionsFont);

	//Tworzy tablice wynikow
	void makeScoreBoard(sf::RenderWindow& mainWindow, sf::Font* titleFont, sf::Font* optionsFont, unsigned int playerScore, const std::string& playerName, const std::string& fileName);

	//Tworzy ekran koncowy przed tablica wynikow
	//Zwraca wporwadzone imie gracza
	std::string makeOverBoard(sf::RenderWindow& mainWindow, sf::Font* titleFont, sf::Font* optionsFont, unsigned int playerScore, sf::Clock clock);

	//Funkcja wyswietla w dostarczonym oknie grê
	//Dostarczone okno powinno mieæ odpowiednie rozmiary
	void makeGameWindow(RenderWindow& mainWindow, pacman& pac, std::vector<ball>& ballVector, std::vector<wall>& wallVector, std::vector<bonus>& bonusVector, bonus& specialBonus,std::vector <ghost>& ghostVector,statusStrapBoard& strap, sf::Clock& clock);


};

