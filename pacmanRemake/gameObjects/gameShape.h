#pragma once
#include <SFML/Graphics.hpp>

//Wirtualna klasa zawierająca wspólne metody dla obiektów wykorzystywanych w grze.

class gameShape : public sf::Drawable //Klasa traktowana jako możliwa do rysowania
{
protected:
	gameShape()=delete;
	
	
	sf::Sprite sprite;
	sf::FloatRect boundries; //AABB obiketu
	sf::Texture* texture; //Wskaźnik na teksture/tablice tekstur zaleznie od klasy
	
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override; //Nadpisanie metody wyświetlającej obiekt w oknie z klasy Drawable

public:
	gameShape(float x, float y, sf::Texture* _texture); //Umieszcza obiekt na mapie i wczytuje teksturę do obiektu
	void updateBoundries(); //Fukcja zwraca gracnice obietu wypełniając obiekt boundries
	sf::FloatRect getBoundries()const; //Zwraca AABB otaczające obiekt
	
	
	
	~gameShape() = 0;
};

