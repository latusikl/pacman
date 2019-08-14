#pragma once
#include <SFML/Graphics.hpp>
#include <string>
//Klasa zarz¹dzaj¹ca tekstami dla okna konca gry
class gameOverBoard:public sf::Drawable
{
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	
	void setPositionScoreBoard();//Ustawia pozycjê teksow w oknie
	void setTextsScoreBoard(sf::Font* titleFont, sf::Font* textFont, unsigned int playerScore);


	sf::Text gameOver;
	sf::Text yourResult;
	sf::Text resultValue;
	sf::Text yourName;
	sf::Text rules;
	
	
	bool goodName = false;
public:
	sf::Text wrongName;
	sf::Text name;
	gameOverBoard(sf::Font* titleFont, sf::Font* textFont, unsigned int playerScore);
	
	void setName(std::string nameString);

	~gameOverBoard();
};

