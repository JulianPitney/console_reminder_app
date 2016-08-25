#include <console_planner.h>
#include <shutdown.h>
#include <startup.h>
#include <fstream>

using namespace std;

const string loadFilePath = "C:\\Users\\ZeroLife\\Documents\\Visual Studio 2015\\Projects\\console_reminder\\console_reminder\\reminder_save_file.txt"; // Set this to path of load file
const string saveFilePatrh = ""; // Set this to path where list should be saved


int main(int argc, char *argv[])
{
	LLCalender *listHandle = loadInstance("C:\\Users\\ZeroLife\\Documents\\Visual Studio 2015\\Projects\\console_reminder\\console_reminder\\reminder_save_file.txt");
	checkListUpToDate(listHandle);

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
			"	note [-n] [-t] [-l] [-x] \n\n" <<
			" -n		Take reminder for current day. \n" <<
			" -t		Prints info from current day. \n" <<
			" -x -n		Prints info from last n days. \n\n";
			
		return 0;
	}
	else if (argument == "-n")
	{
		listHandle->createNote_InDayNode(listHandle->number_of_nodes - 1);
		cout << "\nNote has been added\n";
		printTime(getCurrentTime());
		saveInstance(listHandle);
	}
	else if (argument == "-t")
	{
		listHandle->printDayNode(listHandle->number_of_nodes - 1);
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
				cout << temp.at(i) << " is not a number.\n\n";
				return 0;
			}
		}

		int actual_number = stoi(number);

		if (listHandle->number_of_nodes >= actual_number)
		{
			for (int i = listHandle->number_of_nodes - 1; i >= listHandle->number_of_nodes - actual_number; i--)
			{
				listHandle->printDayNode(i);
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