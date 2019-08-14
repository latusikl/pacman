#include "wall.h"



wall::wall(float x, float y, sf::Texture* _texture)
	: gameShape(x,y,_texture)
{
}

void wall::changeTexture(sf::Texture* newTexture)
{
	this->texture = newTexture;
	this->sprite.setTexture(*newTexture);
}


//float wall::getLeftBoundry()
//{
//	updateBoundries();
//	return wallBoundries.left;
//}
//
//float wall::getRightBoundry()
//{
//	updateBoundries();
//	return wallBoundries.left+wallBoundries.width;
//}
//
//float wall::getTopBoundry()
//{
//	updateBoundries();
//	return wallBoundries.top;
//}
//
//float wall::getBottomBoundry()
//{
//	updateBoundries();
//	return wallBoundries.top+wallBoundries.height;
//}


