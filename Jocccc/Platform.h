#pragma once
#include <SFML/Graphics.hpp>
#include "Collison.h"
class Platform
{
public:
	Platform(sf::Texture* texture,sf::Vector2f size,sf::Vector2f position);
	~Platform();
	
	void Draw(sf::RenderWindow& window);
	Collison GetCollider() { return Collison(body); }
private:
	sf::RectangleShape body;

};

