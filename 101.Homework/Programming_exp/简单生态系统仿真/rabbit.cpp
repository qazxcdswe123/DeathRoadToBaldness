#include "rabbit.h"
#include "empty.h"

State RabbitUnit::getState()
{
	return RABBIT;
}

State RabbitUnit::nextState()
{
	round();

	if (sum[RABBIT] > (sum[FOX] + sum[HUMAN]))
	{
		return RABBIT;
	}
	else if (age > DRAB)
	{
		return EMPTY;
	}
	else if (sum[GRASS] == 0)
	{
		return EMPTY;
	}
	else
	{
		return EMPTY;
	}
}

void RabbitUnit::round()
{
	world->sums(pos, sum);
}