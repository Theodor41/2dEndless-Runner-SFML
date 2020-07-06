#include "pch.h"
#include "Background.h"


Background::Background(sf::Texture* texture, sf::Vector2f size)
{
	body.setSize(size);
	body.setTexture(texture);
	body.setOrigin(size/2.0f);
	body.setPosition(size / 2.0f);
}


Background::~Background()
{
}

void Background::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}
