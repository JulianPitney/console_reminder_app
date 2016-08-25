#include <startup.h>


struct tm* parseTimeStructStr(string timeStructStr)
{
	struct tm* outputTimeStruct = new struct tm;
	string time_token_temp_str = "";
	int time_token_temp_int;
	vector<int> time_token_arr;

	for (int i = 0; i < timeStructStr.size(); i++)
	{
		if (timeStructStr.at(i) == ';')
		{
			time_token_temp_int = stoi(time_token_temp_str);
			time_token_arr.push_back(time_token_temp_int);
			time_token_temp_str = "";
		}
		else
		{
			time_token_temp_str += timeStructStr.at(i);
		}
	}

	outputTimeStruct->tm_hour = time_token_arr.at(0);
	outputTimeStruct->tm_isdst = time_token_arr.at(1);
	outputTimeStruct->tm_mday = time_token_arr.at(2);
	outputTimeStruct->tm_min = time_token_arr.at(3);
	outputTimeStruct->tm_mon = time_token_arr.at(4);
	outputTimeStruct->tm_sec = time_token_arr.at(5);
	outputTimeStruct->tm_wday = time_token_arr.at(6);
	outputTimeStruct->tm_yday = time_token_arr.at(7);
	outputTimeStruct->tm_year = time_token_arr.at(8);

	return outputTimeStruct;
}


LLCalender* loadInstance(char *loadFilePath)
{
	ifstream input(loadFilePath);


	LLCalender *outputList = new LLCalender();

	string number_of_nodes_str; // This block gets the number of nodes we need to create/load
	getline(input, number_of_nodes_str);
	int number_of_nodes = stoi(number_of_nodes_str);

	for (int i = 0; i < number_of_nodes; i++)
	{
		outputList->addNode(i);

		string numbers_of_notes_str; // This block gets the number of notes in the current node
		getline(input, numbers_of_notes_str);
		int number_of_notes = stoi(numbers_of_notes_str);


		string node_init_time_unprocessed; // These 3 lines repopulate the struct containing the creation time of the current node
		getline(input, node_init_time_unprocessed);
		outputList->getDayNode(i)->dayInitTime = parseTimeStructStr(node_init_time_unprocessed);


		for (int z = 0; z < number_of_notes; z++)
		{
			string note_str;
			getline(input, note_str);
			Note *temp_note = new Note(note_str);
			struct tm *note_init_time = getCurrentTime();

			string node_init_time_unprocessed; // These 3 lines repopulate the struct containing the creation time of the current note
			getline(input, node_init_time_unprocessed);
			temp_note->noteInitTime = parseTimeStructStr(node_init_time_unprocessed);

			outputList->getDayNode(i)->noteList.push_back(*temp_note);
		}
	}

	return outputList;
}


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