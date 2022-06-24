#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "living.h"

class HumanUnit : public LivingUnit
{
public:
	HumanUnit(World *w, int r, int c, int a = 0)
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

#endif // _HUMAN_H_