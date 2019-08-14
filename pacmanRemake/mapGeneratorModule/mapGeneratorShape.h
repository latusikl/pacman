#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
class mapGeneratorShape: public Drawable //Obiekt w oknie tworz¹cym mapê
{
	Sprite shape;
	Texture* texture;
	FloatRect shapeBoundries;
	void draw(RenderTarget& target, RenderStates state)const override;
	bool destroyed = false;


public:
	mapGeneratorShape() = delete;
	~mapGeneratorShape() = default;
	mapGeneratorShape(float x, float y, Texture* _texture);
	
	void updateBoundries();
	void destroy();
	bool isDestroyed();
	Vector2f getPosition();
	bool collisoionTest(int x,int y); //Sprawdza kolizje pomiêdzy kursorem a obiektem


};

