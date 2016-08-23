#include <console_calender.h>
#include <console_planner.h>
#include <fstream>

using namespace std;

const string loadFilePath = "C:\\Users\\ZeroLife\\Documents\\Visual Studio 2015\\Projects\\console_reminder\\console_reminder\\reminder_save_file.txt"; // Set this to path of load file
const string saveFilePatrh = ""; // Set this to path where list should be saved


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

	return false;
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

		string node_init_time_unprocessed;
		getline(input, node_init_time_unprocessed);
		int init_time_token = 0;
		string node_init_time_token = "";

		for (unsigned int x = 0; x < node_init_time_unprocessed.size(); x++) // The mess inside this loop populates the struct tm contained in the current node to set it to the time that the node was created
		{
			if (node_init_time_unprocessed.at(x) == ';')
			{
				switch (init_time_token)
				{
				case(0):
					outputList->getDayNode(i)->dayInitTime->tm_hour = stoi(node_init_time_token);
					node_init_time_token = "";
					init_time_token++;
					break;
				case(1):
					outputList->getDayNode(i)->dayInitTime->tm_isdst = stoi(node_init_time_token);
					node_init_time_token = "";
					init_time_token++;
					break;
				case(2):
					outputList->getDayNode(i)->dayInitTime->tm_mday = stoi(node_init_time_token);
					node_init_time_token = "";
					init_time_token++;
					break;
				case(3):
					outputList->getDayNode(i)->dayInitTime->tm_min = stoi(node_init_time_token);
					node_init_time_token = "";
					init_time_token++;
					break;
				case(4):
					outputList->getDayNode(i)->dayInitTime->tm_mon = stoi(node_init_time_token);
					node_init_time_token = "";
					init_time_token++;
					break;
				case(5):
					outputList->getDayNode(i)->dayInitTime->tm_sec = stoi(node_init_time_token);
					node_init_time_token = "";
					init_time_token++;
					break;
				case(6):
					outputList->getDayNode(i)->dayInitTime->tm_wday = stoi(node_init_time_token);
					node_init_time_token = "";
					init_time_token++;
					break;
				case(7):
					outputList->getDayNode(i)->dayInitTime->tm_yday = stoi(node_init_time_token);
					node_init_time_token = "";
					init_time_token++;
					break;
				case(8):
					outputList->getDayNode(i)->dayInitTime->tm_year = stoi(node_init_time_token);
					node_init_time_token = "";
					init_time_token++;
					break;
				default:
					break;
				}
			}
			else
			{
				node_init_time_token += node_init_time_unprocessed.at(x);
			}
		}


		for (int z = 0; z < number_of_notes; z++)
		{
			string note_str;
			getline(input, note_str);
			Note *temp_note = new Note(note_str);
			struct tm *note_init_time = getCurrentTime();

			string node_init_time_unprocessed;
			getline(input, node_init_time_unprocessed);
			int init_time_token = 0;
			string node_init_time_token = "";
			
			for (unsigned int x = 0; x < node_init_time_unprocessed.size(); x++) // The mess inside this loop populates the struct tm contained in the current node to set it to the time that the node was created
			{
				if (node_init_time_unprocessed.at(x) == ';')
				{
					switch (init_time_token)
					{
					case(0):
						note_init_time->tm_hour = stoi(node_init_time_token);
						node_init_time_token = "";
						init_time_token++;
						break;
					case(1):
						note_init_time->tm_isdst = stoi(node_init_time_token);
						node_init_time_token = "";
						init_time_token++;
						break;
					case(2):
						note_init_time->tm_mday = stoi(node_init_time_token);
						node_init_time_token = "";
						init_time_token++;
						break;
					case(3):
						note_init_time->tm_min = stoi(node_init_time_token);
						node_init_time_token = "";
						init_time_token++;
						break;
					case(4):
						note_init_time->tm_mon = stoi(node_init_time_token);
						node_init_time_token = "";
						init_time_token++;
						break;
					case(5):
						note_init_time->tm_sec = stoi(node_init_time_token);
						node_init_time_token = "";
						init_time_token++;
						break;
					case(6):
						note_init_time->tm_wday = stoi(node_init_time_token);
						node_init_time_token = "";
						init_time_token++;
						break;
					case(7):
						note_init_time->tm_yday = stoi(node_init_time_token);
						node_init_time_token = "";
						init_time_token++;
						break;
					case(8):
						note_init_time->tm_year = stoi(node_init_time_token);
						node_init_time_token = "";
						init_time_token++;
						break;
					default:
						break;
					}
				}
				else
				{
					node_init_time_token += node_init_time_unprocessed.at(x);
				}
			}
			temp_note->noteInitTime = note_init_time;
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

int main(int argc, char *argv[])
{
	LLCalender *listHandle = NULL;

	listHandle = loadInstance("C:\\Users\\ZeroLife\\Documents\\Visual Studio 2015\\Projects\\console_reminder\\console_reminder\\reminder_save_file.txt");

	listHandle->printList();


}