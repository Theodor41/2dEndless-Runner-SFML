#include "pch.h"
#include "EntitySpawner.h"


EntitySpawner::EntitySpawner()
{
	srand(time(NULL));
}


EntitySpawner::~EntitySpawner()
{
}

void EntitySpawner::CheckCollisions(Player & player, sf::Vector2f direction)
{
	Collison playerTpCollison = player.GetCollider();
	for (int i = 0; i < Papers.size(); i++) {

		if (Papers[i].GetCollider().CheckCollision(playerTpCollison, direction, 1.0f))
		{
			player.OnToiletPaperCollision(direction);
			Papers.erase(Papers.begin() + i);
		}
	}
}

void EntitySpawner::Update(float deltaTime)
{
	for (int i = 0; i < Papers.size(); i++) {
		Papers[i].Update(deltaTime);
		if (Papers[i].GetPoz().x <= -50 || Papers[i].GetPoz().y >= 740.0f || Papers[i].GetPoz().x >= 2000.0f)
		{
			Papers.erase(Papers.begin() + i);
			std::cout << "gotcha  ";

		}


	}
}

void EntitySpawner::Reset()
{
	Papers.clear();
}

void EntitySpawner::Draw(sf::RenderWindow & window)
{
	for (int i = 0; i < Papers.size(); i++) {
		Papers[i].Draw(window);
	}
}

void EntitySpawner::AddToiletPaper(sf::Texture * texture, sf::Vector2f position)
{
	Papers.push_back(Toilet_Paper(texture, sf::Vector2f(50.0f,50.0f), position));
}

void EntitySpawner::SpawnToiletPaper(float deltaTime, sf::Texture * texture)
{
	if (deltaTime >= internTime + spawnRate)
	{
		internTime = deltaTime;
		AddToiletPaper(texture, sf::Vector2f(1280,rand()%500+400));
	}
}
