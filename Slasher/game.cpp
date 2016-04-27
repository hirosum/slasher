#include <SFML\Graphics.hpp>
#include "game.h"
#include "drawableCircle.h"
#include "drawableRectangle.h"
#include "actor.h"
#include "calculations.h"



float circleRad			= 100.0f;
sf::Vector3f circlePos((WINDOW_WIDTH / 2) - circleRad,
						(WINDOW_HEIGHT / 2) - circleRad, 3.0f);
sf::Vector3f rectPos(0, 0, 2);
sf::Vector2f rectDims(50, 50);
float actorMoveSpeed	= 2.0f;
float actorResizeSpeed = 2.0f;

Actor act(0,0);

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow wnd(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Works!", sf::Style::Default, settings);
	DrawableCircle circle(circlePos, circleRad);
	DrawableRectangle rect(rectPos, rectDims);
	circle.setColor(sf::Color::Green);
	rect.setColor(sf::Color::Magenta);
	act.addToDrawableList(&circle);
	act.addToDrawableList(&rect);
	while (wnd.isOpen())
	{
		sf::Event ev;
		while (wnd.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
				wnd.close();
		}
		keyboardEventHandler();
		wnd.clear();
		act.draw(wnd);
		wnd.display();
	}
}

void keyboardEventHandler()
{
	static KeyHeldCounters holdCounters;
	int maxCircleRad = (smallerInt(WINDOW_HEIGHT, WINDOW_WIDTH) / 2);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
	{
		if (holdCounters.subtractKeyCounter >= KEY_HOLD_TIMEOUT_LENGTH)
		{
			//TODO decrease object size
			holdCounters.subtractKeyCounter = 0;
		}
		else
		{
			holdCounters.subtractKeyCounter++;
		}
	}
	else
	{
		holdCounters.subtractKeyCounter = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
	{
		if (holdCounters.addKeyCounter >= KEY_HOLD_TIMEOUT_LENGTH)
		{
			//TODO increase object size
			holdCounters.addKeyCounter = 0;
		}
		else
		{
			holdCounters.addKeyCounter++;
		}
	}
	else
	{
		holdCounters.addKeyCounter = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (holdCounters.leftKeyCounter >= KEY_HOLD_TIMEOUT_LENGTH)
		{
			//TODO decrease X pos
			act.move(-actorMoveSpeed, 0);
			holdCounters.leftKeyCounter = 0;
		}
		else
		{
			holdCounters.leftKeyCounter++;
		}
	}
	else
	{
		holdCounters.leftKeyCounter = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (holdCounters.rightKeyCounter >= KEY_HOLD_TIMEOUT_LENGTH)
		{
			//TODO increase X pos
			act.move(actorMoveSpeed, 0);
			holdCounters.rightKeyCounter = 0;
		}
		else
		{
			holdCounters.rightKeyCounter++;
		}
	}
	else
	{
		holdCounters.rightKeyCounter = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (holdCounters.upKeyCounter >= KEY_HOLD_TIMEOUT_LENGTH)
		{
			//TODO decrease Y pos
			act.move(0, -actorMoveSpeed);
			holdCounters.upKeyCounter = 0;
		}
		else
		{
			holdCounters.upKeyCounter++;
		}
	}
	else
	{
		holdCounters.upKeyCounter = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (holdCounters.downKeyCounter >= KEY_HOLD_TIMEOUT_LENGTH)
		{
			//TODO increase Y pos
			act.move(0, actorMoveSpeed);
			holdCounters.downKeyCounter = 0;
		}
		else
		{
			holdCounters.downKeyCounter++;
		}
	}
	else
	{
		holdCounters.downKeyCounter = 0;
	}
}
