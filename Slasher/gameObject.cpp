#include "gameObject.h"

GameObject::GameObject(float pPosX, float pPosY) :
	worldPosition(pPosX,pPosY)
{

}

GameObject::GameObject(sf::Vector2f pPos) :
	worldPosition(pPos)
{

}

void GameObject::setPosition(sf::Vector2f pPos)
{
	//TODO do some sort of sanity check here
	worldPosition = pPos;
}

void GameObject::setPosition(float pPosX, float pPosY)
{
	//TODO do some sort of sanity check here
	worldPosition.x = pPosX;
	worldPosition.y = pPosY;
}

void GameObject::setPositionX(float pPos)
{
	//TODO do some sort of sanity check here
	worldPosition.x = pPos;
}

void GameObject::setPositionY(float pPos)
{
	//TODO do some sort of sanity check here
	worldPosition.y = pPos;
}

void GameObject::move(sf::Vector2f pSpeed)
{
	//TODO do some sort of sanity check here
	worldPosition.x += pSpeed.x;
	worldPosition.y += pSpeed.y;
}

void GameObject::move(float pSpeedX, float pSpeedY)
{
	//TODO do some sort of sanity check here
	worldPosition.x += pSpeedX;
	worldPosition.y += pSpeedY;
}

sf::Vector2f GameObject::getPosition()
{
	return worldPosition;
}

float GameObject::getPositionX()
{
	return worldPosition.x;
}

float GameObject::getPositionY()
{
	return worldPosition.y;
}