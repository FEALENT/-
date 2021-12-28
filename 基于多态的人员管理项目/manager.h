#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Manager :public Worker
{
public:
	Manager (int id,string name, int dep);
	virtual void show_info();
	virtual string get_DepID();

private:

};
