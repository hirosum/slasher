#include "drawableCircle.h"
#include "windowHandle.h"

DrawableCircle::DrawableCircle(float pPosX, float pPosY, float pRad, 
								sf::Color pColor) : 
	Drawable(pPosX,pPosY),
	radius(pRad),
	shape(radius),
	color(pColor)
{
	shape.setPosition(worldPosition);
	color = pColor;
}

DrawableCircle::DrawableCircle(sf::Vector2f pPos, float pRad, 
								sf::Color pColor) :
	Drawable(pPos),
	radius(pRad),
	shape(radius),
	color(pColor)
{
	shape.setPosition(worldPosition);
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
	shape.setPosition(pPos, worldPosition.y);
}

void DrawableCircle::setPositionY(float pPos)
{
	Drawable::setPositionY(pPos);
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

void DrawableCircle::resize(float pAmount)
{
	if (radius + pAmount <= 1.0f)
		radius = 1.0f;
	else
		radius += pAmount;
	shape.setRadius(radius);
}

void DrawableCircle::draw(sf::RenderWindow* pWnd)
{
	shape.setFillColor(color);
	pWnd->draw(shape);
}

float DrawableCircle::getRadius()
{
	return radius;
}