#include "drawableCircle.h"
#include "calculations.h"

DrawableCircle::DrawableCircle(float pPosX, float pPosY, float pPosZ, float pRad) :
	Drawable(pPosX, pPosY,pPosZ),
	radius(pRad),
	shape(radius)
{
	shape.setPosition(worldPosition.x, worldPosition.y);
}

DrawableCircle::DrawableCircle(sf::Vector3f pPos, float pRad) :
	Drawable(pPos),
	radius(pRad),
	shape(radius)
{
	shape.setPosition(worldPosition.x, worldPosition.y);
}

void DrawableCircle::setRadius(float pRad)
{
	radius = pRad;
	shape.setRadius(radius);
}

void DrawableCircle::setWorldPosition(float pPosX, float pPosY,float pPosZ)
{
	Drawable::setWorldPosition(pPosX, pPosY, pPosZ);
	shape.setPosition(worldPosition.x, worldPosition.y);
}

void DrawableCircle::setWorldPosition(sf::Vector3f pPos)
{
	Drawable::setWorldPosition(pPos);
	shape.setPosition(worldPosition.x, worldPosition.y);
}

void DrawableCircle::setWorldPositionX(float pPos)
{
	Drawable::setWorldPositionX(pPos);
	shape.setPosition(pPos, worldPosition.y);
}

void DrawableCircle::setWorldPositionY(float pPos)
{
	Drawable::setWorldPositionY(pPos);
	shape.setPosition(worldPosition.x, pPos);
}

void DrawableCircle::move(sf::Vector2f pSpeed)
{
	Drawable::move(pSpeed);
	shape.move(pSpeed);
}

void DrawableCircle::move(float pSpeedX, float pSpeedY)
{
	Drawable::move(pSpeedX,pSpeedY);
	shape.move(pSpeedX, pSpeedY);
}

void DrawableCircle::setLocalPosition(float pPosX, float pPosY, float pPosZ)
{
	Drawable::setLocalPosition(pPosX, pPosY, pPosZ);
	shape.setPosition(localPosToWorldPos(ptrParentObject->getWorldPosition, 
											sf::Vector2f(localPosition.x, localPosition.y)));
}

void DrawableCircle::setLocalPosition(sf::Vector3f pPos)
{
	if (hasParent)
	{
		Drawable::setLocalPosition(pPos);
		shape.setPosition(localPosToWorldPos(ptrParentObject->getWorldPosition, 
												sf::Vector2f(localPosition.x, localPosition.y)));
	}
}

void DrawableCircle::setLocalPositionX(float pPos)
{
	if (hasParent)
	{
		Drawable::setLocalPositionX(pPos);
		shape.setPosition(localPosToWorldPos(ptrParentObject->getWorldPosition, 
												sf::Vector2f(pPos, localPosition.y)));
	}
}

void DrawableCircle::setLocalPositionY(float pPos)
{
	if (hasParent)
	{
		Drawable::setLocalPositionY(pPos);
		shape.setPosition(localPosToWorldPos(ptrParentObject->getWorldPosition,
												sf::Vector2f(localPosition.x, pPos)));
	}
}

void DrawableCircle::moveLocal(sf::Vector2f pSpeed)
{
	Drawable::moveLocal(pSpeed);
	shape.move(pSpeed);
}

void DrawableCircle::moveLocal(float pSpeedX, float pSpeedY)
{
	Drawable::moveLocal(pSpeedX, pSpeedY);
	shape.move(pSpeedX, pSpeedY);
}

void DrawableCircle::changeRadius(float pAmount)
{
	if (radius + pAmount <= 1.0f)
		radius = 1.0f;
	else
		radius += pAmount;
	shape.setRadius(radius);
}

void DrawableCircle::draw(sf::RenderWindow& pWnd)
{
	shape.setFillColor(color);
	pWnd.draw(shape);
}

float DrawableCircle::getRadius()
{
	return radius;
}

void DrawableCircle::scale(float pScale)
{
	shape.scale(pScale, pScale);
	currentScale = shape.getScale();
}

void DrawableCircle::scale(float pScaleX, float pScaleY)
{
	shape.scale(pScaleX, pScaleY);
	currentScale = shape.getScale();
}

void DrawableCircle::setColor(sf::Color pColor)
{
	color = pColor;
}