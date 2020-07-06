#pragma once
#include< SFML\Graphics.hpp>
#include <iostream>
class Animation
{
	//Funct
public:
	Animation(sf::Texture * texture,sf::Vector2u imageCount,float switchTime);
	~Animation();

	void Update(int row, float deltaTime,bool faceRight);
	//Vars
public :
	sf::IntRect uvRect;
private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	

	float totalTime;
	float switchTime;
};

