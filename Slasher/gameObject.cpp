#include "gameObject.h"

GameObject::GameObject(float pPosX, float pPosY, float pPosZ) :
	worldPosition(pPosX, pPosY, pPosZ)
{

}

GameObject::GameObject(sf::Vector3f pPos) :
worldPosition(pPos)
{

}

void GameObject::setWorldPosition(sf::Vector3f pPos)
{
	//TODO do some sort of sanity check here
	worldPosition = pPos;
}

void GameObject::setWorldPosition(float pPosX, float pPosY, float pPosZ)
{
	//TODO do some sort of sanity check here
	worldPosition.x = pPosX;
	worldPosition.y = pPosY;
	worldPosition.z = pPosZ;
}

void GameObject::setWorldPositionX(float pPos)
{
	//TODO do some sort of sanity check here
	worldPosition.x = pPos;
}

void GameObject::setWorldPositionY(float pPos)
{
	//TODO do some sort of sanity check here
	worldPosition.y = pPos;
}

void GameObject::setWorldPositionZ(float pPos)
{
	//TODO do some sort of sanity check here
	worldPosition.z = pPos;
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

sf::Vector3f GameObject::getWorldPosition()
{
	return worldPosition;
}

float GameObject::getWorldPositionX()
{
	return worldPosition.x;
}

float GameObject::getWorldPositionY()
{
	return worldPosition.y;
}

float GameObject::getWorldPositionZ()
{
	return worldPosition.y;
}



void GameObject::setLocalPosition(sf::Vector3f pPos)
{
	//TODO do some sort of sanity check here
	localPosition = pPos;
}

void GameObject::setLocalPosition(float pPosX, float pPosY, float pPosZ)
{
	//TODO do some sort of sanity check here
	localPosition.x = pPosX;
	localPosition.y = pPosY;
	localPosition.z = pPosZ;
}

void GameObject::setLocalPositionX(float pPos)
{
	//TODO do some sort of sanity check here
	localPosition.x = pPos;
}

void GameObject::setLocalPositionY(float pPos)
{
	//TODO do some sort of sanity check here
	localPosition.y = pPos;
}

void GameObject::setLocalPositionZ(float pPos)
{
	//TODO do some sort of sanity check here
	localPosition.z = pPos;
}

void GameObject::moveLocal(sf::Vector2f pSpeed)
{
	//TODO do some sort of sanity check here
	localPosition.x += pSpeed.x;
	localPosition.y += pSpeed.y;
}

void GameObject::moveLocal(float pSpeedX, float pSpeedY)
{
	//TODO do some sort of sanity check here
	localPosition.x += pSpeedX;
	localPosition.y += pSpeedY;
}

sf::Vector3f GameObject::getLocalPosition()
{
	return localPosition;
}

float GameObject::getLocalPositionX()
{
	return localPosition.x;
}

float GameObject::getLocalPositionY()
{
	return localPosition.y;
}

float GameObject::getLocalPositionZ()
{
	return localPosition.y;
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