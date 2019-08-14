#pragma once

#include<SFML/Graphics.hpp>

#include <vector>

#include "../gameObjects/ghost.h"


//Class is responsible for handling simple animations used in game.
class animationManager
{
	sf::Time lastUpdateTimeGhost;
	sf::Time lastUpdateTimeBlink;

	//For ghost animation
	bool runStartAnimation0;
	bool runStartAnimation1;
	bool runStartAnimation2;
	bool runStartAnimation3;
	
	bool drawBonus;


	//Function is responsible for making ghost animation (getting out of "cage").
	bool ghostAnimation(const sf::Clock& clock, ghost& ghost);

	animationManager();

public:
	
	static animationManager& getInstance();
	animationManager(const animationManager& obj) = delete;
	animationManager& operator=(const animationManager& obj) = delete;
	
	void GhostAnimationOn();
	//Function is responsible for running ghost animation (getting out of "cage").
	void GhostAnimationRunner(const sf::Clock& clock, std::vector<ghost>& ghostVector);
	//Function retuns value which signal end of animation for particular ghosts.
	bool getAnimationStatus(unsigned int ghostNumber);


	//Funkcja sprawdza czy nale¿y wyœwietlaæ bonus specjalny
	//Zale¿nie od aktualnego wyniku gracza
	bool checkBonusBlinking(sf::Time currentTime);

	//Funkcja sprawdza warunek dla migania zwyk³ych bonusów
	//Warunek oparty jest na czasie
	//Modyfikuje przekazany przez referencjê zapisany czas
	bool checkSpecialBonusDrawing(unsigned int score, bool isDestroyed);
	
	~animationManager() = default;
};

