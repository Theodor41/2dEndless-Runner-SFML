#include "pch.h"
#include "Hearts.h"


Hearts::Hearts(sf::Texture* texture, sf::Vector2f size,  sf::Vector2f position)
	
{
	body1.setSize(size);
	body1.setTexture(texture);
	body1.setPosition(position);
	body1.setOrigin(size / 2.0f);

	body2.setSize(size);
	body2.setTexture(texture);
	body2.setPosition(position+sf::Vector2f(50.0f,0));
	body2.setOrigin(size / 2.0f);

	body3.setSize(size);
	body3.setTexture(texture);
	body3.setPosition(position + sf::Vector2f(100.0f, 0));
	body3.setOrigin(size / 2.0f);
}

void Hearts::Draw(sf::RenderWindow & window)
{
	window.draw(body1);
	window.draw(body2);
	window.draw(body3);
}

void Hearts::Reset(sf::Texture * texture, sf::Vector2f size, sf::Vector2f position)
{
	body1.setSize(size);
	body1.setTexture(texture);
	body1.setPosition(position);
	body1.setOrigin(size / 2.0f);

	body2.setSize(size);
	body2.setTexture(texture);
	body2.setPosition(position + sf::Vector2f(50.0f, 0));
	body2.setOrigin(size / 2.0f);

	body3.setSize(size);
	body3.setTexture(texture);
	body3.setPosition(position + sf::Vector2f(100.0f, 0));
	body3.setOrigin(size / 2.0f);

}


Hearts::~Hearts()
{
}

void Hearts::takeDmg(int i)
{
	if (i == 2)
	{
		body1.setFillColor(sf::Color::White);
		body2.setFillColor(sf::Color::White);
		body3.setFillColor(sf::Color::Black);
	}
	else if (i == 1)
	{
		body1.setFillColor(sf::Color::White);
		body2.setFillColor(sf::Color::Black);
		body3.setFillColor(sf::Color::Black);
	}

	else
		if(i==0)
		{
			body1.setFillColor(sf::Color::Black);
			body2.setFillColor(sf::Color::Black);
			body3.setFillColor(sf::Color::Black);
		}
		else if (i == 3)
		{
			body1.setFillColor(sf::Color::White);
			body2.setFillColor(sf::Color::White);
			body3.setFillColor(sf::Color::White);
		}
		
}
