#pragma once
#include "Enemy.h"
#include "Player.h"
#include <vector>
#include <time.h> 
#include "Bullet.h"
//prev
class EnemyController
{
public:
	EnemyController();
	~EnemyController();
	void CheckCollisions(Player &player, sf::Vector2f direction);
	void CheckCollisions_Bullet(std::vector<Bullet>, sf::Vector2f direction);
	void Update(float deltaTime);
	void Reset();
	void Draw(sf::RenderWindow& window);
	void AddEnemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTIme, float speed, int Id);
	void SpawnEnemy(float deltaTime, sf::Texture* texture, sf::Vector2u imageCount, float switchTIme);
private:
	std::vector<Enemy> Enemies;

	float internTime=0.0f;
	float spawnRate=3.0f;
	int idCounter=0;
	float speed=200.0f;
	
};

