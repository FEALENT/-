#include"WorkerManager.h"
#include"employee.h"
#include"manager.h"
#include"Boss.h"
#include"worker.h"

WorkerManager::WorkerManager() {
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //读文件
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化属性
		this->m_EmpNum = 0;			//初始化人数
		this->m_EmpArray = NULL;	//初始化数组
		this->m_FileIsEmpty = true; //初始化文件为空标志
		ifs.close();
		return;
	}
	
	//文件存在，但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
	}

	//文件存在，并记录数据
	int num = this->m_getEmpNum();
	//cout << "employee number = " << num << endl;

	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];

	//将文件数据存入数组
	this->init_Emp(); 
	//test
	//for (int i = 0; i < this ->m_EmpNum; i++)
	//{
	//	cout << "id : " << this->m_EmpArray[i]->m_ID
	//		<< " name : " << this->m_EmpArray[i]->m_name
	//		<< " Departmet ID : " << this->m_EmpArray[i]->m_DepID << endl;
	//}

}

WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{//删除每个堆区职工对象(二维数组指向对象及二维指针)

			//delete 清空指针指向的对象
			delete this->m_EmpArray[i];

			//..ptr = NULL 为清空指针
			this->m_EmpArray[i] = NULL;
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

void WorkerManager::show_Menu() {
	cout << " *************welcome************* " << endl;
	cout << " ************0.exit   ************ " << endl;
	cout << " ************1.add    ************ " << endl;
	cout << " ************2.show   ************ " << endl;
	cout << " ************3.delete ************ " << endl;
	cout << " ************4.change ************ " << endl;
	cout << " ************5.search ************ " << endl;
	cout << " ************6.sort   ************ " << endl;
	cout << " ************7.clear  ************ " << endl;
}

void WorkerManager::exit_system()
{
	cout << "欢迎下次使用 " << endl;
	system("pause");
	exit(0);
}

void WorkerManager::add_Emp()
{
	cout << "How many want to add" << endl;
	int add_num;
	cin >> add_num;

	if (add_num > 0)
	{//add

		//计算添加新空间大小
		int new_size = this->m_EmpNum + add_num;//新空间大小 = 原有人数 + 要添加的大小

		//开辟新空间
		Worker** newSpace = new Worker * [new_size];

		//将原有的数据复制
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//添加新数据
		for (int i = 0; i < add_num; i++)
			{
				int id;
				string name;
				int dselect;
				int index = 0;
				while (index != -1)
				{
					cout << "the " << i + 1 << " employee ID" << endl;
					cin >> id;

					index = this->is_exist(id);

					if (index != -1)
						cout << "ID已存在" << endl;
				}

				
				

				cout << "the " << i + 1 << " employee name" << endl;
				cin >> name;

				cout << "the employee department" << endl;
				cout << "1.emplyee\t"
					<< "2.manager\t"
					<< "3.Boss" << endl;
				cin >> dselect;

				Worker* worker = NULL;
				switch (dselect)
				{
					case 1:
						worker = new Employee(id, name, dselect);
						break;
					case 2:
						worker = new Manager(id, name, dselect);
						break;

					case 3:
						worker = new Boss(id, name, dselect);
						break;


					default:
						break;
				}
				//将职工指针保存到数组中
				newSpace[this->m_EmpNum + i] = worker;
			}


			//释放原有空间
			delete[] this->m_EmpArray;

			//更改新空间指向
			this->m_EmpArray = newSpace;

			//更新职工人数
			this->m_EmpNum = new_size;

			//修改文件是否为空的标志
			this->m_FileIsEmpty = false;

			//提示添加成功
			cout << "have added  " << add_num << " Worker" << endl;

			//保存
			this->save();

		
		
	}
	else
	{
		cout << "ERROR: add number not larger than 0" << endl;
	}

	//按任意键清屏，回到上级目录
	system("pause");
	system("cls");
	
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //用输出的方式打开文件  --写文件

	//将每个人的数据写入文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_DepID << endl;

	}
	ofs.close();
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int Did;
	int index = 0;

	while (ifs>>id && ifs>>name && ifs>>Did)
	{
		Worker* worker = NULL;

		if (Did == 1)
		{
			worker = new Employee(id, name, Did);

		}
		else if (Did == 2)
		{
			worker = new Manager(id, name, Did);

		}
		else
		{
			worker = new Boss(id, name, Did);
		}
		this->m_EmpArray[index] = worker;

		index++;
	}

	ifs.close();
}

