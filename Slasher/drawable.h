#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "gameObject.h"

class Drawable : public GameObject
{
public:
	virtual void draw(sf::RenderWindow* pWnd){}
	Drawable(float pPosX, float pPosY);
	Drawable(sf::Vector2f pPos);
	//Drawable(const Drawable& pDrawable);
	virtual void setPosition(float pPosX, float pPosY);
	virtual void setPosition(sf::Vector2f pPos);
	virtual void setPositionX(float pPos);
	virtual void setPositionY(float pPos);
	virtual void move(sf::Vector2f pSpeed);
	virtual void move(float pSpeedX, float pSpeedY);
	virtual void scale(float pScale){}
	virtual void scale(float pScaleX, float pScaleY){}
protected:

	sf::Vector2f currentScale;
};

#endif