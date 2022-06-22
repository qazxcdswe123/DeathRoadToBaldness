#include "fox.h"
#include "empty.h"

State FoxUnit::getState()
{
	return FOX;
}

State FoxUnit::nextState()
{
	round();

	if (sum[HUMAN] > sum[FOX])
	{
		return EMPTY;
	}
	else if (sum[FOX] > TMFOX)
	{
		return EMPTY;
	}
	else
	{
		if (age > DFOX)
		{
			return EMPTY;
		}
		else if (sum[RABBIT] == 0)
		{
			return EMPTY;
		}
		else
		{
			return FOX;
		}
	}
}

void FoxUnit::round()
{
	world->sums(pos, sum);
}