#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
class Collison
{
public:
	Collison(sf::RectangleShape& body);
	~Collison();

	void Move(float dx, float dy) { body.move(dx, dy); }

	bool CheckCollision(Collison & other, sf::Vector2f &direction, float push);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }
private:
	sf::RectangleShape& body;
};

