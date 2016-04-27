#include "actor.h"

Actor::Actor(float pPosX, float pPosY,float pPosZ) :
Drawable(pPosX, pPosY,pPosZ)
{

}

Actor::Actor(sf::Vector3f pPos) :
Drawable(pPos)
{

}

void Actor::draw(sf::RenderWindow& pWnd)
{
	for (int i = 0; i < drawableParts.size(); i++)
	{
		drawableParts[i]->draw(pWnd);
	}
}

void Actor::setWorldPosition(float pPosX, float pPosY,float pPosZ)
{
	Drawable::setWorldPosition(pPosX, pPosY, pPosZ);
	for (int i = 0; i < drawableParts.size(); i++)
	{
		drawableParts[i]->setWorldPosition(pPosX, pPosY, pPosZ);
	}
}

void Actor::setWorldPosition(sf::Vector3f pPos)
{
	Drawable::setWorldPosition(pPos);
	for (int i = 0; i < drawableParts.size(); i++)
	{
		drawableParts[i]->setWorldPosition(pPos);
	}
}

void Actor::setWorldPositionX(float pPos)
{
	Drawable::setWorldPositionX(pPos);
	Drawable::setWorldPositionX(pPos); for (int i = 0; i < drawableParts.size(); i++)
	{
		drawableParts[i]->setWorldPositionX(pPos);
	}
}

void Actor::setWorldPositionY(float pPos)
{
	Drawable::setWorldPositionY(pPos);
	for (int i = 0; i < drawableParts.size(); i++)
	{
		drawableParts[i]->setWorldPositionY(pPos);
	}
}

void Actor::setWorldPositionZ(float pPos)
{
	Drawable::setWorldPositionZ(pPos);
	for (int i = 0; i < drawableParts.size(); i++)
	{
		drawableParts[i]->setWorldPositionZ(pPos);
	}
}

void Actor::move(sf::Vector2f pSpeed)
{
	Drawable::move(pSpeed);
	for (int i = 0; i < drawableParts.size(); i++)
	{
		drawableParts[i]->move(pSpeed);
	}
}

void Actor::move(float pSpeedX, float pSpeedY)
{
	Drawable::move(pSpeedX, pSpeedY);
	for (int i = 0; i < drawableParts.size(); i++)
	{
		drawableParts[i]->move(pSpeedX,pSpeedY);
	}
}

void Actor::scale(float pScale)
{

	for (int i = 0; i < drawableParts.size(); i++)
	{
		drawableParts[i]->scale(pScale);
	}
	currentScale *= pScale;
}

void Actor::scale(float pScaleX, float pScaleY)
{
	for (int i = 0; i < drawableParts.size(); i++)
	{
		drawableParts[i]->scale(pScaleX, pScaleY);
	}

	currentScale.x *= pScaleX;
	currentScale.y *= pScaleY;
}

void Actor::addToDrawableList(Drawable* pDrawable)
{
	drawableParts.push_back(pDrawable);
	drawableParts.back()->setParent(this);
}
