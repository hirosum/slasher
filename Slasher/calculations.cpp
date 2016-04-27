#include "calculations.h"

int smallerInt(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

sf::Vector2f localPosToWorldPos(sf::Vector2f pParentWorldPos, sf::Vector2f pChildLocalPos)
{
	sf::Vector2f childWorldSpace;
	childWorldSpace.x = pChildLocalPos.x - pParentWorldPos.x;
	childWorldSpace.y = pChildLocalPos.y - pParentWorldPos.y;
	return childWorldSpace;
}

bool withinScreenBounds(float pX1, float pY1, float pX2, float pY2)
{
	if (pX1 < 0 || pX2 > WINDOW_WIDTH ||
		pY1 < 0 || pY2 > WINDOW_HEIGHT)
		return false;
	return true;
}