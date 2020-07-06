#pragma once
#include "Animation.h"
#include "EnemyCollision.h"
#include "Collison.h"


class Enemy
{
public:
	Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTIme, float speed, int Id);
	~Enemy();
	Collison GetCollider() { return Collison(body); }
	void Update(float deltaTime);
	int getID() { return Id; };
	void Draw(sf::RenderWindow &window);
	sf::Vector2f GetPoz() { return body.getPosition(); }
	EnemyCollision GetEnemyCollision() { return EnemyCollision(body); }
	void OnEnemyCollision(sf::Vector2f direction);
private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
	sf::Vector2f velocity;
	bool aliveValue = 1;
	time_t start = time(0);
	double  Up_Down_time = 0.2f;


	int Id;
};

