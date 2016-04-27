#include "drawable.h"

Drawable::Drawable(float pPosX, float pPosY,float pPosZ) : 
	GameObject(pPosX, pPosY, pPosZ),
	currentScale(1.0f, 1.0f)
{

}

Drawable::Drawable(sf::Vector3f pPos) : 
	GameObject(pPos),
	currentScale(1.0f, 1.0f)
{

}