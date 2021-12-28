//普通员工
#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Employee : public Worker
{
public:
	Employee(int ID, string name, int did);

	//显示个人信息
	virtual void show_info();

	//获取岗位名称
	virtual string get_DepID();
};
