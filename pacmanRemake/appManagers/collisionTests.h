#pragma once
#include <SFML/Graphics.hpp>

//Klasa zawiera metody odopiwedzialne za wykrywanie kolizji 
class collision
{
	const float overtake = 10.0f; //Zmiana po�o�enia pacmana 
	//Pozwala sprawdza� przed wykoaniniem ruchu gdzie nast�pi kolizja. Powinna odpowiada� pr�dko�ci pacmana.
public:
	bool isColliding; //Znacznik kolizji ustawiany przez wszystkie funkcje obslugujace kolizje
	bool left; //Znacznik kolizji z lewej ustawiany przez funkcje checkSideCollision
	bool right; //Znacznik kolizji z prawej ustawiany przez funkcje checkSideCollision
	bool top; //Znacznik kolizji od gory ustawiany przez funkcje checkSideCollision
	bool bottom; //Znacznik kolizji od gory ustawiany przez funkcje checkSideCollision

	collision();
	~collision() = default;

	//Sprawdza og�lnie kolizj� 2 bry� brzegowych
	void checkCollision(const sf::FloatRect& pacmanRect, const sf::FloatRect& collidingObject);

	//Funckcja do sprawdzania kolizji ewentualnych nast�pnych po�o�e� pacmana z �cianami
	void checkSideCollision(const sf::FloatRect& movingObjRect,const sf::FloatRect& collidingObject);

	template <typename T>
	void checkSideCollisionVect(const sf::FloatRect& movingObjRect,const std::vector <T>& vector)
	{
		for (auto& it : vector)
			this->checkSideCollision(movingObjRect, it.getBoundries());
	}

	//Przywraca pocz�tkowy stan obiektu (ustawia wszsytkie kolizje na flase)
	void clear();

};
