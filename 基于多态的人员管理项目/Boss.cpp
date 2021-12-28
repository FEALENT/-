#include "Boss.h"

Boss::Boss(int ID, string name, int did)
{
	this->m_DepID = did;
	this->m_ID = ID;
	this->m_name = name;
}
void Boss::show_info()
{
	cout << "ID :" << this->m_ID 
		<< "\tname: " << this->m_name 
		<< "\tDepartmentID:" << this->m_DepID 
		<< "\t岗位职责：管理 " << endl;
}

string Boss::get_DepID()
{
	return string("Boss");
}