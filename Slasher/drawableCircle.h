#include "drawable.h"

class DrawableCircle : public Drawable
{
public:
	DrawableCircle(float pPosX, float pPosY, 
					float pRad, 
					sf::Color pColor);
	DrawableCircle(sf::Vector2f pPos, float pRad,
					sf::Color pColor);
	virtual void draw(sf::RenderWindow* pWnd);
	void setRadius(float pRad);
	float getRadius();
	void resize(float pAmount);
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