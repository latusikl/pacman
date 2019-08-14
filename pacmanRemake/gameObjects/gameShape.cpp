#include "gameShape.h"


gameShape::gameShape(float x, float y, sf::Texture* _texture)
	: texture(_texture)
{
	sprite.setPosition(x, y);
	sprite.setTexture(*texture);
	updateBoundries();
}

void gameShape::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(sprite, state);
}

void gameShape::updateBoundries()
{
	boundries = sprite.getGlobalBounds();
}

sf::FloatRect gameShape::getBoundries() const
{
	return this->boundries;
}

gameShape::~gameShape()
{
}
