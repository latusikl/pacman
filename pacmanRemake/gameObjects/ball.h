#pragma once
#include "gameShape.h"
#include <fstream>
#include <string>

//Klasa reprezentuj�ca pokarm dla Pacmana
class ball : public gameShape
{
	bool destroyed = false; //Zmienna przechowuj�ca informacje o gotowo�ci obiektu do usuni�cia (po kolizji z pacmanem)
public:
	//Konstruktory i destruktor
	ball()=delete;
	ball(float x, float y, sf::Texture* _texture);
	~ball()=default;
	

	//float getLeftBoundry();
	//float getRightBoundry();
	//float getTopBoundry();
	//float getBottomBoundry();
	
	
	void destroy();//Sygnalizowanie zniszczenia obiektu
	bool isDestroyed();//Sprawdza czy obiekt jest przeznaczony do usuniecia
};

