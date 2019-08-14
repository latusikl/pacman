#pragma once
#include <SFML/Graphics.hpp>

//Klasa zawiera metody odopiwedzialne za wykrywanie kolizji 
class collision
{
	const float overtake = 10.0f; //Zmiana po³o¿enia pacmana 
	//Pozwala sprawdzaæ przed wykoaniniem ruchu gdzie nast¹pi kolizja. Powinna odpowiadaæ prêdkoœci pacmana.
public:
	bool isColliding; //Znacznik kolizji ustawiany przez wszystkie funkcje obslugujace kolizje
	bool left; //Znacznik kolizji z lewej ustawiany przez funkcje checkSideCollision
	bool right; //Znacznik kolizji z prawej ustawiany przez funkcje checkSideCollision
	bool top; //Znacznik kolizji od gory ustawiany przez funkcje checkSideCollision
	bool bottom; //Znacznik kolizji od gory ustawiany przez funkcje checkSideCollision

	collision();
	~collision() = default;

	//Sprawdza ogólnie kolizjê 2 bry³ brzegowych
	void checkCollision(const sf::FloatRect& pacmanRect, const sf::FloatRect& collidingObject);

	//Funckcja do sprawdzania kolizji ewentualnych nastêpnych po³o¿eñ pacmana z œcianami
	void checkSideCollision(const sf::FloatRect& movingObjRect,const sf::FloatRect& collidingObject);

	template <typename T>
	void checkSideCollisionVect(const sf::FloatRect& movingObjRect,const std::vector <T>& vector)
	{
		for (auto& it : vector)
			this->checkSideCollision(movingObjRect, it.getBoundries());
	}

	//Przywraca pocz¹tkowy stan obiektu (ustawia wszsytkie kolizje na flase)
	void clear();

};
