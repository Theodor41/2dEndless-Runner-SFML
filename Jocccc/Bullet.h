#pragma once
#include "SFML/Graphics.hpp"
#include "Collison.h"
class Bullet
{
public:
	Bullet(sf::Texture* texture, sf::Vector2f position,float rotation, sf::Vector2f velocity);
	~Bullet();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow &window);
	Collison GetCollider() { return Collison(body); }
	sf::Vector2f GetPoz() { return body.getPosition(); }
private:
	sf::RectangleShape body;
	float speed=300.0f;
	sf::Vector2f velocity;
};

