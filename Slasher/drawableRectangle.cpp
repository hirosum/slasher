#include "drawableRectangle.h"

DrawableRectangle::DrawableRectangle(float pPosX, float pPosY, float pPosZ,
										float pLengthX, float pLengthY) : 
	Drawable(pPosX,pPosY,pPosZ),
	lengthOfSides(pLengthX, pLengthY),
	shape(lengthOfSides)
{
	setColor(sf::Color::Blue);
	shape.setPosition(worldPosition.x, worldPosition.y);
}

DrawableRectangle::DrawableRectangle(sf::Vector3f pPos, sf::Vector2f pLengthOfSides) :
	Drawable(pPos),
	lengthOfSides(pLengthOfSides),
	shape(lengthOfSides)
{
	setColor(sf::Color::Blue);
	shape.setPosition(worldPosition.x, worldPosition.y);
}


void DrawableRectangle::setWorldPosition(float pPosX, float pPosY, float pPosZ)
{
	Drawable::setWorldPosition(pPosX, pPosY, pPosZ);
	shape.setPosition(worldPosition.x, worldPosition.y);
}

void DrawableRectangle::setWorldPosition(sf::Vector3f pPos)
{
	Drawable::setWorldPosition(pPos);
	shape.setPosition(worldPosition.x, worldPosition.y);
}

void DrawableRectangle::setWorldPositionX(float pPos)
{
	Drawable::setWorldPositionX(pPos);
	shape.setPosition(pPos, worldPosition.y);
}

void DrawableRectangle::setWorldPositionY(float pPos)
{
	Drawable::setWorldPositionY(pPos);
	shape.setPosition(worldPosition.x, pPos);
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




void DrawableRectangle::setLocalPosition(float pPosX, float pPosY, float pPosZ)
{
	Drawable::setLocalPosition(pPosX, pPosY, pPosZ);
	shape.setPosition(worldPosition.x, worldPosition.y);
}

void DrawableRectangle::setLocalPosition(sf::Vector3f pPos)
{
	Drawable::setLocalPosition(pPos);
	shape.setPosition(worldPosition.x, worldPosition.y);
}

void DrawableRectangle::setLocalPositionX(float pPos)
{
	Drawable::setLocalPositionX(pPos);
	shape.setPosition(pPos, worldPosition.y);
}

void DrawableRectangle::setLocalPositionY(float pPos)
{
	Drawable::setLocalPositionY(pPos);
	shape.setPosition(worldPosition.x, pPos);
}

void DrawableRectangle::moveLocal(sf::Vector2f pSpeed)
{
	Drawable::move(pSpeed);
	shape.move(pSpeed);
}

void DrawableRectangle::moveLocal(float pSpeedX, float pSpeedY)
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