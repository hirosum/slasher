#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <SFML\Graphics.hpp>
#include "globals.h"

int smallerInt(int a, int b);

sf::Vector2f localPosToWorldPos(sf::Vector2f pParentWorldPos, sf::Vector2f pChildLocalPos);

bool withinScreenBounds(float pX1, float pY1, float pX2, float pY2);

#endif