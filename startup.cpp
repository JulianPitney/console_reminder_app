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
	day_node *temp_node = NULL;
	string time_unprocessed = "";
	string time_field = "";

	for (int i = 0; i < listSize; i++)
	{
		outputList->addNode(i);
		temp_node = outputList->getDayNode(i);
		int current_structTm_field = 0;
		getline(loadFile, time_unprocessed);

		for (unsigned int i = 0; i < time_unprocessed.size(); i++)
		{
			if (time_unprocessed.at(i) == ';')
			{
				switch (current_structTm_field)
				{
				case(0):
					temp_node->dayInitTime->tm_hour = stoi(time_field);
					current_structTm_field++;
					time_field = "";
					break;
				case(1):
					temp_node->dayInitTime->tm_isdst = stoi(time_field);
					current_structTm_field++;
					time_field = "";
					break;
				case(2):
					temp_node->dayInitTime->tm_mday = stoi(time_field);
					current_structTm_field++;
					time_field = "";
					break;
				case(3):
					temp_node->dayInitTime->tm_min = stoi(time_field);
					current_structTm_field++;
					time_field = "";
					break;
				case(4):
					temp_node->dayInitTime->tm_mon = stoi(time_field);
					current_structTm_field++;
					time_field = "";
					break;
				case(5):
					temp_node->dayInitTime->tm_sec = stoi(time_field);
					current_structTm_field++;
					time_field = "";
					break;
				case(6):
					temp_node->dayInitTime->tm_wday = stoi(time_field);
					current_structTm_field++;
					time_field = "";
					break;
				case(7):
					temp_node->dayInitTime->tm_yday = stoi(time_field);
					current_structTm_field++;
					time_field = "";
					break;
				case(8):
					temp_node->dayInitTime->tm_year = stoi(time_field);
					current_structTm_field++;
					time_field = "";
					break;
				default:
					break;
				}
			}
			else
			{
				time_field += time_unprocessed.at(i);
			}

			
		}


	}
	

	return outputList;
}