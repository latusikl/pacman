#pragma once
#include "gameShape.h"
#include <fstream>
#include <string>
//Klasa odpowiedzialna za rysowanie œcian
//Dziedziczy z wirtualnej klasy gameShape
class wall: public gameShape 
{
public:
	//Konstruktory i destruktor
	wall(float x, float y, sf::Texture* _texture);
	wall()=delete;
	~wall() = default;
	void changeTexture(sf::Texture* newTexture);

	//float getLeftBoundry();
	//float getRightBoundry();
	//float getTopBoundry();
	//float getBottomBoundry();

	
};

