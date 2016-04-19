#include "drawable.h"

Drawable::Drawable(float pPosX, float pPosY) : 
	GameObject(pPosX, pPosY)
{

}

Drawable::Drawable(sf::Vector2f pPos) : 
	GameObject(pPos)
{

}

void Drawable::setPosition(float pPosX, float pPosY)
{
	GameObject::setPosition(pPosX, pPosY);
}

void Drawable::setPosition(sf::Vector2f pPos)
{
	GameObject::setPosition(pPos);
}

void Drawable::setPositionX(float pPos)
{
	GameObject::setPositionX(pPos);
}

void Drawable::setPositionY(float pPos)
{
	GameObject::setPositionY(pPos);
}

void Drawable::move(sf::Vector2f pSpeed)
{
	GameObject::move(pSpeed);
}

void Drawable::move(float pSpeedX, float pSpeedY)
{
	GameObject::move(pSpeedX, pSpeedY);
}