#include </home/julian/Source/Day_Planner/shutdown.h>

using namespace std;

bool saveInstance(LLCalender* input_calender)
{
	ofstream saveFile("reminder_save_file.txt");
	saveFile << input_calender->number_of_nodes << endl;
	string node_escape = "439chjiefve9vrjvfhkdj8_";
	string note_escape = "fd4873r4fh34uf3h439f44_";

	for (unsigned int i = 0; i < input_calender->number_of_nodes; i++)
	{
		
		struct tm tempTime = *input_calender->getDayNode(i)->dayInitTime;
		saveFile << tempTime.tm_hour << ";" << tempTime.tm_isdst << ";" << tempTime.tm_mday << ";"
			<< tempTime.tm_min << ";" << tempTime.tm_mon << ";" << tempTime.tm_sec << ";"
			<< tempTime.tm_wday << ";" << tempTime.tm_yday << ";" << tempTime.tm_year << ";" << endl;

		for (unsigned int x = 0; x < input_calender->getDayNode(i)->noteList.size(); x++)
		{
			saveFile << input_calender->getDayNode(i)->noteList.at(x).note << endl;
			tempTime = *input_calender->getDayNode(i)->noteList.at(x).noteInitTime;

			saveFile << tempTime.tm_hour << ";" << tempTime.tm_isdst << ";" << tempTime.tm_mday << ";"
				<< tempTime.tm_min << ";" << tempTime.tm_mon << ";" << tempTime.tm_sec << ";"
				<< tempTime.tm_wday << ";" << tempTime.tm_yday << ";" << tempTime.tm_year << ";" << endl;
			saveFile << note_escape << endl;
		}

		saveFile << node_escape << endl;

	}

	return true;
}
