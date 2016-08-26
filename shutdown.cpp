#include <C:\\Users\\100489210\\Desktop\\console_reminder\\console_reminder_app\\shutdown.h>


bool saveInstance(LLCalender *inputList)
{
	ofstream output("reminder_save_file.txt");
	output << inputList->number_of_nodes << endl; // Save number of nodes

	for (int i = 0; i < inputList->number_of_nodes; i++)
	{
		output << inputList->getDayNode(i)->noteList.size() << endl; // Save number of notes in each node

		struct tm *nodeInitTime = inputList->getDayNode(i)->dayInitTime; // This block saves the time that each node was created
		output << nodeInitTime->tm_hour << ";" << nodeInitTime->tm_isdst << ";" << nodeInitTime->tm_mday << ";" <<
			nodeInitTime->tm_min << ";" << nodeInitTime->tm_mon << ";" << nodeInitTime->tm_sec << ";" <<
			nodeInitTime->tm_wday << ";" << nodeInitTime->tm_yday << ";" << nodeInitTime->tm_year << ";" << endl;

		for (int x = 0; x < inputList->getDayNode(i)->noteList.size(); x++)
		{
			output << inputList->getDayNode(i)->noteList.at(x).note << endl; // Save notes from current node

			nodeInitTime = inputList->getDayNode(i)->noteList.at(x).noteInitTime; // Saves the time that each note was created
			output << nodeInitTime->tm_hour << ";" << nodeInitTime->tm_isdst << ";" << nodeInitTime->tm_mday << ";" <<
				nodeInitTime->tm_min << ";" << nodeInitTime->tm_mon << ";" << nodeInitTime->tm_sec << ";" <<
				nodeInitTime->tm_wday << ";" << nodeInitTime->tm_yday << ";" << nodeInitTime->tm_year << ";" << endl;
		}
	}

	output.close();
	return true;
}