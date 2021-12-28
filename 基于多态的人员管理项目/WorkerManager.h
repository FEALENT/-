#pragma once		//防止头文件重复包含
#include <iostream>
#include"worker.h"
#include<fstream>
using namespace std;
#define FILENAME "EmpFile.txt"

//职工管理  
//类实现
class WorkerManager
{
public:
	WorkerManager();
	~WorkerManager();

	//展示函数 
	void show_Menu();

	void exit_system();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//添加职工
	void add_Emp();

	//保存文件
	void save();

	//判断文件是否为空
	bool m_FileIsEmpty;

	//统计文件中的人数
	int m_getEmpNum();

	//初始化员工
	void init_Emp();

	//显示员工
	void show_Emp();

	//删除职工
	void Del_Emp();
	
	//职工是否存在,若不存在返回-1，若存在返回对应下标
	int is_exist(int id);

	//修改职工信息
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//排序
	void Sort_Emp();

	//清空
	void Clear_Emp();

	


private:

};