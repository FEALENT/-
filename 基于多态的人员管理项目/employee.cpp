#include "employee.h"
Employee::Employee(int ID ,string name, int did)
{
	this->m_DepID = did;
	this->m_ID = ID;
	this->m_name = name;
}
void Employee::show_info()
{
	cout << "ID :" << this->m_ID 
		<< "\tname: " << this->m_name 
		<< "\tDepartmentID:" << this->m_DepID 
		<< "\t岗位职责：完成经理的任务 " << endl;
}
string Employee::get_DepID()
{
	return string("Employee");
}
