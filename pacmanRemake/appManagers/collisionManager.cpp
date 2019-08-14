#include "collisionManager.h"

collisionManager& collisionManager::getInstance()
{
	static collisionManager obj;
	return obj;
}

void collisionManager::PacBonusCollsion(pacman& pac, std::vector<bonus>& bonusVector)
{
	collision collisionChecker;
	for (auto& it : bonusVector)
	{
		collisionChecker.checkCollision(pac.getBoundries(), it.getBoundries());
		if (collisionChecker.isColliding)
		{
			it.destroy();//Zmiana stanu obiektu na gotowy do usuniecia
			pac.increaseScore(pacman::translateBonusType(it.getTypeOfBonus()));//Inkrementacja wyniku
		}
		collisionChecker.clear();
	}
}

void collisionManager::PacSpecialBonusCollision(pacman& pac, bonus& specialBonus)
{
	collision collisionChecker;
	
	collisionChecker.checkCollision(pac.getBoundries(), specialBonus.getBoundries());
	if (collisionChecker.isColliding)//Je¿eli by³a kolizja
	{
		pac.increaseScore(pacman::translateBonusType(specialBonus.getTypeOfBonus())); //Zmien wynik gracza 
		specialBonus.destroy(); //Zniszcz obiekt
		specialBonus.changeTextureType(bonus::randomBonusType()); //Zmien typ bonusa
	}
}

collision collisionManager::PacGhostCollision(pacman& pac, std::vector <ghost>& ghostVector,animationManager& animationMan)
{
	collision collisionChecker;
	for (auto& it : ghostVector)
		collisionChecker.checkCollision(pac.getBoundries(), it.getBoundries());
	
	if (collisionChecker.isColliding)
	{
		pac.decreaseLifes();

		for (auto& it : ghostVector)
			it.setStartPosition();
		animationMan.GhostAnimationOn();
	}


	return collisionChecker;
}

void collisionManager::PacBallCollision(pacman& pac, std::vector<ball>& ballVector)
{
	for (auto& it : ballVector)
	{
		collision pacBallCollision;
		pacBallCollision.checkCollision(pac.getBoundries(), it.getBoundries()); //Sprawdzanie kolizji
		if (pacBallCollision.isColliding)
		{
			it.destroy();//Zmiana stanu obiektu na gotowy do usuniecia
			pac.increaseScore(ballCollision);//Inkrementacja wyniku
		}
	}
}

void collisionManager::GhostWallCollision(std::vector<ghost>& ghostVector, std::vector<wall>& wallVector, animationManager& animationMan,sf::Clock clock)
{
	collision collisionChecker;
	if (animationMan.getAnimationStatus(0))//Dopiero po zakoñczeniu animacji
	{
		collisionChecker.checkSideCollisionVect(ghostVector[0].getBoundries(), wallVector);
		ghostVector[0].update(collisionChecker.left, collisionChecker.right, collisionChecker.top, collisionChecker.bottom, clock);
	}
	collisionChecker.clear();
	if (animationMan.getAnimationStatus(1))//Dopiero po zakoñczeniu animacji
	{
		collisionChecker.checkSideCollisionVect(ghostVector[1].getBoundries(), wallVector);
		ghostVector[1].update(collisionChecker.left, collisionChecker.right, collisionChecker.top, collisionChecker.bottom, clock);
	}
	collisionChecker.clear();
	if (animationMan.getAnimationStatus(2))//Dopiero po zakoñczeniu animacji
	{
		collisionChecker.checkSideCollisionVect(ghostVector[2].getBoundries(), wallVector);
		ghostVector[2].update(collisionChecker.left, collisionChecker.right, collisionChecker.top, collisionChecker.bottom, clock);
	}
	collisionChecker.clear();
	if (animationMan.getAnimationStatus(3))//Dopiero po zakoñczeniu animacji
	{
		collisionChecker.checkSideCollisionVect(ghostVector[3].getBoundries(), wallVector);
		ghostVector[3].update(collisionChecker.left, collisionChecker.right, collisionChecker.top, collisionChecker.bottom, clock);
	}
}

collision collisionManager::PacWallCollision(const pacman& pac, const std::vector<wall>& wallVector)
{
	collision collisionChecker;
	collisionChecker.checkSideCollisionVect<wall>(pac.getBoundries(), wallVector);
	return  collisionChecker;
}
