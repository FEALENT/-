#include<iostream>
#include"WorkerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"Boss.h"
using namespace std;

int main() {
	WorkerManager wm;
	int choice = 0;
	//// test coed
	//Worker* worker = NULL;
	//worker = new Employee(1, "Hong", 001);
	//worker->show_info();
	//delete worker;

	//worker = new Manager(2, "HONG", 002);
	//worker->show_info();
	//delete worker;

	//worker = new Boss(3, "AAAA", 003);
	//worker->show_info();
	//delete worker;


	
	while(true)
	{
		//调用Show_menu
		wm.show_Menu();

		cout << "您的操作" << endl;

		cin >> choice;
		
		switch (choice)
		{
		case 0://exit
			wm.exit_system();
			break;
		case 1://add
			wm.add_Emp();
			break;
		case 2://show
			wm.show_Emp();
			break;
		case 3://delete
			wm.Del_Emp();
			break; 
		case 4://change
			wm.Mod_Emp();
			break;
		case 5://search
			wm.Find_Emp();
			break;
		case 6://sort
			wm.Sort_Emp();
			break;
		case 7://clear
			wm.Clear_Emp();
			break;
		default:
			system("cls");
				break;
		}
	}
	


	system("pause");

	return 0;
}