#ifndef _RABBIT_H_
#define _RABBIT_H_

#include "living.h"

class RabbitUnit : public LivingUnit
{
public:
	RabbitUnit(World *w, int r, int c, int a = 0) : age(a)
	{
		pos.row = r;
		pos.colum = c;
		world = w;
	}

	State getState();
	State nextState();
	void round();

protected:
	int age;
};

#endif // _RABBIT_H_