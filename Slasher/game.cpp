#include <SFML\Graphics.hpp>

float circleRad = 100.0f;

void keyboardEventHandler();
const int WINDOW_HEIGHT = 200;
const int WINDOW_WIDTH	= 200;

int main()
{
	sf::RenderWindow wnd(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Works!");
	sf::CircleShape shape(circleRad);
	shape.setFillColor(sf::Color::Green);

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
		shape.setRadius(circleRad);
		shape.setPosition((WINDOW_WIDTH / 2) - circleRad, (WINDOW_HEIGHT / 2) - circleRad);
		wnd.draw(shape);
		wnd.display();
	}
}
const int KEY_HOLD_TIMEOUT_LENGTH = 500;
void keyboardEventHandler()
{
	static int  holdLeftKeyTimer	  = 0;
	static int  holdRightKeyTimer	  = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (holdLeftKeyTimer >= KEY_HOLD_TIMEOUT_LENGTH)
		{
			circleRad -= 1;
			if (circleRad < 10.0f)
				circleRad = 10.0f;
			holdLeftKeyTimer = 0;
		}
		else
		{
			holdLeftKeyTimer++;
		}
	}
	else
	{
		holdLeftKeyTimer = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (holdRightKeyTimer >= KEY_HOLD_TIMEOUT_LENGTH)
		{
			circleRad += 1;
			if (circleRad > 100.0f)
				circleRad = 100.0f;
			holdRightKeyTimer = 0;
		}
		else
		{
			holdRightKeyTimer++;
		}
	}
	else
	{
		holdRightKeyTimer = 0;
	}
}