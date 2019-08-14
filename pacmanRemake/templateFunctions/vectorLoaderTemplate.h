#pragma once
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

#include "./gameObjects/ball.h"

//Szablon funckji odpowiedzialny za tworzenie wektora
//Argumentem mo¿e byæ odpowiednia klasa powi¹zana z bibliotek¹ SFML reprezentuj¹ca jakiœ obiekt w oknie i posiadaj¹ca odpowiedni konstruktor
//Np. class wall, class ball itd.

template <typename T>
std::vector <T> createVector(std::string fileName, sf::Texture* _texture)
{
	std::ifstream file;
	file.open(fileName, std::ios::in);
	if (!file.is_open())
	{
		std::string error = "Unable to open file at mapGenerator|createWallMapVector()\n";
		throw error;
	}
	else
	{
		std::vector<T> Vector;
		float x, y;
		while (file >> x)
		{
			file >> y;

			Vector.push_back(T{ x,y,_texture });
		}
		file.close();
		return Vector;
	}


}

//template <>
//std::vector <bonus> createVector <bonus>  (std::string fileName, sf::Texture* _texture)
//{
//	std::ifstream file;
//	file.open(fileName, std::ios::in);
//	if (!file.is_open())
//	{
//		std::string error = "Unable to open file at mapGenerator|createWallMapVector()\n";
//		throw error;
//	}
//	else
//	{
//		std::vector<bonus> Vector;
//		float x, y;
//		while (file >> x)
//		{
//			file >> y;
//
//			Vector.push_back(bonus{ x,y,_texture });
//		}
//		file.close();
//		return Vector;
//	}
//}


