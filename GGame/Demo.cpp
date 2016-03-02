#include "GameLoop.h"



int main(int argc, char **argv)
{

	MG::GameLoop* game = new MG::GameLoop();

	game->run();

	delete game;

	return 0;
}