#pragma once
#include"Toilet_Paper.h"
#include <vector>
#include "Player.h"
class Entity_Spawner
{
public:
	Entity_Spawner();
	void CheckCollisions(Player &player, sf::Vector2f direction);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void AddToiletPaper(sf::Texture* texture, sf::Vector2u imageCount, float switchTIme, float speed, int Id);
	void SpawnToiletPaper(float deltaTime, sf::Texture* texture, sf::Vector2u imageCount, float switchTIme);
	~Entity_Spawner();
private:
	std::vector<Toilet_Paper> Toilet_Papers;
};

