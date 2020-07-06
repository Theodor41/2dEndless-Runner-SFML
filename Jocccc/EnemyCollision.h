#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
class EnemyCollision
{
public:
	EnemyCollision(sf::RectangleShape& body);
	~EnemyCollision();

	bool CheckCollision(EnemyCollision & other, sf::Vector2f &direction, float push);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }
private:
	sf::RectangleShape& body;
};

