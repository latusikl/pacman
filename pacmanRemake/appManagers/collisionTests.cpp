#include "collisionTests.h"

collision::collision()
	:isColliding(false),left(false),right(false),top(false),bottom(false)
{
}

void collision::checkCollision(const sf::FloatRect& pacmanRect,const sf::FloatRect& collidingObject)
{
	if (collidingObject.intersects(pacmanRect))
		isColliding = true;
}

void collision::checkSideCollision(const sf::FloatRect& movingObjRect, const sf::FloatRect& collidingObject)
{
	//Po�o�enie przy nast�pnym ruchu w lewo
	sf::FloatRect pacmanRectLeft = movingObjRect;
	pacmanRectLeft.left -= overtake;
	
	//Po�o�enie przy nast�pnym ruchu w prawo
	sf::FloatRect pacmanRectRight = movingObjRect;
	pacmanRectRight.width += overtake;

	//Po�o�enie przy nast�pnym ruchu w g�r�
	sf::FloatRect pacmanRectTop = movingObjRect;
	pacmanRectTop.top -= overtake;

	//Po�o�enie przy nast�pnym ruchu w d�
	sf::FloatRect pacmanRectBottom = movingObjRect;
	pacmanRectBottom.height += overtake;

	//Sprawdzenie czy zachodzi kolizja przy nast�pnym ruchu w lewo
	if (pacmanRectLeft.intersects(collidingObject))
		left = true;
	
	//Sprawdzenie czy zachodzi kolizja przy nast�pnym ruchu w prawo
	if (pacmanRectRight.intersects(collidingObject))
		right = true;

	//Sprawdzenie czy zachodzi kolizja przy nast�pnym ruchu w g�r�
	if (pacmanRectTop.intersects(collidingObject))
		top = true;

	//Sprawdzenie czy zachodzi kolizja przy nast�pnym ruchu w d�
	if (pacmanRectBottom.intersects(collidingObject))
		bottom = true;
	
	//Je�eli jest dowolna kolizja ustawiam dodatkowy znacznik
	if (left || right || top || bottom)
		isColliding = true;
}

void collision::clear()
{
	this->isColliding = false;
	this->left = false;
	this->right = false;
	this->top = false;
	this->bottom = false;
}

