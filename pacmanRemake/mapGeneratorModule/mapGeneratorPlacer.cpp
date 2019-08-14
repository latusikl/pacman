#include "mapGeneratorPlacer.h"


Vector2f mapGeneratorPlacer::getPosition()
{
	return rect.getPosition();
}

bool mapGeneratorPlacer::checkMovement()
{
	return movable;
}

bool mapGeneratorPlacer::isBonus()
{
	return bonus;
}

bool mapGeneratorPlacer::isSpecialBonus()
{
	return specialBonus;
}

void mapGeneratorPlacer::stopMovement()
{
	movable = false;
}

void mapGeneratorPlacer::update()
{
	if (movable)
	{
		if (Keyboard::isKeyPressed(Keyboard::Left) && getPosition().x >= 0) //W lewo
		{
			velocity.x = -rectVelocity;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right) && getPosition().x <= 600) //W prawo
		{
			velocity.x = rectVelocity;

		}
		//Ruch Pacmana w góre lub w dó³
		else if (Keyboard::isKeyPressed(Keyboard::Up) && getPosition().y >= 0)
		{
			velocity.y = -rectVelocity;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down) && getPosition().y <= 800)
		{
			velocity.y = rectVelocity;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Enter))
		{
			stopMovement();
		}
		else
		{
			velocity.y = 0;
			velocity.x = 0;
		}

		rect.move(velocity);
	}
}

void mapGeneratorPlacer::makeBonus()
{
	rect.setFillColor(Color::Yellow);
	this->bonus = true;
}

void mapGeneratorPlacer::makeSpecialBonus()
{
	rect.setFillColor(Color::Magenta);
	this->specialBonus = true;
}

void mapGeneratorPlacer::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(rect, state);
}

mapGeneratorPlacer::mapGeneratorPlacer()
{
	rect.setSize(size);
	rect.setFillColor(Color::Green);
	rect.setPosition(startPosition);
}

