#include "bonus.h"





bonus::bonus(float x, float y, sf::Texture* _texture)
	:gameShape(x, y, _texture), typeOfBonus(dot)
{
	//Ustawia odp. teksture
	this->sprite.setTexture(this->texture[dot]);
}

void bonus::destroy()
{
	this->destroyed = true;
}

bool bonus::isDestroyed()
{
	return this->destroyed;
}

void bonus::changeTextureType(bonusType textureType)
{
	//Ustawia odp. teksture
	this->sprite.setTexture(this->texture[textureType]);
	this->typeOfBonus = textureType;
}

bonusType bonus::getTypeOfBonus()
{
	return this->typeOfBonus;
}

void bonus::changeToNotDestroyed()
{
	this->destroyed = false;
}



bonusType bonus::randomBonusType()
{
	//Losowanie liczby
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int> distribution(0, 999);
	int randomNumber = distribution(generator);

	if (0 <= randomNumber && randomNumber <= 332)
		return cherry;
	else if (333 <= randomNumber && randomNumber <= 665)
		return banana;
	else if (666 <= randomNumber && randomNumber <= 999)
		return strawberry;
	else
		return dot;
}
