#include "drawableRectangle.h"

DrawableRectangle::DrawableRectangle(float pPosX, float pPosY,
	float pLengthX, float pLengthY) : 
	Drawable(pPosX,pPosY),
	lengthOfSides(pLengthX, pLengthY),
	shape(lengthOfSides)
{
	setColor(sf::Color::Blue);
	shape.setPosition(position);
}

DrawableRectangle::DrawableRectangle(sf::Vector2f pPos, sf::Vector2f pLengthOfSides) :
	Drawable(pPos),
	lengthOfSides(pLengthOfSides),
	shape(lengthOfSides)
{
	setColor(sf::Color::Blue);
	shape.setPosition(position);
}


void DrawableRectangle::setPosition(float pPosX, float pPosY)
{
	Drawable::setPosition(pPosX, pPosY);
	shape.setPosition(pPosX, pPosY);
}

void DrawableRectangle::setPosition(sf::Vector2f pPos)
{
	Drawable::setPosition(pPos);
	shape.setPosition(pPos);
}

void DrawableRectangle::setPositionX(float pPos)
{
	Drawable::setPositionX(pPos);
	shape.setPosition(pPos, position.y);
}

void DrawableRectangle::setPositionY(float pPos)
{
	Drawable::setPositionY(pPos);
	shape.setPosition(position.x, pPos);
}

void DrawableRectangle::move(sf::Vector2f pSpeed)
{
	Drawable::move(pSpeed);
	shape.move(pSpeed);
}

void DrawableRectangle::move(float pSpeedX, float pSpeedY)
{
	Drawable::move(pSpeedX, pSpeedY);
	shape.move(pSpeedX, pSpeedY);
}

void DrawableRectangle::draw(sf::RenderWindow& pWnd)
{
	shape.setFillColor(color);
	pWnd.draw(shape);
}

void DrawableRectangle::scale(float pScale)
{
	shape.scale(pScale, pScale);
	currentScale = shape.getScale();
}

void DrawableRectangle::scale(float pScaleX, float pScaleY)
{
	shape.scale(pScaleX, pScaleY);
	currentScale = shape.getScale();
}

void DrawableRectangle::setColor(sf::Color pColor)
{
	color = pColor;
}