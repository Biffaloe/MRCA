#include <iostream>
#include <fstream>
#include <iomanip>
#include "DataManagement.h"
using namespace std;


void DataManagement::SaveData()
{
	WorkData.open("Work_Data.txt", ios::out | ios::app);

	cout << setprecision(2) << fixed << showpoint;
	cout << "Please enter the work date this data is pertaining to. (MM DD YYYY)\n";
	cin >> month;
	cin >> day;
	cin >> year;
	cout << "Please enter the amount of tips you earned.\n";
	cin >> tips;
	cout << "Please enter the amount earned from your milage.\n";
	cin >> milageRate;
	cout << "Please enter the amount of hours spent on the road.\n";
	cin >> hoursRoad;
	cout << "Please enter the amount of hours spent in the store. \n";
	cin >> hoursInstore;
	cout << "Please enter the amount of deliveries you took.\n";
	cin >> deliveries;

	WorkData << month << "/" << day << "/" << year << endl;
	WorkData << tips << endl;
	WorkData << milageRate << endl;
	WorkData << hoursRoad << endl;
	WorkData << hoursInstore << endl;
	WorkData << deliveries << endl;

	cout << "Document saved.\n";

	WorkData.close();
}


void DataManagement::ShowData()
{
	int select;

	cout << "What would you like to do?\n1. Display Specific Date \n2. Display totals\n3. Show All dates\n";
	cin >> select;
	while (select < 1 || select > 3)
	{
		cout << "Please enter 1 or 2.\n";
		cin >> select;
	}

	if (select == 1)
		ShowSpecific();
	else if (select == 2)
		ShowTotal();
	else if (select == 3)
		ShowAll();
	else
		cout << "An error has occured with the select variable.\n";
}


void DataManagement::ShowTotal()
{
	int tempDeliveries = 0;
	double tempMilageRate = 0, tempTips = 0, tempHoursRoad = 0, tempHoursInstore = 0;
	double tempRoadWage = 0, tempInstoreWage = 0;
	double total;
	string line;

	WorkData.open("Work_Data.txt", ios::in || ios::beg);

	while (WorkData >> line)
	{
		WorkData >> tips >> milageRate >> hoursRoad >> hoursInstore >> deliveries;
		tempTips += tips;
		tempMilageRate += milageRate;
		tempHoursRoad += hoursRoad;
		tempHoursInstore += hoursInstore;
		tempDeliveries += deliveries;
	}

	tempRoadWage = tempHoursRoad * 4.00;
	tempInstoreWage = tempHoursInstore * 8.00;
	total = tempInstoreWage + tempRoadWage + tempTips + tempMilageRate;

	cout << "\nTotals:\n";
	cout << "Tips: $" << tempTips << endl << "Milage Rate: $" << tempMilageRate << endl << "Road Hours: " << tempHoursRoad << endl
		<< "Instore Hours: " << tempHoursInstore << endl << "# of Deliveries: " << tempDeliveries << endl;
	cout << "Total profit: $" << total << endl << endl;

	WorkData.close();
}


void DataManagement::ShowSpecific()
{
	string search, line;
	bool confirm = true;

	WorkData.open("Work_Data.txt", ios::in || ios::beg);
	cout << "Please enter the specific date you're looking for.   mm/dd/yyyy\n";
	cin >> search;

	size_t pos;
	while (WorkData.good())
	{
		getline(WorkData, line);
		pos = line.find(search);
		if (pos != string::npos)
		{
			confirm = false;
			WorkData >> tips >> milageRate >> hoursRoad >> hoursInstore >> deliveries;

			cout << "Tips: $" << tips << endl << "Milage Rate: $" << milageRate << endl << "Road Hours: " << hoursRoad << endl
				<< "Instore Hours: " << hoursInstore << endl << "# of Deliveries: " << deliveries << endl;
		}
	}
	if (confirm)
		cout << "The date you entered is not present in the data file.\n";

	WorkData.close();
}


void DataManagement::ShowAll()
{
	string line;
	WorkData.open("Work_Data.txt", ios::in || ios::beg);

	while (WorkData >> line)
	{
		WorkData >> tips >> milageRate >> hoursRoad >> hoursInstore >> deliveries;

		cout << line << endl;
		cout << "Tips: $" << tips << endl << "Milage Rate: $" << milageRate << endl << "Road Hours: " << hoursRoad << endl
			<< "Instore Hours: " << hoursInstore << endl << "# of Deliveries: " << deliveries << endl << endl;
	}

	WorkData.close();
}
