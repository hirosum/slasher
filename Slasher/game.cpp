#include <SFML\Graphics.hpp>
#include "game.h"
#include "drawableCircle.h"
#include "windowHandle.h"
//Constants
const int KEY_HOLD_TIMEOUT_LENGTH	= 500;

float circleRad			= 100.0f;
float circleX			= (WINDOW_WIDTH / 2) - circleRad;
float circleY			= (WINDOW_HEIGHT / 2) - circleRad;
float circleMoveSpeed	= 10.0f;
float circleResizeSpeed = 10.0f;

DrawableCircle circle(circleX,circleY,circleRad,sf::Color(100,100,100));
sf::RenderWindow* wnd;

int main()
{
	WindowHandle* wndHandle = WindowHandle::Instance();
	wnd = wndHandle->getWindow();

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	while (wnd->isOpen())
	{
		sf::Event ev;
		while (wnd->pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
				wnd->close();
		}
		keyboardEventHandler();
		wnd->clear();
		circle.draw(wnd);
		//wnd->draw(shape);
		wnd->display();
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
				circle.resize(-circleResizeSpeed);
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
				circle.setRadius(maxCircleRad);
			else
			{
				circle.resize(circleResizeSpeed);
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
}

int smallerInt(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}