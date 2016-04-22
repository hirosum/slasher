#ifndef DRAWABLECIRCLE_H
#define DRAWABLECIRCLE_H

#include "drawable.h"

class DrawableCircle : public Drawable
{
public:
	DrawableCircle(float pPosX, float pPosY,
					float pRad);
	DrawableCircle(sf::Vector2f pPos, float pRad);
	//DrawableCircle(const DrawableCircle& pDrawableCircle);
	virtual void draw(sf::RenderWindow& pWnd);
	void setRadius(float pRad);
	float getRadius();
	void changeRadius(float pAmount);
	void setColor(sf::Color pColor);
	virtual void scale(float pScale);
	virtual void scale(float pScaleX, float pScaleY);
	virtual void setPosition(float pPosX, float pPosY);
	virtual void setPosition(sf::Vector2f pPos);
	virtual void setPositionX(float pPos);
	virtual void setPositionY(float pPos);
	virtual void move(sf::Vector2f pSpeed);
	virtual void move(float pSpeedX, float pSpeedY);
private:
	float			  radius;
	sf::CircleShape   shape;
	sf::Color		  color;
};

#endif