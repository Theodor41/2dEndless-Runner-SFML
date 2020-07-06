#include "pch.h"
#include "Bullet.h"





Bullet::Bullet(sf::Texture * texture, sf::Vector2f position, float rotation, sf::Vector2f velocity)
{
	body.setSize(sf::Vector2f(70.0f, 70.0f));
	body.setOrigin(35.0f, 35.0f);
	body.setTexture(texture);
	body.setPosition(position);
	body.setRotation(rotation);
	
	this->velocity = velocity;
}

Bullet::~Bullet()
{
}

void Bullet::Update(float deltaTime)
{
	body.move(velocity * deltaTime*200.0f);
	body.rotate(0.2f);
}

void Bullet::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}



