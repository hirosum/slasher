#ifndef ACTOR_H
#define ACTOR_H

#include <SFML\Graphics.hpp>
#include <vector>
#include "drawable.h"
#include "drawableCircle.h"
#include "drawableRectangle.h"

class Actor : public Drawable
{
public:
	Actor(float pPosX, float pPosY);
	Actor(sf::Vector2f pPos);
	//Actor(const Actor& pActor);
	virtual void setPosition(float pPosX, float pPosY);
	virtual void setPosition(sf::Vector2f pPos);
	virtual void setPositionX(float pPos);
	virtual void setPositionY(float pPos);
	virtual void move(sf::Vector2f pSpeed);
	virtual void move(float pSpeedX, float pSpeedY);
	virtual void scale(float pScale);
	virtual void scale(float pScaleX, float pScaleY);
	virtual void draw(sf::RenderWindow& pWnd);
	void addToDrawableList(Drawable* pDrawable);
	void removeFromDrawList(Drawable* pDrawable);
private:
	std::vector<Drawable*> drawableParts;
};

#endif