#pragma once
#include "gameShape.h"
#include <random>
#include "bonusType.h"

//Klasa reprezentuje w grze wszystkie rodzaje bonus�w. 
//Domy�lny typ bonusa przy konstrukcji to blueDot
//Istnieje mo�liwo�� zmiany przez metode changeTextureType
class bonus : public gameShape
{
	bonusType typeOfBonus;
	bool destroyed = false; //Zmienna przechowuj�ca informacje o gotowo�ci obiektu do usuni�cia (po kolizji z pacmanem
public:
	bonus() = delete;
	bonus(float x, float y, sf::Texture* _texture);
	
	void destroy();//Sygnalizowanie zniszczenia obiektu
	bool isDestroyed();//Sprawdza czy obiekt jest przeznaczony do usuniecia

//Metody potrzebne dla bonusa specjalnego	
	void changeTextureType(bonusType textureType); //Zmienia domy�lny typ bonusa
	bonusType getTypeOfBonus();//Zwraca typ bonusa przypisany do danego obiektu
	void changeToNotDestroyed();
	static bonusType randomBonusType();//Losuje jeden z 3 bonus�w specjalnych

	~bonus()=default;
};

