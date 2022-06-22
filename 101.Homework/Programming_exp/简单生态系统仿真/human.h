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