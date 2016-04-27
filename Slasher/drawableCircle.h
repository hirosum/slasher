#ifndef DRAWABLECIRCLE_H
#define DRAWABLECIRCLE_H

#include "drawable.h"

class DrawableCircle : public Drawable
{
public:
	DrawableCircle(float pPosX, float pPosY,
					float pPosZ, float pRad);
	DrawableCircle(sf::Vector3f pPos, float pRad);

	virtual void setWorldPosition(float pPosX, float pPosY, float pPosZ);
	virtual void setWorldPosition(sf::Vector3f pPos);
	virtual void setWorldPositionX(float pPos);
	virtual void setWorldPositionY(float pPos);
	virtual void setWorldPositionZ(float pPos);
	virtual void move(sf::Vector2f pSpeed);
	virtual void move(float pSpeedX, float pSpeedY);
	sf::Vector3f getWorldPosition();
	float		 getWorldPositionX();
	float		 getWorldPositionY();
	float		 getWorldPositionZ();

	virtual void setLocalPosition(float pPosX, float pPosY, float pPosZ);
	virtual void setLocalPosition(sf::Vector3f pPos);
	virtual void setLocalPositionX(float pPos);
	virtual void setLocalPositionY(float pPos);
	virtual void setLocalPositionZ(float pPos);
	virtual void moveLocal(sf::Vector2f pSpeed);
	virtual void moveLocal(float pSpeedX, float pSpeedY);
	virtual sf::Vector3f getLocalPosition();
	virtual float		 getLocalPositionX();
	virtual float		 getLocalPositionY();
	virtual float		 getLocalPositionZ();

	virtual void draw(sf::RenderWindow& pWnd);
	void setRadius(float pRad);
	float getRadius();
	void changeRadius(float pAmount);
	void setColor(sf::Color pColor);
	virtual void scale(float pScale);
	virtual void scale(float pScaleX, float pScaleY);
private:
	float			  radius;
	sf::CircleShape   shape;
	sf::Color		  color;
};

#endif