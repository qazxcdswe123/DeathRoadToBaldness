#ifndef _FOX_H_
#define _FOX_H_

#include "living.h"

class FoxUnit : public LivingUnit
{
public:
	FoxUnit(World *w, int r, int c, int a = 0) : age(a)
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

#endif // _FOX_H_