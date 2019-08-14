#pragma once
#include <SFML/Graphics.hpp>
enum textType{startType,aboutType,controlType};

//Klasa zarzadza ustawieniami obiektow wchodzacych w sklad menu
//Umozliwa rysowanie ich w oknie
class menuBoard: public sf::Drawable
{
//Potrzebne obiekty
	sf::Sprite garphics[2]; //Grafiki pacmana widoczne w men
	sf::Sprite controlInfo; //Grafika z informacja sposobie poruszania pacmanem
	sf::Text title, start, about, control; //Tekst napisow wyswietlanych w menu
	sf::Text generalInfo; //Tekst podmenu about
	sf::Text back; //Wysiwetla napis exit
	
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override; //Umo¿liwia rysowanie klasy menu
	void setPosition();
	void setColor();
	void setText();
	
public:
	//Ustawia parametry obiektow u¿ywanych w obrebie menu
	menuBoard(sf::Texture* menuGraphicsTexture, sf::Texture* menuGraphicsTexture2,sf::Texture* controlTexture ,sf::Font* titleFont, sf::Font* optionsFont);
	void sizeChangeUp(textType type); //Powieksza zadany napis
	void sizeChangeDown(); //Przywraca poprzedni rozmiar napisow
	
	static void sizeBackTextUp(sf::Text& _back);//Powieksza napis back
	static void sizeBackTextDown(sf::Text& _back);// Przywraca poprzedni rozmiar napisu back

	//AABB napisow
	sf::FloatRect getStartBoundries() const;
	sf::FloatRect getControlBoundries() const;
	sf::FloatRect getAboutBoundries() const;

	//Zwraca elemnty potrzebne w podmenu
	sf::Sprite getControlInfo();
	sf::Text getBackText();
	sf::Text getGeneralInfoText();
	
	menuBoard()=delete;
	~menuBoard()=default;
};

