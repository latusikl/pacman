#include "animationManager.h"

bool animationManager::ghostAnimation(const sf::Clock& clock, ghost& ghost)
{
	const int changeTime = 100; //Co ile wykonaæ nastêpne przesuniêcie
	bool animationEndState = false;
	
	const unsigned int endPositionY = 370; //Ostateczna pozycja Y w animacji
	const unsigned int endPositionX = 290; //Ostateczna pozycja X w animajci
	
	const float positionChange = 10.0f;
	
	sf::Time currentTime = clock.getElapsedTime(); //Pobranie czasu dostarczonego z funkcji main

	if ((this->lastUpdateTimeGhost.asMilliseconds() + changeTime) <= currentTime.asMilliseconds())//Zmiana Polo¿enia je¿eli mina³ odpowiedni czas
	{
		sf::Vector2f currentPosition = ghost.getPosition(); //Obecne po³o¿enie 
		sf::Vector2f nextPosition = currentPosition; //Nastêpne po³o¿enie


		//Ruch do góry
		if (currentPosition.x == endPositionX && currentPosition.y > endPositionY)
			nextPosition.y -= positionChange;
		//Ruch w prawo dla duszka z lewej strony
		else if (currentPosition.y == ghost.getStartPosition().y && currentPosition.x < endPositionX)
			nextPosition.x += positionChange; //Przesuñ w prawo
		//Ruch w lewo dla duszka z prawej strony
		else if (currentPosition.y == ghost.getStartPosition().y
			&& currentPosition.x > endPositionX)
			nextPosition.x -= positionChange; //Przesuñ w lewo
		//Sygnalizuje koniec animacji
		else if (currentPosition.y == endPositionY)
		{
			animationEndState = true;
		}
		ghost.changePosition(nextPosition); //Przemieszczenie duszka

		this->lastUpdateTimeGhost = currentTime; //Zapisanie ostatniego czasu
	}

	return animationEndState;
}

animationManager& animationManager::getInstance()
{
	static animationManager obj;
	return obj;
}

void animationManager::GhostAnimationOn()
{
	this->runStartAnimation0 = true;
}

void animationManager::GhostAnimationRunner(const sf::Clock& clock, std::vector<ghost>& ghostVector)
{
	if (ghostVector.size() == 4)
	{
		if (this->runStartAnimation0)
		{
			bool endAnimation = this->ghostAnimation(clock, ghostVector[0]);
			if (endAnimation)
			{
				this->runStartAnimation0 = false;
				this->runStartAnimation1 = true;
			}
		}
		else if (this->runStartAnimation1)
		{
			bool endAnimation = this->ghostAnimation(clock, ghostVector[1]);
			if (endAnimation)
			{
				this->runStartAnimation1 = false;
				this->runStartAnimation2 = true;
			}
		}
		else if (this->runStartAnimation2)
		{
			bool endAnimation = this->ghostAnimation(clock, ghostVector[2]);
			if (endAnimation)
			{
				this->runStartAnimation2 = false;
				this->runStartAnimation3 = true;
			}
		}
		else if (this->runStartAnimation3)
		{
			bool endAnimation = this->ghostAnimation(clock, ghostVector[3]);
			if (endAnimation)
				this->runStartAnimation3 = false;
		}
	}
}

bool animationManager::getAnimationStatus(unsigned int ghostNumber)
{
	switch (ghostNumber)
	{
	case 0:
		return !this->runStartAnimation0;
	case 1:
		return (!this->runStartAnimation1 && !this->runStartAnimation0);
	case 2:
		return (!this->runStartAnimation2 && !this->runStartAnimation1 && !this->runStartAnimation0);
	case 3:
		return (!this->runStartAnimation3 && !this->runStartAnimation2 && !this->runStartAnimation1 && !this->runStartAnimation0);
	default:
		return false;
	}
}

bool animationManager::checkBonusBlinking(sf::Time currentTime)
{
	const unsigned short drawingTime = 700;
	const unsigned short notDrawingTime = 100;

	if ((this->lastUpdateTimeBlink.asMilliseconds() + drawingTime) <= currentTime.asMilliseconds())	//Przez jaki czas maj¹ byæ widoczne
	{
		this->lastUpdateTimeBlink = currentTime; //Przypisanie czasu rysowania do zapisanego czasu
		this->drawBonus = false;
	}
	else if ((this->lastUpdateTimeBlink.asMilliseconds() + notDrawingTime) <= currentTime.asMilliseconds())	//Przez jaki czas maj¹ byæ nie widoczne
	{
		this->drawBonus = true;
	}

		return this->drawBonus;
}

bool animationManager::checkSpecialBonusDrawing(unsigned int score, bool isDestroyed)
{
	if (!isDestroyed) //Istnieje na mapie
		return true;
	else if (isDestroyed && score == 1000)//Nie istnieje i wynik 1000
		return true;
	else if (isDestroyed && ((score % 2000) == 0))//Nie istnieje i modulo 2000 wyniku rowne 0
		return true;
	else
		return false;
}

animationManager::animationManager()
	:runStartAnimation0(false), runStartAnimation1(false), runStartAnimation2(false), runStartAnimation3(false),drawBonus(true)
{
}
