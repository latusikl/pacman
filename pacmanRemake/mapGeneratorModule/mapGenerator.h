#pragma once
#include <SFML/Graphics.hpp>
#include "mapGeneratorShape.h"
#include "mapGeneratorPlacer.h"
#include "../gameObjects/wall.h"
#include <vector>
#include <fstream>
#include <iostream>
#define SIZEX 60//Rozmiar wektora wektor�w
#define SIZEY 80
#define OFFSET 10 //Definuje przesuni�cie obiekt�w (dot. funckji setPosition) przy wype�nianiu tablicy wektorami

using namespace sf;

class mapGenerator //Klasa odpowiedzialna za generowanie okna do tworzenia mapy
{
	std::vector<std::vector<mapGeneratorShape>> shapeVector{SIZEX};
	std::vector<std::vector<mapGeneratorShape>> restoreShapeVector{SIZEX}; //Pomocniczy wektor, kt�ry zachowuje poprzedni stan mapy w wypadku pomy�ki
	std::vector<mapGeneratorPlacer> ballVector;
	std::vector<mapGeneratorPlacer> restoreBallVector;
	int savedIndex=0;
	sf::Time time;
	std::vector <wall> createVector2(std::string fileName, sf::Texture* _texture);

public:
	mapGenerator() = default;
	mapGenerator(Texture* _texture);
	~mapGenerator()=default;

	//Kreowanie mapy
	void saveLastMapStateMapCreator();
	void restorePreviousStateMapCreator();
	void fillMapCreator(Texture* _texture); //Wype�nia wetktor
	void renderWindowMapCreator(); //Wysiwetla okno
	void putToFileMapCreator();
	//Wype�nianie mapy kulkami
	void renderWindowBallVectorCreator(Texture* _texture, std::string mapFile);
	void putBallVectorToFile();
	void saveLastBallVector();
	void restoreLastBallVector();
};

