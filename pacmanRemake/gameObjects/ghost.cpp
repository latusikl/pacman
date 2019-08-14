#include "ghost.h"

unsigned int ghost::randomNumber(const unsigned int begRange, const unsigned int endRange)
{
	std::random_device rdevice; //Losuje liczbê pseudolosowa
	std::mt19937 generator(rdevice()); //Losuje liczbê losow¹ na podstawie ziarna z rdevice
	std::uniform_int_distribution<unsigned int> distribution (begRange, endRange); //Losuje inta w podanym zakresie bazuj¹c na generatorze

	return distribution(generator);
}

std::vector<direction> ghost::PossibleDirections(bool leftCollision, bool rightCollision, bool topCollision, bool bottomCollision)
{
	std::vector<direction> possibleDirections;
	if (!leftCollision)
		possibleDirections.push_back(leftDir);
	if (!rightCollision)
		possibleDirections.push_back(rightDir);
	if(!topCollision)
		possibleDirections.push_back(topDir);
	if (!bottomCollision)
		possibleDirections.push_back(bottomDir);

	this->setOppositeDirectionAtTheEnd(possibleDirections);

	return possibleDirections;
}

bool ghost::isDirectionPossible(direction Current,const std::vector<direction>& possibleDirections)
{
	for (auto& it : possibleDirections)
	{
		if (it == Current)
			return true;
	}
	return false;
}

bool ghost::isOppositeDirectionPossible(const std::vector<direction>& possibleDirections)
{
	if (possibleDirections.size() != 0)
	{
		switch (this->currentDirection)
		{
		case leftDir:
			if (possibleDirections[possibleDirections.size() - 1] == rightDir)
				return true;
			else
				break;
		case rightDir:
			if (possibleDirections[possibleDirections.size() - 1] == leftDir)
				return true;
			else
				break;
		case topDir:
			if (possibleDirections[possibleDirections.size() - 1] == bottomDir)
				return true;
			else
				break;
		case bottomDir:
			if (possibleDirections[possibleDirections.size() - 1] == topDir)
				return true;
			else
				break;
		default:
			break;
		}
	}
	return false;
}

void ghost::setOppositeDirectionAtTheEnd( std::vector<direction>& possibleDirections)
{
	if (possibleDirections.size() != 0)
	{
		direction opposedDirection = noneDir;
		switch (this->currentDirection)
		{
		case leftDir:
			opposedDirection = rightDir;
			break;
		case rightDir:
			opposedDirection = leftDir;
			break;
		case topDir:
			opposedDirection = bottomDir;
			break;
		case bottomDir:
			opposedDirection = topDir;
			break;
		default:
			opposedDirection = noneDir;
			break;
		}

		short oppositeDirIndex = -1;

		for (unsigned int i = 0; i < possibleDirections.size(); i++)
		{
			if (possibleDirections[i] == opposedDirection)
			{
				oppositeDirIndex = i;
				break;
			}
		}

		if (oppositeDirIndex != -1) //Jezeli w wektorze wystepuje kierunek przeciwny
		{
			std::swap(possibleDirections[oppositeDirIndex], possibleDirections[possibleDirections.size() - 1]);
		}
	}
}

