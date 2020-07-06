#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h";
#include "Collison.h";
#include "EnemyCollision.h"
class Player
{
public:
	Player(sf::Texture* texture,sf::Vector2u imageCount,float switchTIme,float speed,float jumpHeight,int HP);
	~Player();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow &window);
	void OnCollision(sf::Vector2f direction);
	void OnEnemyCollision(sf::Vector2f direction);
	void OnToiletPaperCollision(sf::Vector2f direction);
	void Reset(sf::Texture* texture, sf::Vector2u imageCount, float switchTIme, float speed, float jumpHeight, int HP);
	int GetHp(){ return HP; }
	void ChangeShield_status() { shield = -1*shield; };
	Collison GetCollider() { return Collison(body); }
	EnemyCollision GetEnemyCollision() { return EnemyCollision(body); }
	sf::Vector2f GetPoz() { return body.getPosition(); }
	sf::Vector2f GetSize() { return body.getSize(); }
private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
	int shield = -1;
	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
	int HP;
};

