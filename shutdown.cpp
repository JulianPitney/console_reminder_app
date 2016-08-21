#include <shutdown.h>

using namespace std;

bool saveInstance(LLCalender* input_calender, char *saveFilePath)
{
	ofstream saveFile(saveFilePath);
	saveFile << input_calender->number_of_nodes << endl;
	string node_escape = "439chjiefve9vrjvfhkdj8_";
	string note_escape = "fd4873r4fh34uf3h439f44_";


	// Loop to save each node
	for (unsigned int i = 0; i < input_calender->number_of_nodes; i++)
	{
		
		// Save time of node creation
		struct tm tempTime = *input_calender->getDayNode(i)->dayInitTime;
		saveFile << tempTime.tm_hour << ";" << tempTime.tm_isdst << ";" << tempTime.tm_mday << ";"
			<< tempTime.tm_min << ";" << tempTime.tm_mon << ";" << tempTime.tm_sec << ";"
			<< tempTime.tm_wday << ";" << tempTime.tm_yday << ";" << tempTime.tm_year << ";" << endl;


		// Loop to save all notes inside node
		for (unsigned int x = 0; x < input_calender->getDayNode(i)->noteList.size(); x++)
		{
			// Save actual note
			saveFile << input_calender->getDayNode(i)->noteList.at(x).note << endl;

			// Save time of note creation
			tempTime = *input_calender->getDayNode(i)->noteList.at(x).noteInitTime;
			saveFile << tempTime.tm_hour << ";" << tempTime.tm_isdst << ";" << tempTime.tm_mday << ";"
				<< tempTime.tm_min << ";" << tempTime.tm_mon << ";" << tempTime.tm_sec << ";"
				<< tempTime.tm_wday << ";" << tempTime.tm_yday << ";" << tempTime.tm_year << ";" << endl;

			// Escape string to mark end of note
			saveFile << note_escape << endl;
		}

		// Escape string to mark end of node
		saveFile << node_escape << endl;

	}

	saveFile.close();
	return true;
}