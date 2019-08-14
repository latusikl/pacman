#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class statusStrapBoard : public sf::Drawable
{
	 //Ilosc rysowanych zyc
	sf::Text score; //Wyswietla  wynik
	sf::Font* font; //Czcionka wyswietlanego wyniku
	std::vector<sf::Sprite> lifes; //Wetkor przechowujacy zycia
	sf::Texture* texture; //Tekstura serca

	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;


public:
	//Konstruktory i destruktor
	statusStrapBoard(float scoreX, float scoreY, unsigned int charSize,float firstLifeX, float firstLifeY,float spacing ,sf::Font* _font, sf::Texture* _texture, unsigned int lifesAmount = 3);
	statusStrapBoard()=delete;
	~statusStrapBoard()=default;
	void update(unsigned int pacmanScore, unsigned short pacmanLifes);
};

