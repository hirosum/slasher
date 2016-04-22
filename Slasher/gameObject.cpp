#include "gameObject.h"

GameObject::GameObject(float pPosX, float pPosY) :
	position(pPosX,pPosY)
{

}

GameObject::GameObject(sf::Vector2f pPos) :
	position(pPos)
{

}

void GameObject::setPosition(sf::Vector2f pPos)
{
	//TODO do some sort of sanity check here
	position = pPos;
}

void GameObject::setPosition(float pPosX, float pPosY)
{
	//TODO do some sort of sanity check here
	position.x = pPosX;
	position.y = pPosY;
}

void GameObject::setPositionX(float pPos)
{
	//TODO do some sort of sanity check here
	position.x = pPos;
}

void GameObject::setPositionY(float pPos)
{
	//TODO do some sort of sanity check here
	position.y = pPos;
}

void GameObject::move(sf::Vector2f pSpeed)
{
	//TODO do some sort of sanity check here
	position.x += pSpeed.x;
	position.y += pSpeed.y;
}

void GameObject::move(float pSpeedX, float pSpeedY)
{
	//TODO do some sort of sanity check here
	position.x += pSpeedX;
	position.y += pSpeedY;
}

sf::Vector2f GameObject::getPosition()
{
	return position;
}

float GameObject::getPositionX()
{
	return position.x;
}

float GameObject::getPositionY()
{
	return position.y;
}

void GameObject::setParent(GameObject* pParent)
{
	ptrParentObject = pParent;
	hasParent = true;
}

void GameObject::removeParent()
{
	ptrParentObject = NULL;
	hasParent = false;
}