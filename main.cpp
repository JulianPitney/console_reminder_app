#include <C:\\Users\\100489210\\Desktop\\console_reminder\\console_reminder_app\\console_planner.h>
#include <C:\\Users\\100489210\\Desktop\\console_reminder\\console_reminder_app\\shutdown.h>
#include <C:\\Users\\100489210\\Desktop\\console_reminder\\console_reminder_app\\startup.h>
#include <fstream>

using namespace std;




int main(int argc, char *argv[])
{
	LLCalender *listHandle = loadInstance("reminder_save_file.txt");
	if (listHandle == NULL)
	{
		cout << "Exiting program...\n";
		return 0;
	}
	else
	{
		checkListUpToDate(listHandle);
	}
	

	if (argc < 2)
	{
		cout << "Usage: note [-action]\n";
		cout << "[-help] for help \n";
		return 0;
	}
	
	string argument = argv[1];

	if (argument == "-help")
	{
		cout << "\n	Reminder program. Allows notes to be taken with time and date information saved \n	internally. Notes  from " <<
			"any arbritrary day can be requested and printed. \n\n" <<
			"	note [-n] [-x] \n\n" <<
			" -r		Take reminder for current day. \n" <<
			" -x -n		Prints info from last n days. \n\n";
			
		return 0;
	}
	else if (argument == "-r")
	{
		listHandle->createNote_InDayNode(listHandle->number_of_nodes - 1);
		cout << "\nNote has been added\n";
		printTime(getCurrentTime());
		saveInstance(listHandle);
	}
	else if (argument == "-x" && argv[2][0] == '-')
	{
		string temp = argv[2];
		string number = "";

		for (int i = 1; i < temp.size(); i++)
		{
			if (temp.at(i) == '0' || temp.at(i) == '1' || temp.at(i) == '2' || temp.at(i) == '3' ||
				temp.at(i) == '4' || temp.at(i) == '5' || temp.at(i) == '6' || temp.at(i) == '7' ||
				temp.at(i) == '8' || temp.at(i) == '9')
			{
				number += temp.at(i);
			}
			else
			{
				cout << endl;
				cout << temp.at(i) << " is not a number.\n";
				cout << "Usage: note [-action]\n";
				cout << "[-help] for help \n";
				return 0;
			}
		}

		if (number.size() > 6)
		{
			cout << "\nThat's way too many days. Calm down. \n";
			cout << "Usage: note [-action]\n";
			cout << "[-help] for help \n";
			return 0;
		}

		int actual_number = stoi(number);

		if (listHandle->number_of_nodes >= actual_number)
		{
			for (int i = listHandle->number_of_nodes - 1; i >= listHandle->number_of_nodes - actual_number; i--)
			{
				listHandle->printDayNode(i);

				if (i == listHandle->number_of_nodes - actual_number)
				{
					cout << "_________________________________________ \n";
					cout << "***************************************** \n";
				}
			}
		}
		else
		{
			cout << "Tried to print more days than there are in the list.\n\n";
		}
	}
	else
	{
		cout << "Usage: note [-action]\n";
		cout << "[-help] for help \n";
		return 0;
	}
	

	return 0;
}