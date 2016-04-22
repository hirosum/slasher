#include "drawableCircle.h"
#include "windowHandle.h"

DrawableCircle::DrawableCircle(float pPosX, float pPosY, float pRad) :
	Drawable(pPosX, pPosY),
	radius(pRad),
	shape(radius)
{
	shape.setPosition(position);
}

DrawableCircle::DrawableCircle(sf::Vector2f pPos, float pRad) :
	Drawable(pPos),
	radius(pRad),
	shape(radius)
{
	shape.setPosition(position);
}

void DrawableCircle::setRadius(float pRad)
{
	radius = pRad;
	shape.setRadius(radius);
}

void DrawableCircle::setPosition(float pPosX, float pPosY)
{
	Drawable::setPosition(pPosX, pPosY);
	shape.setPosition(pPosX, pPosY);
}

void DrawableCircle::setPosition(sf::Vector2f pPos)
{
	Drawable::setPosition(pPos);
	shape.setPosition(pPos);
}

void DrawableCircle::setPositionX(float pPos)
{
	Drawable::setPositionX(pPos);
	shape.setPosition(pPos, position.y);
}

void DrawableCircle::setPositionY(float pPos)
{
	Drawable::setPositionY(pPos);
	shape.setPosition(position.x, pPos);
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