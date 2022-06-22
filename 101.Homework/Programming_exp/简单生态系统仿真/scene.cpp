#include <iostream>
using namespace std;

#include "scene.h"
#include "living.h"

Scene::Scene(World &w)
{
	world = &w;
}

void Scene::update()
{
	world->update();
}

void Scene::display()
{
	world->display();
}

void Scene::run()
{
	for (int i = 0; i < CYCLES; ++i)
	{
		update();
		display();
	}
}