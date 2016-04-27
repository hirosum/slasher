#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML\Graphics.hpp>

class GameObject
{
public:
	GameObject(float pPosX, float pPosY, float pPosZ);
	GameObject(sf::Vector3f pPos);

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

	void		 setParent(GameObject* pParent);
	void		 removeParent();

protected:
	sf::Vector3f worldPosition;
	sf::Vector3f localPosition;
	GameObject*  ptrParentObject;
	bool		 hasParent;
	
};

#endif