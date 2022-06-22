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