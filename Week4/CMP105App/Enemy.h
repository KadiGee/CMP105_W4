#pragma once
#include "Framework/GameObject.h"
class Enemy: public GameObject
{

	
public:
	Enemy();
	~Enemy();
	void update(float, sf::Vector2f, sf::Vector2u);
};

