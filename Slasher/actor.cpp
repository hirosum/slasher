#include "actor.h"

Actor::Actor(float pPosX, float pPosY) :
Drawable(pPosX, pPosY)
{

}

Actor::Actor(sf::Vector2f pPos) :
Drawable(pPos)
{

}

void Actor::draw(sf::RenderWindow& pWnd)
{
	for (int i = 0; i < drawableParts.size(); i++)
	{
		drawableParts[i]->draw(&pWnd);
	}
}

void Actor::setPosition(float pPosX, float pPosY)
{
	Drawable::setPosition(pPosX, pPosY);
	for (int i = 0; i < drawableParts.size(); i++)
	{
		drawableParts[i]->setPosition(pPosX, pPosY);
	}
}

void Actor::setPosition(sf::Vector2f pPos)
{
	Drawable::setPosition(pPos);
	for (int i = 0; i < drawableParts.size(); i++)
	{
		drawableParts[i]->setPosition(pPos);
	}
}

void Actor::setPositionX(float pPos)
{
	Drawable::setPositionX(pPos);
	Drawable::setPositionX(pPos); for (int i = 0; i < drawableParts.size(); i++)
	{
		drawableParts[i]->setPositionX(pPos);
	}
}

void Actor::setPositionY(float pPos)
{
	Drawable::setPositionY(pPos);
	for (int i = 0; i < drawableParts.size(); i++)
	{
		drawableParts[i]->setPositionY(pPos);
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
