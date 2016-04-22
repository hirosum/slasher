#ifndef DRAWABLERECTANGLE_H
#define DRAWABLERECTANGLE_H
#include "drawable.h"

class DrawableRectangle : public Drawable
{
public:
	DrawableRectangle(float pPosX, float pPosY,float pLengthX, float pLengthY);
	DrawableRectangle(sf::Vector2f pPos, sf::Vector2f pLengthOfSides);
	//DrawableRectangle(const DrawableRectangle& pDrawableRectangle);
	virtual void scale(float pScale);
	virtual void scale(float pScaleX, float pScaleY);
	virtual void setPosition(float pPosX, float pPosY);
	virtual void setPosition(sf::Vector2f pPos);
	virtual void setPositionX(float pPos);
	virtual void setPositionY(float pPos);
	virtual void move(sf::Vector2f pSpeed);
	virtual void move(float pSpeedX, float pSpeedY);
	virtual void draw(sf::RenderWindow& pWnd);
	sf::Vector2f getLengthOfSides();
	void setColor(sf::Color pColor);
private:
	sf::Vector2f		lengthOfSides;
	sf::RectangleShape	shape;
	sf::Color			color;
};

#endif