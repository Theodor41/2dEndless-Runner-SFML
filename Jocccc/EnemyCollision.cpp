#include "pch.h"
#include "EnemyCollision.h"


EnemyCollision::EnemyCollision(sf::RectangleShape& body)
	:body(body)
{

}


EnemyCollision::~EnemyCollision()
{
}

bool EnemyCollision::CheckCollision(EnemyCollision & other, sf::Vector2f & direction, float push)
{

	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();


	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);
		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{

				direction.x = 1.0f;
				direction.y = 0.0f;
			}
			else
			{

				direction.x = -1.0f;
				direction.y = 0.0f;
			}

		}
		else
		{
			if (deltaY > 0.0f)
			{

				direction.x = 0.0f;
				direction.y = 1.0f;
			}
			else
			{

				direction.x = 0.0f;
				direction.y = -1.0f;
			}
		}
		std::cout << "Hit";
		return true;
	}	
	else
		return false;
}
