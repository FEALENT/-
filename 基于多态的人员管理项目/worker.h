#pragma once
#include<iostream>
#include<string>
using namespace std;

//����ְ����
class Worker
{
public:
	//��ʾ������Ϣ
	virtual void show_info() = 0;

	//get DepID
	virtual string get_DepID() = 0;

	//ְ�����
	int m_ID;
	string m_name;
	int m_DepID;
};
