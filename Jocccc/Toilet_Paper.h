#pragma once
#include "SFML/Graphics.hpp"
#include "Collison.h";
class Toilet_Paper
{
public:
	void Draw(sf::RenderWindow& window);
	void Update(float deltaTime);
	Collison GetCollider() { return Collison(body); }
	sf::Vector2f GetPoz() { return body.getPosition(); }
	Toilet_Paper(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Toilet_Paper();
private:
	sf::RectangleShape body;
	sf::Vector2f velocity;

};

