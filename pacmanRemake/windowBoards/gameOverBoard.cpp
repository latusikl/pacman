#include "gameOverBoard.h"






void gameOverBoard::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->gameOver, state);
	target.draw(this->yourResult, state);
	target.draw(this->resultValue, state);
	target.draw(this->rules, state);
	target.draw(this->yourName, state);
}

void gameOverBoard::setPositionScoreBoard()
{

	this->gameOver.setPosition(20.0f, 80.0f); //Napis koniec gry
	this->yourResult.setPosition(20.0f, 250.0f); //Napis twoj wynik
	this->resultValue.setPosition(330.0f,260.0f); //Wartosc wyniku
	this->yourName.setPosition(20.0f,400.0f); //Napis twoje imie

	this->rules.setPosition(20.0f, 480.0f); //Zasady nazyw gracza
	this->wrongName.setPosition(330.0f, 410.0f); //Zle imie
	this->name.setPosition(330.0f, 410.0f); //Wprow nazwa gracza
}

void gameOverBoard::setTextsScoreBoard(sf::Font* titleFont, sf::Font* textFont, unsigned int playerScore)
{
	//Napis koniec gry
	this->gameOver.setCharacterSize(85);
	this->gameOver.setFillColor(sf::Color::Yellow);
	this->gameOver.setString("GAME OVER");
	this->gameOver.setFont(*titleFont);
	//Napis twoj wynik
	this->yourResult.setCharacterSize(40);
	this->yourResult.setFillColor(sf::Color::Blue);
	this->yourResult.setString("Your Result: ");
	this->yourResult.setFont(*titleFont);
	//Wartosc wyniku
	this->resultValue.setCharacterSize(30);
	this->resultValue.setFillColor(sf::Color::White);
	this->resultValue.setString(std::to_string(playerScore));
	this->resultValue.setFont(*textFont);
	//Naza gracza-napis
	this->yourName.setCharacterSize(40);
	this->yourName.setFillColor(sf::Color::Blue);
	this->yourName.setString("Your Name: ");
	this->yourName.setFont(*titleFont);
	//Warunki dla nazwy gracza
	this->rules.setCharacterSize(17);
	this->rules.setFillColor(sf::Color::Red);
	this->rules.setString("Player name reqiures   1-7   letters and   3   digits at the end.\n               Press    ENTER    to    confirm    your    name.");
	this->rules.setFont(*textFont);
	//Zla nazwa gracza
	this->wrongName.setCharacterSize(15);
	this->wrongName.setFillColor(sf::Color::Red);
	this->wrongName.setString("Wrong name!\n    Try Again.");
	this->wrongName.setFont(*textFont);
	//Pole na nazwe gracza
	this->name.setCharacterSize(30);
	this->name.setFillColor(sf::Color::White);
	this->name.setFont(*textFont);
	this->name.setString("Adammmm123");
}

gameOverBoard::gameOverBoard(sf::Font* titleFont, sf::Font* textFont, unsigned int playerScore)
{
	this->setTextsScoreBoard(titleFont, textFont,playerScore);
	this->setPositionScoreBoard();
}

void gameOverBoard::setName(std::string nameString)
{
	this->name.setString(nameString);
}

gameOverBoard::~gameOverBoard()
{
}