direction ghost::randomDirection(std::vector<direction>& possibleDirVect)
{
	const double possiblityOpositeDir = 0.05;
	
	
	int possibleDirCount = possibleDirVect.size(); //Sizeof vector possibleDirVect
	direction choosenDirection;
	
	switch (possibleDirCount)//Losowy wybór mo¿liwego kierunku ruchu
		{
		case 0:
			choosenDirection = noneDir;
			break;
		case 1:
			choosenDirection = possibleDirVect[0];
			break;
		case 2:
		{
			const unsigned int intervalBeg = 1;
			const unsigned int intervalEnd = 50;
			unsigned int randomNum = ghost::randomNumber(intervalBeg, intervalEnd);//Wybiera losowa liczbê z przedzia³u 1-50
			
			if (!this->isOppositeDirectionPossible(possibleDirVect))//Równoprawdopodbny wybór kierunku je¿eli kierunke przeciwny nie jest mo¿liwy
			{
				if (randomNum <= static_cast<int>(intervalEnd * 0.5f))
					choosenDirection = possibleDirVect[0];
				else
					choosenDirection = possibleDirVect[1];
			}
			else
			{
				unsigned int limitOpposite = static_cast <unsigned int> (possiblityOpositeDir*intervalEnd);
				
				if (randomNum < limitOpposite)
					choosenDirection = possibleDirVect[1];
				else
					choosenDirection = possibleDirVect[0];
			}
			break;
		}
		case 3:
		{
			const unsigned int intervalBeg = 1;
			const unsigned int intervalEnd = 75;
			unsigned int randomNum = ghost::randomNumber(intervalBeg, intervalEnd);//Wybiera losowa liczbê z przedzia³u 1-50

	
			if (!this->isOppositeDirectionPossible(possibleDirVect))//Równoprawdopodbny wybór kierunku je¿eli kierunke przeciwny nie jest mo¿liwy
			{
				if (randomNum <= static_cast<unsigned int>(intervalEnd / 3) ) 
					choosenDirection = possibleDirVect[0];
				else if (randomNum <= static_cast<unsigned int>(2* intervalEnd / 3))
					choosenDirection = possibleDirVect[1];
				else
					choosenDirection = possibleDirVect[2];
			}
			else
			{
				unsigned int limitOpposite = static_cast <unsigned int> (possiblityOpositeDir * intervalEnd);

				if (randomNum < limitOpposite)
					choosenDirection = possibleDirVect[2];
				else
				{
					unsigned int limitNonOpposite = static_cast <unsigned int>((intervalEnd - limitOpposite)*0.5);
					
					if (randomNum <= limitNonOpposite + limitOpposite)
						choosenDirection = possibleDirVect[1];
					else
						choosenDirection = possibleDirVect[0];
				}
			}
			break;
		}
		case 4:
		{
			const unsigned int intervalBeg = 1;
			const unsigned int intervalEnd = 100;
			unsigned int randomNum = ghost::randomNumber(intervalBeg, intervalEnd);//Wybiera losowa liczbê z przedzia³u 1-50
			
			if (!this->isOppositeDirectionPossible(possibleDirVect))//Równoprawdopodbny wybór kierunku je¿eli kierunke przeciwny nie jest mo¿liwy
			{
				if (randomNum <= static_cast<unsigned int>(intervalEnd *0.25))
					choosenDirection = possibleDirVect[0];
				else if (randomNum <= static_cast<unsigned int>(intervalEnd * 0.5))
					choosenDirection = possibleDirVect[1];
				else if (randomNum <= static_cast<unsigned int>(intervalEnd * 0.75))
					choosenDirection = possibleDirVect[2];
				else
					choosenDirection = possibleDirVect[3];
			}
			else
			{
				unsigned int limitOpposite = static_cast <unsigned int> (possiblityOpositeDir * intervalEnd);

				if (randomNum < limitOpposite)
					choosenDirection = possibleDirVect[3];
				else
				{
					unsigned int limitNonOpposite = static_cast <unsigned int>((intervalEnd - limitOpposite) / 3);

					if (randomNum <= limitNonOpposite + limitOpposite)
						choosenDirection = possibleDirVect[0];
					else if (randomNum <= limitNonOpposite*2 + limitOpposite)
						choosenDirection = possibleDirVect[1];
					else
						choosenDirection = possibleDirVect[2];
				}
			}
			break;
		}
		default:
			choosenDirection = noneDir;
			break;
		}

	return choosenDirection;
}

void ghost::move(direction movementDirection)
{
	this->velocity.y = 0;//Zmiana predkosci
	this->velocity.x = 0;//Zmiana predkosci

	switch (movementDirection) //Realizacja ruchu w wybranym kierunku
	{
	case noneDir:
		this->setStartPosition(); //Duch powraca do pozycji startowej
		break;
	case leftDir:
		velocity.x = -ghostVelocity;
		this->currentDirection = leftDir;
		break;
	case rightDir:
		velocity.x = ghostVelocity;
		this->currentDirection = rightDir;
		break;
	case topDir:
		velocity.y = -ghostVelocity;
		this->currentDirection = topDir;
		break;
	case bottomDir:
		velocity.y = ghostVelocity;
		this->currentDirection = bottomDir;
		break;
	default:
		break;
	}

	this->sprite.move(velocity); //Przemieszcza duszka
	updateBoundries();//Uaktualnia polozenie AABB zapisanego w zmiennej boundries
}

ghost::ghost(float x, float y, sf::Texture* _texture)
	:gameShape(x,y,_texture),currentTexture(red),currentDirection(noneDir)
{
	startPosition = this->getPosition();
}

void ghost::changeTexture(ghostTextureType textureType)
{
	this->sprite.setTexture(this->texture[textureType]);
	this->currentTexture = textureType;
}

