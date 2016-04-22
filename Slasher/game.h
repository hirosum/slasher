#ifndef GAME_H
#define GAME_H

void keyboardEventHandler();

struct KeyHeldCounters
{
	int addKeyCounter = 0;
	int subtractKeyCounter = 0;
	int leftKeyCounter = 0;
	int rightKeyCounter = 0;
	int upKeyCounter = 0;
	int downKeyCounter = 0;
};

#endif