void WorkerManager::show_Emp()
{
	if (this->m_FileIsEmpty )
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		cout << "employee number = " << m_EmpNum << endl;

		for (int i = 0; i < m_EmpNum; i++)
		{
			//多态调用接口
			this->m_EmpArray[i]->show_info();

		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty )
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		//按编号删除职工
		cout << "请输入要删除的职工编号" << endl;

		int id;
		cin >> id;

		int index = this->is_exist(id);

		if (index != -1)
		{//此职工存在，进行删除,即数据前移
			for (int i = index; i < this->m_EmpNum -1  ; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//更新记录人数

			//同步到文件
			this->save();

			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败,此职工不存在" << endl;
		}


	}


	system("pause");
	system("cls");
}

int WorkerManager::is_exist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (id == this->m_EmpArray[i]->m_ID )
		{

			index = i;

			break;
		}
	}

	return index;
}

void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		cout << "请输入要编辑的员工编号" << endl;

		int id;
		cin >> id;
		
		int index = this->is_exist(id);
		if (index != -1)
		{
			//职工存在

			//释放原有数据
			delete this->m_EmpArray[index];

			//定义新信息

			int new_id = 0;
			string new_name = "";
			int new_Did = 0;

			cout << "查找到" << id << "号员工" << endl << "请输入新的编号" << endl;
			cin >> new_id;

			cout << "新的姓名" << endl;
			cin >> new_name;

			cout << "新的岗位ID" << endl << "1.Employee\t2.Manager\t3.Boss" << endl;
			cin >> new_Did;

			Worker* worker = NULL;
			switch (new_Did)
			{
			case 1:
				worker = new Employee(new_id, new_name, new_Did);
				break;
			case 2:
				worker = new Manager(new_id, new_name, new_Did);
				break;
			case 3:
				worker = new Boss(new_id, new_name, new_Did);
				break;
			default:
				break;
			}

			//更新数据
			this->m_EmpArray[index] = worker;

			cout << "修改成功" << endl;

			//保存至文件

			this->save();

		}
		else
		{
			cout << "查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::m_getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //打开文件

	int id;
	string name;
	int Did;
	int num = 0;

	while (ifs>>id &&ifs>>name && ifs>>Did)
	{
		//统计人数
		num++;
	}

	return num;
}

void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty )
	{
		cout << "文件为空或不存在" << endl;
	}
	else
	{
		cout << "1.按照编号查找" << endl;
		cout << "2.按照姓名查找" << endl;

		int select;
		cin >> select;

		switch (select )
		{

		case 1:
		{int id;
		cout << "请输入ID" << endl;
		cin >> id;

		int ret = this->is_exist(id);
		if (ret != -1)
		{
			//找到职工
			cout << "查找成功" << endl;
			this->m_EmpArray[ret]->show_info();
		}
		else
		{
			cout << "查找失败" << endl;
		}

		break; 
		}
			

		case 2:
		{
			string name;
			cout << "请输入姓名" << endl;
			cin >> name;

			//加入是否找到的标志
			bool flag = false;

			for (int i = 0; i < this->m_EmpNum ; i++)
			{
				if (name == this->m_EmpArray[i]->m_name)
				{
					cout << "查找成功" << endl;
					this->m_EmpArray[i]->show_info();

					flag = true;
					break;
				}
			}

			if (!flag)
				cout << "查找失败" << endl; 
			
			break;
		}
		default:

			cout << "输入有误" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}

void WorkerManager::Sort_Emp()
{

	if (this->m_FileIsEmpty) {
		cout << "文件不存在或空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择升序或者降序排列" << endl;
		cout << "1.升序\t 2.降序" << endl;

		int select;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrmax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{//升序
					if (this->m_EmpArray[minOrmax]->m_ID > this->m_EmpArray[j]->m_ID)
					{
						minOrmax = j;
					}
				}
				else if (select == 2)
				{//降序
					if (this->m_EmpArray[minOrmax]->m_ID < this->m_EmpArray[j]->m_ID)
					{
						minOrmax = j;
					}
				}

			}
			//判断minOrmax和i是否相等，若不相等，按顺序交换
			if (i != minOrmax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrmax];
				this->m_EmpArray[minOrmax] = temp;
			}
		}
		cout << "排序成功,排序后的结果" << endl;

		this->save();

		this->show_Emp();
	}

	
}

void WorkerManager::Clear_Emp()
{
	cout << "确定是否清空" << endl << "Y/N" << endl;
	char select;
	cin >> select;

	if (select == 'Y')
	{
		//清空文件
		ofstream ofs(FILENAME, ios::trunc); //删除文件后重新创建
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)	
			{//删除每个堆区职工对象(二维数组指向对象及二维指针)

				//delete 清空指针指向的对象
				delete this->m_EmpArray[i];

				//..ptr = NULL 为清空指针
				this->m_EmpArray[i] = NULL;
			}

			//删除数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;

			

		}
		cout << "清空成功" << endl;

	}

	system("pause");
	system("cls");
}
