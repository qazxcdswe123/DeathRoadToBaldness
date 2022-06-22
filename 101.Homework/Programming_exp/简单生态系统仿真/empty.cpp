#include "empty.h"

State EmptyUnit::getState()
{
	return EMPTY;
}

State EmptyUnit::nextState()
{
	round();

	if (sum[FOX] > 1)
	{
		return FOX;
	}
	else
	{
		if (sum[RABBIT] > 1)
		{
			return RABBIT;
		}
		else
		{
			if (sum[GRASS] > 1)
			{
				return GRASS;
			}
			else
			{
				if (sum[HUMAN] > 1)
				{
					return HUMAN;
				}
				else
				{

					return EMPTY;
				}
			}
		}
	}
}

void EmptyUnit::round()
{
	world->sums(pos, sum);
}