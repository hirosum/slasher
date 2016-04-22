#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <SFML\Graphics.hpp>

int smallerInt(int a, int b);

sf::Vector2f localPosToWorldPos(sf::Vector2f pParentWorldPos, sf::Vector2f pChildLocalPos);

#endif