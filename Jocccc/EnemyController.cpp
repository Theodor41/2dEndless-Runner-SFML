#include "pch.h"
#include "EnemyController.h"

//Prev
EnemyController::EnemyController()
{
	srand(time(NULL));
	
}


EnemyController::~EnemyController()
{
	
}

void EnemyController::CheckCollisions(Player & player, sf::Vector2f direction)
{
	EnemyCollision playerEnemyCollision = player.GetEnemyCollision();
	for (int i = 0; i < Enemies.size(); i++) {

		if (Enemies[i].GetEnemyCollision().CheckCollision(playerEnemyCollision, direction, 1.0f))
		{
			player.OnEnemyCollision(direction);
			Enemies.erase(Enemies.begin() + i);
		}
	}
}

void EnemyController::CheckCollisions_Bullet(std::vector<Bullet> bullets, sf::Vector2f direction)
{
	if (!bullets.empty())
	{//Collison BulletCollision = entitySpawner.Get();
		for (int i = 0; i < Enemies.size(); i++) {
			for (int j = 0; j < bullets.size(); j++)
			{
				if (bullets[j].GetPoz().x!=NULL)
				{
					Collison BulletCollision = bullets[j].GetCollider();
					if (Enemies[i].GetCollider().CheckCollision(BulletCollision, direction, 1.0f))
					{

						Enemies.erase(Enemies.begin() + i);
						break;
					}
				}
			}
		}
	}
}

void EnemyController::Update(float deltaTime)
{
	for (int i = 0; i < Enemies.size(); i++) {
		Enemies[i].Update(deltaTime);
		if (Enemies[i].GetPoz().x <= -50 || Enemies[i].GetPoz().y>= 740.0f || Enemies[i].GetPoz().x >=2000.0f )
		{
			Enemies.erase(Enemies.begin() + i);
			std::cout << "gotcha  ";
			
		}
		
		
	}
}

void EnemyController::Reset()
{
	internTime = 0.0f;
	spawnRate = 3.0f;
	idCounter = 0;
	speed = 200.0f;
	Enemies.clear();
}

void EnemyController::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < Enemies.size(); i++) {
		Enemies[i].Draw(window);
	}
}

void EnemyController::AddEnemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTIme, float speed, int Id)
{
	
	Enemies.push_back(Enemy(texture, imageCount, switchTIme, speed, Id));

}

void EnemyController::SpawnEnemy(float deltaTime,sf::Texture* texture, sf::Vector2u imageCount, float switchTIme)
{
	
	if (deltaTime >= internTime+spawnRate)
	{
		
		internTime = deltaTime;
		if (spawnRate >= 0.2f)
			spawnRate -= 0.1f;
		idCounter++;
		int Id=1;
		if (speed <= 400)
			speed += 5;
		if (idCounter >= 4)
		{
			
			Id= rand() % 4 + 1;
		}
		AddEnemy(texture, imageCount, switchTIme, speed, Id);
	}
}

