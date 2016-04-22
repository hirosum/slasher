#include <SFML\Graphics.hpp>
#include "game.h"
#include "drawableCircle.h"
#include "drawableRectangle.h"
#include "actor.h"
#include "calculations.h"

//Constants
const int KEY_HOLD_TIMEOUT_LENGTH = 50;
const int WINDOW_HEIGHT = 800;
const int WINDOW_WIDTH = 600;

float circleRad			= 100.0f;
float circleX			= (WINDOW_WIDTH / 2) - circleRad;
float circleY			= (WINDOW_HEIGHT / 2) - circleRad;
float circleMoveSpeed	= 2.0f;
float circleResizeSpeed = 2.0f;

DrawableCircle circle(circleX,circleY,circleRad);
DrawableRectangle rect(0, 0, 50, 50);

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow wnd(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Works!", sf::Style::Default, settings);
	Actor act(circleX, circleY);
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
			if ((circle.getRadius() - circleResizeSpeed)<= 10.0f)
				circle.setRadius(10.0f);
			else
				circle.changeRadius(-circleResizeSpeed);
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
			if ((circle.getRadius() + circleResizeSpeed) >= maxCircleRad)
				circle.setRadius((float)maxCircleRad);
			else
			{
				circle.changeRadius(circleResizeSpeed);
			}
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
			if ((circle.getPositionX() - circleMoveSpeed) <= 0)
				circle.setPositionX(0.0f);
			else
				circle.move(-circleMoveSpeed,0);
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
			if ((circle.getPositionX() + circleMoveSpeed) >= WINDOW_WIDTH - (circle.getRadius() * 2))
				circle.setPositionX(WINDOW_WIDTH - (circleRad * 2));
			else
				circle.move(circleMoveSpeed,0);
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
			if ((circle.getPositionY() - circleMoveSpeed) <= 0)
				circle.setPositionY(0.0f);
			else
				circle.move(0,-circleMoveSpeed);
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
			if ((circle.getPositionY() + circleMoveSpeed) >= (WINDOW_HEIGHT - circleRad * 2))
				circle.setPositionY((WINDOW_HEIGHT - circleRad * 2));
			else
				circle.move(0,circleMoveSpeed);
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (holdCounters.downKeyCounter >= KEY_HOLD_TIMEOUT_LENGTH)
		{
			if ((circle.getPositionY() + circleMoveSpeed) >= (WINDOW_HEIGHT - circleRad * 2))
				circle.setPositionY((WINDOW_HEIGHT - circleRad * 2));
			else
				circle.move(0, circleMoveSpeed);
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
