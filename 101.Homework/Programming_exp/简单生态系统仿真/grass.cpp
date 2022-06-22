#include "grass.h"
#include "empty.h"

State GrassUnit::getState()
{
	return GRASS;
}

State GrassUnit::nextState()
{
	round();
	if (sum[GRASS] > (sum[RABBIT] + sum[HUMAN]))
	{
		return GRASS;
	}
	else
	{
		return EMPTY;
	}
}

void GrassUnit::round()
{
	world->sums(pos, sum);
}