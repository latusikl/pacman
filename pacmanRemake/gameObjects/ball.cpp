#include "ball.h"

ball::ball(float x, float y,sf::Texture* _texture)
	:gameShape(x,y,_texture)
{
}

//float ball::getLeftBoundry()
//{
//	updateBoundries();
//	return ballBoundries.left;
//}
//
//float ball::getRightBoundry()
//{
//	updateBoundries();
//	return ballBoundries.left+ballBoundries.width;
//}
//
//float ball::getTopBoundry()
//{
//	updateBoundries();
//	return ballBoundries.top;
//}
//
//float ball::getBottomBoundry()
//{
//	updateBoundries();
//	return ballBoundries.top+ballBoundries.height;
//}
//
//
//FloatRect ball::getBallBoundries() const
//{
//	return ballBoundries;
//}

void ball::destroy()
{
	destroyed = true;
}

bool ball::isDestroyed()
{
	return destroyed;
}