void ghost::changePosition(sf::Vector2f newPosition)
{
	this->sprite.setPosition(newPosition);
	this->updateBoundries();
}

sf::Vector2f ghost::getPosition()
{
	return this->sprite.getPosition();
}

sf::Vector2f ghost::getStartPosition()
{
	return this->startPosition;
}

float ghost::getLeftBoundry()
{
	updateBoundries();//Uaktualnienie po³o¿enie obiektu przed pobraniem danych
	return boundries.left;
}

float ghost::getRightBoundry()
{
	updateBoundries();//Uaktualnienie po³o¿enie obiektu przed pobraniem danych
	return boundries.left + boundries.width;
}

float ghost::getTopBoundry()
{
	updateBoundries();//Uaktualnienie po³o¿enie obiektu przed pobraniem danych
	return boundries.top;
}

float ghost::getBottomBoundry()
{
	updateBoundries(); //Uaktualnienie po³o¿enie obiektu przed pobraniem danych
	return boundries.top + boundries.height;
}

void ghost::setStartPosition()
{
	this->sprite.setPosition(startPosition);
	this->currentDirection = noneDir;
	this->updateBoundries();
}

bool ghost::startAnimation(const sf::Clock& clock)
{
	const int changeTime = 100; //Co ile wykonaæ nastêpne przesuniêcie
	bool animationEndState = false;
	const unsigned int endPositionY = 370; //Ostateczna pozycja Y w animacji
	const unsigned int endPositionX = 290; //Ostateczna pozycja X w animajci
	const float positionChange = 10.0f;
	sf::Time currentTime = clock.getElapsedTime(); //Pobranie czasu dostarczonego z funkcji main

	if ((lastUpdateTime.asMilliseconds() + changeTime) <= currentTime.asMilliseconds())//Zmiana Polo¿enia je¿eli mina³ odpowiedni czas
	{
		sf::Vector2f currentPosition = this->getPosition(); //Obecne po³o¿enie 
		sf::Vector2f nextPosition = currentPosition; //Nastêpne po³o¿enie


		//Ruch do góry
		if (currentPosition.x == endPositionX && currentPosition.y > endPositionY)
			nextPosition.y -= positionChange;
		//Ruch w prawo dla duszka z lewej strony
		else if (currentPosition.y == startPosition.y && currentPosition.x < endPositionX)
			nextPosition.x += positionChange; //Przesuñ w prawo
		//Ruch w lewo dla duszka z prawej strony
		else if (currentPosition.y == startPosition.y
			&& currentPosition.x > endPositionX)
			nextPosition.x -= positionChange; //Przesuñ w lewo
		//Sygnalizuje koniec animacji
		else if (currentPosition.y == endPositionY)
		{
			animationEndState = true;
			this->updateBoundries(); //Uaktualnia granice po³o¿enie obietku
		}
		this->changePosition(nextPosition); //Przemieszczenie duszka

		this->lastUpdateTime = currentTime; //Zapisanie ostatniego czasu
	}

		return animationEndState;
}

void ghost::update(bool leftCollision, bool rightCollision, bool topCollision, bool bottomCollision, sf::Clock& clock)
{
	sf::Time currentTime = clock.getElapsedTime(); //Pobranie czasu dostarczonego z funkcji main
	const float changeTime = 80; //Co ile wykonywaæ ruch milisekundy


	if ((lastUpdateTime.asMilliseconds() + changeTime) <= currentTime.asMilliseconds())//Zmiana Po³o¿enia po odpowiednim czasie
	{
		int randomNumber = ghost::randomNumber(1, 10);
		std::vector<direction> possibleDirVect = PossibleDirections(leftCollision, rightCollision, topCollision, bottomCollision); //Zwraca wektor mo¿liwych kierunków ruchu
		
		if (randomNumber > 5 || !ghost::isDirectionPossible(this->currentDirection,possibleDirVect) )//Wykonaj zmiana kierunku z praw. 30% inaczej je¿eli by³ ruch to w 70% przypadków w t¹ sam¹ stronê lub gdy w ostatnim kierunku niemo¿liwy
		{
			
			direction choosenDirection = this->randomDirection(possibleDirVect);
			this->move(choosenDirection);
		}
		else
		{
			this->move(this->currentDirection);
		}
		
		this->lastUpdateTime = currentTime; //Aktualizacja czasu ostatniej zmiany tekstur
	}
}




