#include "Enemy.h"

Enemy::Enemy() 
{
	velocity.x = 500;
	velocity.y = 500;
}
Enemy::~Enemy() 
{

}
void Enemy::update(float dt, sf::Vector2f pos, sf::Vector2u winsize)
{
	

	if (pos.x +100 >= winsize.x || pos.x<=0)
	{
		velocity.x = velocity.x*-1;
	}
	if (pos.y +100 >= winsize.y || pos.y<=0)
	{
		velocity.y = velocity.y *-1;
	}

	move(velocity * dt);


}