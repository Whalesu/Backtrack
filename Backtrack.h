#ifndef BACKTRACK
#define BACKTRACK

#include "Application.h";
#include "Position.h"；

class Backtrack
{
public:
	Backtrack(const Application& app);

	bool tryToSolve(Position pos);
protected:
	Applicaition app;
};
#endif