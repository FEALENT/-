#include "manager.h"

Manager::Manager(int id, string name, int did)
{
	this->m_DepID = did;
	this->m_ID = id;
	this->m_name = name;
}

void Manager::show_info()
{
	cout << "ID :" << this->m_ID
		<< "\tname: " << this->m_name
		<< "\tDepartmentID:" << this->m_DepID
		<< "\t��λְ�����Boss������ " << endl; ;
}

string Manager::get_DepID()
{
	return string("Manager");
}
