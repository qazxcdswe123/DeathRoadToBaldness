#ifndef _GRASS_H_
#define _GRASS_H_

#include "living.h"

class GrassUnit : public LivingUnit
{
public:
	GrassUnit(World *w, int r, int c)
	{
		pos.row = r;
		pos.colum = c;
		world = w;
	}

	State getState();
	State nextState();
	void round();
};

#endif // _GRASS_H_