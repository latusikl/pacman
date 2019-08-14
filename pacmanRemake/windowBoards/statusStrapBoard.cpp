#include "statusStrapBoard.h"
#include <string>
void statusStrapBoard::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	//Rysuje zycia
	for(auto& it:lifes)
		target.draw(it, state);
	//Rysuje wynik gracza
	target.draw(score, state);
}


statusStrapBoard::statusStrapBoard(float scoreX, float scoreY,unsigned int charSize ,float firstLifeX, float firstLifeY, float spacing ,sf::Font* _font, sf::Texture* _texture, unsigned int lifesAmount)
	:font(_font),texture(_texture)
{
	//Ustawienie rozmiaru wektora
	lifes.resize(lifesAmount);

	//Ustawianie parametrow tekstu
	score.setFont(*font); //Czcionka
	score.setPosition(scoreX, scoreY); //Polozenie
	score.setCharacterSize(charSize); //Rozmiar czcionki
	score.setString("SCORE: 0"); //Napis poczatkowy
	
	for (auto& it : lifes)
	{
		it.setPosition(firstLifeX,firstLifeY); //Pozycja grafiki serca
		it.setTexture(*texture); //Przypisanie teksury
		firstLifeX += spacing; //Przesuniecie nastepnej grafiki wzglêdem pierwszej
	}

}

//Zmaina wysiwetlanego w oknie wyniku i ilosci zyc
void statusStrapBoard::update(unsigned int pacmanScore, unsigned short pacmanLifes)
{
	//Wysiwetla nowy wynik pobrany z klasy pacman
	score.setString("SCORE: " + std::to_string(pacmanScore));

	//Usuwa z wektora nadmiarowa ilosc wyswietlanych zyc
	//Obecna ilosc zyc jest przekazywana z klasy pacman
	while (pacmanLifes < lifes.size() && lifes.size()>0)
	{
		lifes.pop_back();
	}
}
