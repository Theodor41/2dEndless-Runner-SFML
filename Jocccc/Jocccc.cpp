// Jocccc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include"Animation.h"
#include "Player.h"
#include "Platform.h"
#include "Collison.h"
#include "Background.h";
#include "Enemy.h";
#include "EnemyController.h"
#include "EntitySpawner.h"

#include <time.h>
#include <string>
#include <fstream>
#include "Hearts.h"
#include "Abillities.h"
using namespace std;

//Window height and width 
static const float View_Height = 720.0f;
static const float View_Width = 1280.0f;

float high_score;

void ResizeView(sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(View_Width , View_Height);
}
int main()
{
	//Data retrieval
	ofstream Outfile;
	std::ifstream Readfile;
	Readfile.open("Save.txt");
	if (Readfile.is_open())
	{
		Readfile >> high_score;
	}
	else
	{
		Readfile.close();
		
		Outfile.open("Save.txt");
		high_score = 0.0f;
		Outfile.close();
	}


	//Window render
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Game", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	
	//Main view 
	sf::View mainView(sf::Vector2f(0.0f, 0.0f),sf::Vector2f(View_Width, View_Height));

	//Background
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("Bg1.jpg");
	Background background1(&backgroundTexture,sf::Vector2f(View_Width, View_Height));

	//Enemies
	sf::Texture EnemyTextures;
	EnemyTextures.loadFromFile("monsters.png");
	EnemyController SpawnAi;
	
	//Toilet Paper
	sf::Texture ToiletPaperTexture;
	ToiletPaperTexture.loadFromFile("Paper.png");
	EntitySpawner entitySpawner;
	
	//Time counter
	time_t start = time(0);
	double seconds_since_start = difftime(time(0), start);

	//Music 
	sf::Music music;
	if (!music.openFromFile("toxic.wav"))
		return -1; // error

	sf::Music dmgMusic;
	dmgMusic.openFromFile("dmg.wav");

	sf::Music hpMusic;
	hpMusic.openFromFile("health+.wav");
	
	

	//Player
	sf::Texture playerTexture;
	playerTexture.loadFromFile("Player.png");
	Player player(&playerTexture, sf::Vector2u(3, 3), 0.3f, 200.0f, 200.0f, 3);
	
	//Abilities
	sf::Texture A1_Texture;
	sf::Texture A2_Texture;
	A1_Texture.loadFromFile("soap.png");
	A2_Texture.loadFromFile("shield.png");
	Abillities Ability_Controller(&A1_Texture, &A2_Texture);
	//Hp
	sf::Texture heartTexture;
	heartTexture.loadFromFile("Heart.png");
	Hearts hearts(&heartTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(50.0f, 50.0f));

	// Score
	float score = 0.0f;
	sf::Text scoreText;
	sf::Font MyFont;
	MyFont.loadFromFile("Roboto-BoldItalic.ttf");
	scoreText.setFont(MyFont);
	scoreText.setString(std::to_string(int(score)));
	scoreText.setStyle(sf::Text::Bold);
	scoreText.setFillColor(sf::Color::Green);
	scoreText.setCharacterSize(24);
	scoreText.setPosition(sf::Vector2f(1150.0f, 25.0f));
	
	//High Score
	sf::Text high_scoreText;
	high_scoreText.setFont(MyFont);
	high_scoreText.setString(std::to_string(int(high_score)));
	high_scoreText.setStyle(sf::Text::Bold);
	high_scoreText.setFillColor(sf::Color::Green);
	high_scoreText.setCharacterSize(24);
	high_scoreText.setPosition(sf::Vector2f(1000.0f, 25.0f));

	//Bottom border
	Platform bottomBorder(nullptr, sf::Vector2f(View_Width, View_Width), sf::Vector2f(View_Width / 2.0f, View_Width + (6.5f / 100.0f*View_Width)));
	
	//End Screen
	int gameRunning=0;
	bool refreshInitialization = 0;
	sf::RectangleShape endWindow;
	endWindow.setSize(sf::Vector2f(600.0f,600.0f));
	endWindow.setPosition(sf::Vector2f(View_Width / 2.0f, View_Height / 2.0f));
	endWindow.setOrigin(sf::Vector2f(300.0f,300.0f));
	endWindow.setFillColor(sf::Color::Black);

	sf::Text endText;
	endText.setFont(MyFont);
	endText.setString("You died ... Press SpaceBar to start again");
	endText.setStyle(sf::Text::Bold);
	endText.setFillColor(sf::Color::Green);
	endText.setCharacterSize(24);
	endText.setScale(sf::Vector2f(1.0f, 1.0f));
	endText.setPosition(sf::Vector2f(View_Width / 2.0f - 250.0f , View_Height / 2.0f));

	//Main screen text
	sf::Text menuText;

	menuText.setFont(MyFont);
	menuText.setString("Press SpaceBar to start shopping");
	menuText.setStyle(sf::Text::Bold);
	menuText.setFillColor(sf::Color::Green);
	menuText.setCharacterSize(24);
	menuText.setScale(sf::Vector2f(2.0f, 2.0f));
	menuText.setPosition(sf::Vector2f(View_Width / 2.0f-350.0f, View_Height/ 2.0f));

	// Clock for animations
	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		if (gameRunning == 0)
		{
			background1.Draw(window);
			window.draw(menuText);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				music.play();
				gameRunning = 1;
			}
		}
		while (gameRunning == 1)
		{
			//Re-Initializing all game elements
			
			if (refreshInitialization == 1)
			{
				refreshInitialization = 0;
				start = time(0);
				music.play();
				player.Reset(&playerTexture, sf::Vector2u(3, 9), 0.3f, 200.0f, 200.0f, 3);
				hearts.Reset(&heartTexture, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(50.0f, 50.0f));
				score = 0.0f;
				std::ifstream Readfile;
				Readfile.open("Save.txt");
				if (Readfile.is_open())
				{
					Readfile >> high_score;
				}
				Readfile.close();
				SpawnAi.Reset();
				Ability_Controller.Reset(deltaTime,&A1_Texture,&A2_Texture);
				entitySpawner.Reset();
				high_scoreText.setString(std::to_string(int(high_score)));
				
			}

			
			score += 0.01f;
			scoreText.setString(std::to_string(int(score)));


			seconds_since_start = difftime(time(0), start);
			deltaTime = clock.restart().asSeconds();
			
			if (deltaTime > 1.0f / 20.0f)
				deltaTime = 1.0f / 20.0f;

			sf::Event evnt1;
			while (window.pollEvent(evnt1))
			{
				switch (evnt1.type)
				{
				case sf::Event::Closed:
					
					Outfile.open("Save.txt");
					if (score > high_score)
						high_score = score;
					Outfile << high_score;
					Outfile.close();
					window.close();
					break;
				case sf::Event::Resized:
					ResizeView(window, mainView);
					break;
				case sf::Event::TextEntered:
					//std::cout << " GOD LEFT ME UNFINISHED ";
					break;
				}
			}
			//Spawn Enemies
			SpawnAi.SpawnEnemy(seconds_since_start, &EnemyTextures, sf::Vector2u(3, 16), 0.3f);
			entitySpawner.SpawnToiletPaper(seconds_since_start, &ToiletPaperTexture);
			//Update player and enemies
			player.Update(deltaTime);
			SpawnAi.Update(deltaTime);
			Ability_Controller.Update(deltaTime, seconds_since_start,player,&player);
			entitySpawner.Update(deltaTime);
			//Check collision for player and enemies
			Collison playerCollision = player.GetCollider();
			EnemyCollision playerEnemyCollision = player.GetEnemyCollision();
			sf::Vector2f direction;
			if (bottomBorder.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
				player.OnCollision(direction);
			
			//Music Controller
			int hpAux = player.GetHp();
			SpawnAi.CheckCollisions(player, direction);
			SpawnAi.CheckCollisions_Bullet(Ability_Controller.ReturnBullets_Vector(), direction);
			entitySpawner.CheckCollisions(player, direction);
			
			//Change Hearts
			hearts.takeDmg(player.GetHp());
			//Check if game Ends
			if (player.GetHp() == 0)
				gameRunning = 3;
			//mainView.setCenter(player.GetPoz());

			//Center view on center of screen
			mainView.setCenter(sf::Vector2f(View_Width / 2, View_Height / 2));

			//Clear the window
			window.clear(sf::Color::Blue);
			//Set view
			window.setView(mainView);

			//Draw bg first
			background1.Draw(window);

			//Draw hearts
			hearts.Draw(window);

			//Draw player
			player.Draw(window);
			//Check music again
			if ((music.getStatus() == sf::Music::Stopped ||music.getStatus() == sf::Music::Paused) && dmgMusic.getStatus()!=sf::Music::Stopped)
			{
				music.play();

			}
			//Draw enemies and bottom border
			SpawnAi.Draw(window);
			Ability_Controller.Draw(window);
			entitySpawner.Draw(window);
			bottomBorder.Draw(window);
			window.draw(scoreText);
			window.draw(high_scoreText);
			window.display();
		}
		if (gameRunning == 3)
		{
			//Save High Score
			
			
			Outfile.open("Save.txt");
			if (score > high_score)
				high_score = score;
			Outfile << high_score;
			Outfile.close();

			music.stop();
			hearts.Draw(window);
			window.draw(endWindow);
			window.draw(endText);
			window.draw(scoreText);
			window.draw(high_scoreText);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				gameRunning = 1;
			refreshInitialization = 1;
			
		}
		window.display();
	}
	return 0;
}

