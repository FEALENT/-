#pragma once
#include<iostream>
#include<string>
using namespace std;

//抽象职工类
class Worker
{
public:
	//显示个人信息
	virtual void show_info() = 0;

	//get DepID
	virtual string get_DepID() = 0;

	//职工编号
	int m_ID;
	string m_name;
	int m_DepID;
};
