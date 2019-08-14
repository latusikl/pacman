#include "mapGeneratorShape.h"



void mapGeneratorShape::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(shape, state);
}

mapGeneratorShape::mapGeneratorShape(float x, float  y,Texture* _texture)
	:texture(_texture)
{
	shape.setPosition(x, y);
	shape.setTexture(*_texture);
	updateBoundries();
}

void mapGeneratorShape::updateBoundries()
{
	shapeBoundries = shape.getGlobalBounds();
}	 

void mapGeneratorShape::destroy()
{
	this->destroyed = true;
}

bool mapGeneratorShape::isDestroyed()
{
	return destroyed;
}

Vector2f mapGeneratorShape::getPosition()
{
	return shape.getPosition();
}

bool mapGeneratorShape::collisoionTest(int x,int y) //Wartoœæ zwracana potrzebna jest do autozapisu je¿eli wyst¹pi zmiana to jest autozapis poprzedniego stanu
{
	FloatRect tmp ((float)x, (float)y, 1.0f, 1.0f); //Przekszta³cenie wspó³rzêdnych na obiekt FloatRect
	
	if (shapeBoundries.intersects(tmp)) //Sprawdzenie kolizji
	{
		destroy();
		return true;
	}
	return false;
}

