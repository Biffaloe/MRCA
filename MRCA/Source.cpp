#include <iostream>
#include <fstream>
#include <iomanip>
#include "DataManagement.h"
using namespace std;

int main()
{
	DataManagement Data;
	int select;
	char confirm;

	cout << "This program will ask for and compile all your driver information.\n";

	do
	{
		cout << "What would you like to  do?\n1. Save Data \n2. Show Compiled Data \n";
		cin >> select;
		while (select < 1 || select > 2)
		{
			cout << "Please enter 1 or 2.\n";
			cin >> select;
		}
	
		if (select == 1)
			Data.SaveData();
		else if (select == 2)
			Data.ShowData();
		else
			cout << "An error has occured with the select variable.\n";

		cout << "Would you like to quit? Y/N\n";
		cin >> confirm;

	} while (confirm != 'y' || confirm != 'Y');




	return 0;
}