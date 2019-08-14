#pragma once
#include "gameShape.h"
#include <random>
#include <iostream>
enum ghostTextureType {red,blue,gray,pink};
enum direction { leftDir, rightDir, topDir, bottomDir, noneDir };



//Klasa reprezentuje duszki
class ghost : public gameShape
{
	const float ghostVelocity = { 10.0f }; //Wartosæ prêdkoœci
	sf::Vector2f velocity; //Wketor prêdkoœci z³o¿ony z 2 floatów, odpowiada 2 osiom
	ghostTextureType currentTexture;
	sf::Time lastUpdateTime; //Czas ostatniej aktualizacji wykorzystywany przez funkcje startAnimation oraz update
	sf::Vector2f startPosition; //First ghost position inside cage
	direction currentDirection; //Stores information about current movement direction

	static unsigned int randomNumber(const unsigned int begRange,const unsigned int endRange); //Generuje losowy numer z danego zakresu
	
	std::vector <direction> PossibleDirections(bool leftCollision, bool rightCollision, bool topCollision, bool bottomCollision); //If the opposite direction to current is possitble then it is placed at the end of vector
	bool isDirectionPossible(direction Current,const std::vector <direction>& possibleDirections); //Checks if specified dirrection is possible in this move
	bool isOppositeDirectionPossible(const std::vector <direction>& possibleDirections); //Chceks if oppossite dirrection is possible
	void setOppositeDirectionAtTheEnd(std::vector <direction>& possibleDirections); //If in vector is opposite direction to current method puts it at the end of vector
	direction randomDirection(std::vector <direction>& ppossibleDirVect); //Generates random movement direction 
	void move(direction movementDirection);


public:
	ghost() = delete;
	ghost(float x, float y, sf::Texture* _texture);
	~ghost() = default;

	//Zmienia bazowa teksture
	void changeTexture(ghostTextureType textureType);
	void changePosition(sf::Vector2f newPosition);

	//Obecne polo¿enie na mapie.
	sf::Vector2f getPosition();
	sf::Vector2f getStartPosition();
	//Pojedyncze granice obiektu
	float getLeftBoundry();//Lewa granica obiektu
	float getRightBoundry();//Prawa granica obiektu
	float getTopBoundry();//Górna granica obiektu
	float getBottomBoundry();//Dolna granica obiektu

	void setStartPosition(); //Ustawia duszka w pozycji startowej
	
	bool startAnimation(const sf::Clock& clock); //Animacja wyjœcia z miejsca startowego funkcja powinna byæ poprzedzona ustawieniem pacmana w pozycji statrtowej

	void update(bool leftCollision, bool rightCollision, bool topCollision, bool bottomCollision, sf::Clock& clock);


	
};

