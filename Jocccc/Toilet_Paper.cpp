#include "pch.h"
#include "Toilet_Paper.h"


Toilet_Paper::Toilet_Paper(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	body.setSize(size);
	body.setTexture(texture);
	body.setPosition(position);
	body.setOrigin(size / 2.0f);
	
}


void Toilet_Paper::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}

void Toilet_Paper::Update(float deltaTime)
{
	body.rotate(0.2f);
	velocity.x = -1.0f*100.f;
	body.move(velocity * deltaTime);
}

Toilet_Paper::~Toilet_Paper()
{

}
