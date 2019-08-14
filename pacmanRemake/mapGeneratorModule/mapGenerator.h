#pragma once
#include <SFML/Graphics.hpp>
#include "mapGeneratorShape.h"
#include "mapGeneratorPlacer.h"
#include "../gameObjects/wall.h"
#include <vector>
#include <fstream>
#include <iostream>
#define SIZEX 60//Rozmiar wektora wektorów
#define SIZEY 80
#define OFFSET 10 //Definuje przesuniêcie obiektów (dot. funckji setPosition) przy wype³nianiu tablicy wektorami

using namespace sf;

class mapGenerator //Klasa odpowiedzialna za generowanie okna do tworzenia mapy
{
	std::vector<std::vector<mapGeneratorShape>> shapeVector{SIZEX};
	std::vector<std::vector<mapGeneratorShape>> restoreShapeVector{SIZEX}; //Pomocniczy wektor, który zachowuje poprzedni stan mapy w wypadku pomy³ki
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
	void fillMapCreator(Texture* _texture); //Wype³nia wetktor
	void renderWindowMapCreator(); //Wysiwetla okno
	void putToFileMapCreator();
	//Wype³nianie mapy kulkami
	void renderWindowBallVectorCreator(Texture* _texture, std::string mapFile);
	void putBallVectorToFile();
	void saveLastBallVector();
	void restoreLastBallVector();
};

