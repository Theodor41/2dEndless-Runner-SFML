#include "pch.h"
#include "Player.h"



Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTIme, float speed,float jumpHeight,int HP):
	animation(texture, imageCount, switchTIme)
{

	this->HP = HP;
	this->speed = speed;
	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(100.0f, 100.0f));
	body.setOrigin(50.0f, 50.0f);
	body.setPosition(90.0f, 720.0f-90.0f);//To change 
	body.setTexture(texture);
	this->jumpHeight = jumpHeight;
}


Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	
	velocity.x = 0.0f;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x -= speed ;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x += speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&canJump)
	{
		canJump = false;
		//square root (2.0f * gravity * jumpHeight)
		velocity.y=-sqrtf(2.0f* 981.0f*jumpHeight);//Sfml has flipped y axis do not forget you dum dum
	}
	velocity.y += 981.0f *deltaTime;
	if (velocity.x == 0.0f )
	{
		row = 0;
	}
	else if (velocity.y!=0.0f && canJump == false)
	{
		row = 1;
		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}
	else
	{
		row = 2;
		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);//Movement not frame specific
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);

}

void Player::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		velocity.x = 0.0f; // coll on left
	}
	else if (direction.x > 0.0f)
	{
		velocity.x = 0.0f; // coll on right
	}
	if (direction.y < 0.0f)
	{
		velocity.y = 0.0f; // coll on bottom
		canJump = true;
	}
	else if (direction.y >  0.0f)
	{
		velocity.y = 0.0f; //coll on top
	}
}
void Player::OnEnemyCollision(sf::Vector2f direction)
{

	if (direction.x < 0.0f)
	{
		if(shield==-1)
		HP--;
	}
	else if (direction.x > 0.0f)
	{
		if (shield == -1)
		HP--;
	}
	if (direction.y < 0.0f)
	{
		if (shield == -1)
		HP--;
	}
	else if (direction.y > 0.0f)
	{
		if (shield == -1)
		HP--;
	}
}

void Player::OnToiletPaperCollision(sf::Vector2f direction)
{
	int k = 0;
	if (direction.x < 0.0f)
	{
		k = 1;
	}
	else if (direction.x > 0.0f)
	{
		k = 1;
	}
	if (direction.y < 0.0f)
	{
		k = 1;
	}
	else if (direction.y > 0.0f)
	{
		k = 1;
	}
	if (k == 1 && HP < 3)
		HP++;
}

void Player::Reset(sf::Texture * texture, sf::Vector2u imageCount, float switchTIme, float speed, float jumpHeight, int HP)
{
	this->HP = HP;
	this->speed = speed;
	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(100.0f, 150.0f));
	body.setOrigin(50.0f, 75.0f);
	body.setPosition(90.0f, 720.0f - 90.0f);//To change 
	body.setTexture(texture);
	this->jumpHeight = jumpHeight;

}
