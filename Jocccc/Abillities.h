#pragma once
#include "EnemyController.h"
#include "Bullet.h"
#include "Player.h"
#include <vector>

class Abillities
{
public:
	Abillities(sf::Texture* texture1, sf::Texture* texture2);
	void StartAbility1(Player player);
	void Draw(sf::RenderWindow& window);
	void AddBullet(sf::Texture* texture, sf::Vector2f position, float rotation, sf::Vector2f velocity);
	void Reset(float deltaTime,sf::Texture* texture1, sf::Texture* texture2);
	void Update(float deltaTime, float S_sinceStart, Player player,Player *shield_used);
	int ReturnBullets_size() { return Bullets.size(); };
	Bullet RtBullet(int i);
	std::vector<Bullet> ReturnBullets_Vector() { return Bullets; };
	~Abillities();
private:
	std::vector<Bullet> Bullets;
	sf::Texture BulletTexture;
	sf::Texture shieldTexture;
	
	float internTime1 = 0.0f;
	float internTime2 = 0.0f;
	float shieldTime = 0.0f;

	sf::RectangleShape Ability1;
	sf::RectangleShape Ability2;
	sf::RectangleShape Shield;
	bool ab1 = 1;;
	bool ab2 = 1;
	bool shield_status = false;
};

