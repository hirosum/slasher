#ifndef WINDOWHANDLE_H
#define WINDOWHANDLE_H

#include <SFML\Graphics.hpp>

const int WINDOW_HEIGHT = 800;
const int WINDOW_WIDTH = 600;

class WindowHandle
{
public:

	static WindowHandle* Instance();

	WindowHandle();

	sf::RenderWindow* getWindow();

private:
	static WindowHandle* s_pInstance;

	sf::RenderWindow* window;
};


#endif