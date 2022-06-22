#include "human.h"
#include "empty.h"

State HumanUnit::getState()
{
	return HUMAN;
}

State HumanUnit::nextState()
{
	round();

	if (sum[HUMAN] > TMHUM)
	{
		return EMPTY;
	}
	else if (age > DHUM)
	{
		return EMPTY;
	}
	else if (sum[RABBIT] == 0 && sum[FOX] == 0 && sum[GRASS] == 0)
	{
		return EMPTY;
	}
	else
	{
		return HUMAN;
	}
}

void HumanUnit::round()
{
	world->sums(pos, sum);
}