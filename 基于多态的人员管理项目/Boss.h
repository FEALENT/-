#pragma once
#include"manager.h"


class Boss :public Worker
{
public:
	Boss(int id, string name, int did);

	virtual void show_info();
	virtual string get_DepID();

};