#ifndef _LIVING_H_
#define _LIVING_H_

#include "basic.h"

#include "world.h"

class LivingUnit //单元格对象，分为 空的，草，兔、狐狸 等
{
public:
	virtual State getState() = 0;  //获取生物所在位置的当前仿真时刻状态
	virtual State nextState() = 0; //该单元下一个仿真时刻的状态
	virtual void round() = 0;	   //周围态势，得到各类生物数目统计

protected:
	Position pos;	 //所在的位置
	World *world;	 //所在的世界
	int sum[STATES]; //所在位置附近的各类生物数目统计
};

#endif // _LIVING_H_