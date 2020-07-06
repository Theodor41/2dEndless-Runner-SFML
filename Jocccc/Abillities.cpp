#include "pch.h"
#include "Abillities.h"





Abillities::Abillities(sf::Texture * texture1, sf::Texture * texture2)
{
	Ability1.setSize(sf::Vector2f(50.0f,50.0f));
	Ability1.setTexture(texture1);
	Ability1.setPosition(sf::Vector2f(100.0f, 200.0f));
	Ability1.setOrigin(sf::Vector2f(200.0f, 200.0f) / 2.0f);

	Ability2.setSize(sf::Vector2f(50.0f, 50.0f));
	Ability2.setTexture(texture2);
	Ability2.setPosition(sf::Vector2f(200.0f, 200.0f));
	Ability2.setOrigin(sf::Vector2f(200.0f, 200.0f) / 2.0f);





	BulletTexture.loadFromFile("soap.png");
	shieldTexture.loadFromFile("shieldTxt.png");
	Shield.setTexture(&shieldTexture);
	Shield.setSize(sf::Vector2f(125.0f, 125.0f));
	Shield.setOrigin(Shield.getSize() / 2.0f);
	
}

void Abillities::StartAbility1(Player player)
{
	sf::Vector2f position = player.GetPoz();
	sf::Vector2f size = player.GetSize();
	//sf::Texture* texture, sf::Vector2f position, float rotation, sf::Vector2f velocity
	sf::Vector2f velocity;
	float rotation = 0.0f;
	float std = 50.0f;
	AddBullet(&BulletTexture, sf::Vector2f(position.x,position.y- std), rotation, sf::Vector2f(0.0f,-2.0f));
	AddBullet(&BulletTexture, sf::Vector2f(position.x+ std, position.y - std), 45.0f, sf::Vector2f(2.0f, -2.0f));
	AddBullet(&BulletTexture, sf::Vector2f(position.x + std, position.y ), 90.0f, sf::Vector2f(2.0f, 0.0f));
	AddBullet(&BulletTexture, sf::Vector2f(position.x + std, position.y+std),135.0f, sf::Vector2f(2.0f, +2.0f));

	AddBullet(&BulletTexture, sf::Vector2f(position.x , position.y + std), 180.0f, sf::Vector2f(0.0f, +2.0f));
	AddBullet(&BulletTexture, sf::Vector2f(position.x-std, position.y + std), 225.0f, sf::Vector2f(-2.0f, +2.0f));
	AddBullet(&BulletTexture, sf::Vector2f(position.x - std, position.y ), 270.0f, sf::Vector2f(-2.0f, 0.0f));
	AddBullet(&BulletTexture, sf::Vector2f(position.x - std, position.y-std), 315.0f, sf::Vector2f(-2.0f, -2.0f));
}

void Abillities::Draw(sf::RenderWindow & window)
{
	window.draw(Ability1);
	window.draw(Ability2);
	if(shield_status==true)
	window.draw(Shield);
	for (int i = 0; i < Bullets.size(); i++) {
		Bullets[i].Draw(window);
	}
	
}

void Abillities::AddBullet(sf::Texture * texture, sf::Vector2f position, float rotation, sf::Vector2f velocity)
{
	Bullets.push_back(Bullet(texture, position, rotation, velocity));
}

void Abillities::Reset(float deltaTime,sf::Texture * texture1, sf::Texture * texture2)
{
	Ability1.setSize(sf::Vector2f(50.0f, 50.0f));
	Ability1.setTexture(texture1);
	Ability1.setPosition(sf::Vector2f(100.0f, 200.0f));
	Ability1.setOrigin(sf::Vector2f(200.0f, 200.0f) / 2.0f);

	Ability2.setSize(sf::Vector2f(50.0f, 50.0f));
	Ability2.setTexture(texture2);
	Ability2.setPosition(sf::Vector2f(200.0f, 200.0f));
	Ability2.setOrigin(sf::Vector2f(200.0f, 200.0f) / 2.0f);
	
	internTime1 = 0;
	internTime2 = 0;
	shieldTime = 0.0f;
	shield_status = false;
	ab1 = 1;
	ab2 = 1;
	Bullets.clear();
	
}

void Abillities::Update(float deltaTime, float S_sinceStart,Player player, Player *shield_used)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && ab1 == 1)
	{
		StartAbility1(player);
		internTime1 = S_sinceStart;
		ab1 = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)&&ab2==1)
	{
		shield_used->ChangeShield_status();
		internTime2 = S_sinceStart;
		shieldTime = S_sinceStart;
		shield_status = true;
		ab2 = 0;
	}
	if (S_sinceStart >= internTime1 + 10.0f)
	{
		
		internTime1 = S_sinceStart;
		Bullets.clear();
		ab1 = 1;
	}
	if (S_sinceStart >= internTime2 + 10.0f)
	{
		internTime2 = S_sinceStart;
		shield_status = false;
		ab2 = 1;
	}
	if (S_sinceStart >= shieldTime + 5.0f && shield_status ==true)
	{
		//std::cout << "A";
		shield_status = false;
		shield_used->ChangeShield_status();

	}
	if (ab1 == 0)
		Ability1.setFillColor(sf::Color::Red);
	else
		Ability1.setFillColor(sf::Color::White);
	if (ab2 == 0)
		Ability2.setFillColor(sf::Color::Red);
	else
		Ability2.setFillColor(sf::Color::White);
	for (int i = 0; i < Bullets.size(); i++) {
		Bullets[i].Update(deltaTime);
		if (Bullets[i].GetPoz().x <= -50 || Bullets[i].GetPoz().y >= 740.0f || Bullets[i].GetPoz().x >= 2000.0f || Bullets[i].GetPoz().y<=-20)
		{
			Bullets.erase(Bullets.begin() + i);
			//std::cout << "A  ";

		}


	}
	Shield.setPosition(player.GetPoz());
}

Bullet Abillities::RtBullet(int i)
{
	int j;
	for ( j = 0; j < Bullets.size(); j++)
		if (j == i)
			break;
	return Bullets[j];
}

Abillities::~Abillities()
{
}
