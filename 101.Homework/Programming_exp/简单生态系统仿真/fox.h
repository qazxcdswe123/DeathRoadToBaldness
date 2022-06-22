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