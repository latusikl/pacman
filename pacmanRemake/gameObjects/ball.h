#pragma once
#include "gameShape.h"
#include <fstream>
#include <string>

//Klasa reprezentuj¹ca pokarm dla Pacmana
class ball : public gameShape
{
	bool destroyed = false; //Zmienna przechowuj¹ca informacje o gotowoœci obiektu do usuniêcia (po kolizji z pacmanem)
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

