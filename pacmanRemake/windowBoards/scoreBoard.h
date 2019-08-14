#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <string>
//Klasa obslugujaca napisy potrzebne do zbudowania tablicy wynikow
class scoreBoard: public sf::Drawable
{
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override; //Nadpisanie metody wyœwietlaj¹cej obiekt w oknie z klasy Drawable
	sf::Text scoreBoardTexts[9]; //Przechowuje teksty u¿ywane w tablicy
	std::string scoresValue[10]; //Wczytuje wynik i nazwe gracza
public:
	void setTextsScoreBoard(sf::Font* titleFont, sf::Font* textFont,unsigned int playerScore ,std::string playerName); //Wstawia teksty i czcionki do obiektów sf::Text
	void setPositionScoreBoard();//Ustawia pozycjê teksow w oknie
	void loadFromFile(std::string fileName);//£aduje wyniki z pliku
	void saveToFile(unsigned int playerScore, std::string playerName);
	
	scoreBoard()=default;
	~scoreBoard()=default;
};

