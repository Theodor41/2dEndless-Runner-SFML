#include "pch.h"
#include "Enemy.h"


Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTIme, float speed,int Id)
	:animation(texture, imageCount, switchTIme)
{
	this->speed = speed;
	this->Id = Id;
	if (Id == 2)
	{
		row = 0;//12
	}
	else if (Id == 3)
		row = 12;
	else
		row = 4;
	faceRight = false;
	body.setSize(sf::Vector2f(70.0f, 70.0f));
	body.setOrigin(35.0f, 35.0f);
	body.setTexture(texture);
	if (Id == 3) {
		
		body.setPosition(rand()%1000+400, 0.0f);
	}
	else
	body.setPosition(1280.0f, 720.0f - 50.0f);//To change 
	
	
	
}


Enemy::~Enemy()
{
}



void Enemy::Update(float deltaTime)
{
	if (Id== 2)
	{
		
		velocity.x = -1.0f*speed;
		if(!velocity.y)
		velocity.y = -1.0f*speed;
		double seconds_since_start = difftime(time(0), start);
		
		if (seconds_since_start >= Up_Down_time)
		{
			velocity.y = velocity.y*(-1);
			Up_Down_time += 0.2f;
			
			
		}
	}
	else if (Id == 3)
	{
		velocity.y = 1.0f*speed;
		if (!velocity.x)
		velocity.x = -1.0f*speed;
		double seconds_since_start = difftime(time(0), start);
		if (seconds_since_start >= Up_Down_time)
		{
			velocity.x = velocity.x*(-1);
			Up_Down_time += 0.2f;


		}
	}
	else
		velocity.x = -1.0f*speed;
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}

void Enemy::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}

void Enemy::OnEnemyCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		
		aliveValue = 0;
	}
	else if (direction.x > 0.0f)
	{
		aliveValue = 0;
	}
	if (direction.y < 0.0f)
	{
		aliveValue = 0;
	}
	else if (direction.y > 0.0f)
	{
		aliveValue = 0;
	}

}
