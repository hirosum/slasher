#include "windowHandle.h"

WindowHandle* WindowHandle::s_pInstance = nullptr;

WindowHandle* WindowHandle::Instance()
{
	if (s_pInstance == nullptr)
	{
		s_pInstance = new WindowHandle();
	}
	return s_pInstance;
}

WindowHandle::WindowHandle()
{
	window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Works!");
}

sf::RenderWindow* WindowHandle::getWindow()
{
	return window;
}

