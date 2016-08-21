#include <startup.h>


// Scans LLCalender to determine whether the current day is later than the day the last node was added to the list.
// If it is, it adds a node for today to the list and returns true, otherwise it does nothing and retrns false.
bool checkListUpToDate(LLCalender* input_calender)
{
	if (input_calender == NULL) // Case: Received NULL ptr argument
	{
		cout << "Error: startup_proc() received NULL argument\n";
		return false;
	}
	else if (input_calender->last_node == NULL) // Case: input_calender LL is empty
	{
		input_calender->appendToday();
		return true;
	}

	struct tm *now = getCurrentTime();
	if (input_calender->last_node->dayInitTime->tm_year < now->tm_year) // Case: Last node was added to input_calender at an earlier year
	{
		delete now;
		input_calender->appendToday();
		return true;
	}
	else if (input_calender->last_node->dayInitTime->tm_yday < now->tm_yday) // Case: Last node was added to input_calender at an earlier day
	{
		delete now;
		input_calender->appendToday();
		return true;
	}
	else // Case: Last node was added to input_calender today
	{
		delete now;
		return false;
	}



}



LLCalender* loadList(char *loadFilePath)
{
	ifstream loadFile;
	loadFile.open(loadFilePath, std::ifstream::out);

	// Unpack size of list
	string sizeStr;
	getline(loadFile, sizeStr);
	int listSize = stoi(sizeStr);

	LLCalender *outputList = new LLCalender();

	for (int i = 0; i < listSize; i++)
	{
		outputList->addNode(i);
	}
	

	return outputList;
}