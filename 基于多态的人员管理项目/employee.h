//��ͨԱ��
#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Employee : public Worker
{
public:
	Employee(int ID, string name, int did);

	//��ʾ������Ϣ
	virtual void show_info();

	//��ȡ��λ����
	virtual string get_DepID();
};
