#include "menuBoard.h"



void menuBoard::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(garphics[0], state);
	target.draw(garphics[1], state);
	target.draw(title, state);
	target.draw(start, state);
	target.draw(about, state);
	target.draw(control, state);
}

void menuBoard::setPosition()
{
	//Pozycja
	title.setPosition(50.0f, 30.0f);
	
	garphics[0].setPosition(0.0f, 200.0f);
	
	start.setPosition(220.0f, 350.0f);
	
	about.setPosition(215.0f, 450.0f);
	
	control.setPosition(180.0f, 550.0f);
	
	garphics[1].setPosition(0.0f, 700.0f);
	
	controlInfo.setPosition(0.0f, 100.0f);
	
	generalInfo.setPosition(60, 300.0f);
	
	back.setPosition(235.0f, 750.0f);
}

void menuBoard::setColor()
{
	//Kolor
	title.setFillColor(sf::Color::Yellow);
	start.setFillColor(sf::Color::Blue);
	about.setFillColor(sf::Color::Blue);
	control.setFillColor(sf::Color::Blue);
	generalInfo.setFillColor(sf::Color::White);
	back.setFillColor(sf::Color::Blue);
}

void menuBoard::setText()
{
	title.setString("PACMAN");
	title.setCharacterSize(100);
	start.setString("Start");
	start.setCharacterSize(45);
	control.setString("Control");
	control.setCharacterSize(45);
	about.setString("About");
	about.setCharacterSize(45);
	sf::String info = "This game has been created in order \n to get required credit of a subject \n called Basic of Programming 4. \n Subject is being lead at \n Silesian Univeristy of Technology \n as part of Computer Science field of study.\n \n Author : Lukasz Latusik";
	generalInfo.setString(info);
	generalInfo.setCharacterSize(20);
	back.setString("BACK");
	back.setCharacterSize(45);
}

menuBoard::menuBoard(sf::Texture* menuGraphicsTexture, sf::Texture* menuGraphicsTexture2,sf::Texture* controlTexture,sf::Font* titleFont, sf::Font* optionsFont)
{
//Tekstury
	garphics[0].setTexture(*menuGraphicsTexture);
	garphics[1].setTexture(*menuGraphicsTexture2);
	title.setFont(*titleFont);
	start.setFont(*optionsFont);
	about.setFont(*optionsFont);
	control.setFont(*optionsFont);
	controlInfo.setTexture(*controlTexture);
	back.setFont(*optionsFont);
	generalInfo.setFont(*optionsFont);
	this->setText();
	this->setPosition();
	this->setColor();
	
}

void menuBoard::sizeChangeUp(textType type)
{
	switch (type)
	{
	case startType:
		this->start.setCharacterSize(48);
		break;
	case controlType:
		this->control.setCharacterSize(48);
		break;
	case aboutType:
		this->about.setCharacterSize(48);
	}
}

void menuBoard::sizeChangeDown()
{
	this->start.setCharacterSize(45);
	this->control.setCharacterSize(45);
	this->about.setCharacterSize(45);
}

void menuBoard::sizeBackTextUp(sf::Text& _back)
{
	_back.setCharacterSize(48);
}

void menuBoard::sizeBackTextDown(sf::Text& _back)
{
	_back.setCharacterSize(45);
}

sf::FloatRect menuBoard::getStartBoundries() const
{
	return this->start.getGlobalBounds();
}

sf::FloatRect menuBoard::getControlBoundries() const
{
	return this->control.getGlobalBounds();
}

sf::FloatRect menuBoard::getAboutBoundries() const
{
	return this->about.getGlobalBounds();
}

sf::Sprite menuBoard::getControlInfo()
{
	return this->controlInfo;
}

sf::Text menuBoard::getBackText()
{
	return this->back;
}

sf::Text menuBoard::getGeneralInfoText()
{
	return this->generalInfo;
}


