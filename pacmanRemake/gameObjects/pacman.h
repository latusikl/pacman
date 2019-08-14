#pragma once
#include "gameShape.h"
#include "bonusType.h"

enum textureType { stop, right, right2, left, left2, top, top2, bottom, bottom2 }; //Rozoroznia typ uzywanej obecnie tekstury Pacmana
enum movemetDirection { LEFT, RIGHT, TOP, BOTTOM }; //Rozroznia kierunek ruchu Pacmana
enum pointIncreaser { cherryCollision, bananaCollision, dotCollision, strawberryCollision, ballCollision, unknown }; //Rozroznia powod zwiekszenia ilosci punktow Pacmana


																													 
																													
//Klasa odpowiada za zarz¹dzanie i rysowanie postaci gracza (Pacmana)
class pacman: public gameShape
{
	const float pacmanDisplacement = { 10.0f }; //Wartosæ prêdkoœci
	sf::Vector2f velocity; //Wketor prêdkoœci z³o¿ony z 2 floatów, odpowiada 2 osiom
	unsigned int score; //Ilosc punktow zebranych przez gracza
	unsigned short lifes; //Ilosc zyc pacmana+
	const int changeTime = 70; //Roznica czasu miedzy zmianami polo¿enia changeTime dla zmiany simulateMove jest jej wielokrotnoœci¹
	textureType currentTexture;
	sf::Time lastTextureChangeTime;
	sf::Time lastUpdateTime;
public:
	//Konstruktory i destruktor
	pacman(float x,float y, sf::Texture* _texture, sf::Clock& clock);
	pacman() = delete;
	~pacman() = default;
	
	//Pojedyncze granice obiektu
	float getLeftBoundry();//Lewa granica obiektu
	float getRightBoundry();//Prawa granica obiektu
	float getTopBoundry();//Górna granica obiektu
	float getBottomBoundry();//Dolna granica obiektu

	sf::Vector2f getPos();



	void simulateMove(sf::Clock clock, movemetDirection type); //Funkcja odpowiada za symulacjê wygladu ruchu pacmana w odpowiednim kierunku (okreslony przez textureType)
	void update(bool leftCollision, bool rightCollision, bool topCollision, bool bottomCollision,sf::Clock& clock); //Metoda zmienia po³o¿enie obiektu w oknie

	//Obsluga wyniku gracza
	unsigned int getScore() const; //Zwraca wartoœæ wyniku
	void increaseScore(pointIncreaser type); //Zmienia wartoœæ wyniku o wartosc zalezna od powodu zmiany
	static pointIncreaser translateBonusType(bonusType bonus); //T³umaczy typ bonusa na typ zwiêkszenia iloœci punktów
	
											 
											 //Obsluga zyc gracza
	unsigned short getLifes() const; //Zwraca ilosc zyc gracza
	void decreaseLifes(); //Zmiejsza ilosc pozostalych zyc gracza


};

