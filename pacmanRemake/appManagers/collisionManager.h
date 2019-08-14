#include<SFML/Graphics.hpp>
#include <vector>

#include "collisionTests.h"

#include "../gameObjects/pacman.h"
#include "../gameObjects/wall.h"
#include "../gameObjects/ball.h"
#include "../gameObjects/bonus.h"
#include "../gameObjects/ghost.h"
#include "animationManager.h"

//Class is responsible for managing possible collsions in game window
//Singleton 
class collisionManager
{
	collisionManager() = default;

public:
	static collisionManager& getInstance();
	
	collisionManager(const collisionManager& obj) = delete;
	collisionManager& operator=(const collisionManager& obj) = delete;

	collision PacWallCollision(const pacman& pac, const std::vector<wall>& wallVector);
	void PacBonusCollsion(pacman& pac, std::vector<bonus>& bonusVector);
	void PacSpecialBonusCollision(pacman& pac, bonus& specialBonus);
	collision PacGhostCollision(pacman& pac, std::vector <ghost>& ghostVector, animationManager& animationMan);
	void PacBallCollision(pacman& pac, std::vector<ball>& ballVector);
	void GhostWallCollision(std::vector<ghost>& ghostVector, std::vector <wall>& wallVector,animationManager& animationMan,sf::Clock clock);

};