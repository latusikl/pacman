#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class mapGeneratorPlacer:public Drawable
{

	void draw(RenderTarget& target, RenderStates state)const override; //Nadpisanie funkcji z klasy Drawable umo¿liwia rysowanie
	Vector2f size = { 20.0f,20.0f };
	Vector2f startPosition = { 0.0f,0.0f };
	Vector2f velocity;
	const float rectVelocity = 10.0f;
	RectangleShape rect;
	bool movable = true;
	bool bonus = false;
	bool specialBonus = false;
public:
	mapGeneratorPlacer();
	~mapGeneratorPlacer()=default;
	Vector2f getPosition();
	bool checkMovement();
	bool isBonus();
	bool isSpecialBonus();
	void stopMovement();
	void update();
	void makeBonus();
	void makeSpecialBonus();
};

