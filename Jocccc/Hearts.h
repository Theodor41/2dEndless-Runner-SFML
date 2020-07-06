#pragma once
#include <SFML/Graphics.hpp>
class Hearts
{
public:
	Hearts(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	void Draw(sf::RenderWindow& window);
	void Reset(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Hearts();
	void takeDmg(int i);
private:
	sf::RectangleShape body1;
	sf::RectangleShape body2;
	sf::RectangleShape body3;
};

