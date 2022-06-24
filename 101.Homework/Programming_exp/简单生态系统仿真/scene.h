#ifndef _SCENE_H
#define _SCENE_H

#include "basic.h"
#include "world.h"

class Scene
{
public:
	Scene(World &w);
	void update();	//更新场景
	void display(); //显示当前的场景
	void run();		//场景运行

private:
	World *world;
};

#endif // _SCENE_H