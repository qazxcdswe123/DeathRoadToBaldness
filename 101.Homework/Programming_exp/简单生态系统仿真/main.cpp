//一个简单的生态仿真系统

#include <iostream>
using namespace std;

#include "scene.h"

int main()
{
	World world(WORLD_OF_HUMAN);
	Scene scene(world);	

	scene.run();
	
	return 1;
}