#pragma once
#include <SFML/Graphics.hpp>

//Wirtualna klasa zawieraj�ca wsp�lne metody dla obiekt�w wykorzystywanych w grze.

class gameShape : public sf::Drawable //Klasa traktowana jako mo�liwa do rysowania
{
protected:
	gameShape()=delete;
	
	
	sf::Sprite sprite;
	sf::FloatRect boundries; //AABB obiketu
	sf::Texture* texture; //Wska�nik na teksture/tablice tekstur zaleznie od klasy
	
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override; //Nadpisanie metody wy�wietlaj�cej obiekt w oknie z klasy Drawable

public:
	gameShape(float x, float y, sf::Texture* _texture); //Umieszcza obiekt na mapie i wczytuje tekstur� do obiektu
	void updateBoundries(); //Fukcja zwraca gracnice obietu wype�niaj�c obiekt boundries
	sf::FloatRect getBoundries()const; //Zwraca AABB otaczaj�ce obiekt
	
	
	
	~gameShape() = 0;
};

