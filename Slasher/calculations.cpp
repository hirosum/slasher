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