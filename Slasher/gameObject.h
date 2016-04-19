#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML\Graphics.hpp>

class GameObject
{
public:
	GameObject(float pPosX, float pPosY);
	GameObject(sf::Vector2f pPos);
	virtual void setPosition(float pPosX, float pPosY);
	virtual void setPosition(sf::Vector2f pPos);
	virtual void setPositionX(float pPos);
	virtual void setPositionY(float pPos);
	virtual void move(sf::Vector2f pSpeed);
	virtual void move(float pSpeedX, float pSpeedY);
	sf::Vector2f getPosition();
	float getPositionX();
	float getPositionY();
protected:
	sf::Vector2f worldPosition;
	
};

#endif