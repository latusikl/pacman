#include "pacman.h"



pacman::pacman(float x, float y,sf::Texture* _texture,sf::Clock& clock)
	:gameShape(x,y,_texture),score(0),lifes(3),currentTexture(stop)
{
	this->lastTextureChangeTime = clock.getElapsedTime(); //Set the time variable
}


float pacman::getLeftBoundry()
{
	updateBoundries();//Uaktualnienie po³o¿enie obiektu przed pobraniem danych
	return boundries.left;
}

float pacman::getRightBoundry()
{
	updateBoundries();//Uaktualnienie po³o¿enie obiektu przed pobraniem danych
	return boundries.left + boundries.width;
}

float pacman::getTopBoundry()
{
	updateBoundries();//Uaktualnienie po³o¿enie obiektu przed pobraniem danych
	return boundries.top;
}

float pacman::getBottomBoundry()
{
	updateBoundries(); //Uaktualnienie po³o¿enie obiektu przed pobraniem danych
	return boundries.top+boundries.height;
}

sf::Vector2f pacman::getPos()
{
	return sprite.getPosition();
}

void pacman::simulateMove(sf::Clock clock, movemetDirection type)
{
	sf::Time currentTime = clock.getElapsedTime(); //Pobranie czasu dostarczonego z funkcji main
	
	if ((lastTextureChangeTime.asMilliseconds() + 2.5*this->changeTime) <= currentTime.asMilliseconds())//Zmiana Tekstury je¿eli mina³ odpowiedni czas
	{
		textureType texture1=stop;
		textureType texture2=stop;

		//Ustawienie odpowiednich indeksow w tablicy tekstur
		//Zaleznie od przypadku ruchu pobieranego z funkcji update
		if (type == LEFT)
		{
			texture1 = left;
			texture2 = left2;
		}
		else if (type==RIGHT)
		{
			texture1 = right;
			texture2 = right2;
		}
		else if (type == TOP)
		{
			texture1 = top;
			texture2 = top2;
		}
		else if (type == BOTTOM)
		{
			texture1 = bottom;
			texture2 = bottom2;
		}
		
		//Zmiana tekstury przy ruchu
		if (currentTexture != texture1) //Jezeli porzednio nie byla juz tekstura dla ruchu w lewo lub byla 2ga
		{
			sprite.setTexture(texture[texture1]); //UStawienie tekstury
			this->currentTexture = texture1; //Przypisanie 
		}
		else
		{
			sprite.setTexture(texture[texture2]);
			this->currentTexture = texture2;	
		}
		
		this->lastTextureChangeTime = currentTime; //Aktualizacja czasu ostatniej zmiany tekstur
	}
}

void pacman::update(bool leftCollision, bool rightCollision, bool topCollision, bool bottomCollision,sf::Clock& clock)
{
	sf::Time currentTime = clock.getElapsedTime(); //Pobranie czasu dostarczonego z funkcji main
	
	if ((lastUpdateTime.asMilliseconds() + this->changeTime) <= currentTime.asMilliseconds())//Zmiana Po³o¿enia po odpowiednim czasie, reguluje predkosc ruchu pacmana
	{
		//W celu wykoania ruchu musi zostaæ wciœniêty odpowiedni klawisz
		//Ruch pacmana nie spowoduje kolizji ze œcian¹ (znaczniki kolizji) i wyjœcia poza okno
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !leftCollision && getLeftBoundry() > 0) //W lewo
		{

			velocity.x = -pacmanDisplacement;//Zmiana predkosci
			this->simulateMove(clock, LEFT);//Zmiana tekstury (symulacja ruchu)
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !rightCollision && getRightBoundry() < 600) //W prawo
		{
			velocity.x = pacmanDisplacement;//Zmiana predkosci
			this->simulateMove(clock, RIGHT);//Zmiana tekstury (symulacja ruchu)
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !topCollision && getTopBoundry() > 0) //Gora
		{
			velocity.y = -pacmanDisplacement;//Zmiana predkosci
			this->simulateMove(clock, TOP);//Zmiana tekstury (symulacja ruchu)
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !bottomCollision && getBottomBoundry() < 800) //Dol
		{
			velocity.y = pacmanDisplacement;//Zmiana predkosci
			this->simulateMove(clock, BOTTOM);//Zmiana tekstury (symulacja ruchu)
		}
		else //Zatrzymanie
		{
			velocity.y = 0;//Zmiana predkosci
			velocity.x = 0;//Zmiana predkosci


			this->sprite.setTexture(texture[stop]);//Tekstura dla stojacego pacmana
			this->currentTexture = stop; //Zapamietanie obecnej tekstury
		}

		//Uniemo¿liwia przypadkowy ruch po skosie
		if (velocity.x != 0 && velocity.y != 0)
		{
			velocity.y = 0;
			velocity.x = 0;
		}

		sprite.move(velocity);//Wykonanie ruchu obiektem
		updateBoundries();//Uaktualnia polozenie AABB zapisanego w zmiennej boundries

		this->lastUpdateTime = currentTime; //Aktualizacja czasu ostatniej zmiany tekstur
	}
}

unsigned int pacman::getScore() const
{
	return this->score;
}

void pacman::increaseScore(pointIncreaser type)
{
	switch (type)
	{
	case ballCollision:
		this->score += 50;
		break;
	case cherryCollision:
		this->score += 200;
		break;
	case bananaCollision:
		this->score += 400;
		break;
	case dotCollision:
		this->score += 100;
		break;
	case strawberryCollision:
		this->score += 600;
		break;
	case unknown:
		break;
	default:
		break;
	}
}

pointIncreaser pacman::translateBonusType(bonusType bonus)
{
	switch (bonus)
	{
	case dot:
		return dotCollision;
	case banana:
		return bananaCollision;
	case cherry:
		return cherryCollision;
	case strawberry:
		return strawberryCollision;
	default:
		return unknown;
	}
	return unknown;
}

unsigned short pacman::getLifes() const
{
	return lifes;
}

void pacman::decreaseLifes() 
{
	this->lifes -= 1;
}

