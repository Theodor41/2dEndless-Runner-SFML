#pragma once
#include "Player.h"
#include <vector>
#include "Toilet_Paper.h"
class EntitySpawner
{

public:
	EntitySpawner();
	~EntitySpawner();
	void CheckCollisions(Player &player, sf::Vector2f direction);
	void Update(float deltaTime);
	void Reset();
	void Draw(sf::RenderWindow& window);
	void AddToiletPaper(sf::Texture* texture, sf::Vector2f position);
	void SpawnToiletPaper(float deltaTime, sf::Texture* texture);
private:
	std::vector<Toilet_Paper> Papers;
	float spawnRate = 10.0f;
	float internTime = 0.0f;
};

