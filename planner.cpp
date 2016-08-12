#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


struct tm* getCurrentTime() {

	time_t t = time(0);
	struct tm *now = new struct tm;
	localtime_s(now, &t);
	return now;
}


/***************************************/


class Note
{
public:

	string note;
	struct tm *noteInitTime;

	Note();
	string getUserNote();
	void printNote();

private:
};


Note::Note()
{
	note = this->getUserNote();
	noteInitTime = getCurrentTime();
}

string Note::getUserNote()
{
	string note;

	cout << "Inpute reminder: ";
	getline(cin, note);
	return note;
}

// Print time contained in supplied tm struct
void Note::printNote(){
	
	cout << (noteInitTime->tm_year + 1900) << '-'
		 << (noteInitTime->tm_mon + 1) << '-'
		 << (noteInitTime->tm_mday) << endl;
	cout << (noteInitTime->tm_hour) << ':'
		 << (noteInitTime->tm_min) << ':'
		 << (noteInitTime->tm_sec) << "\n\n";

	cout << note << endl;

}










struct day_node
{
	day_node* next = NULL;
	day_node* previous = NULL;
	struct tm *dayInitTime = getCurrentTime();
	vector<Note> noteList;
};

class LLCalender
{
public:
	int number_of_nodes = 0;
	day_node* LLHandle = NULL; // start of list
	day_node* last_node = NULL; // end of list

	int removeNode(unsigned int node_position);	
	int addNode (unsigned int node_position, day_node *input_node);
	int appendToday();

	void printList();

private:





};

// Prints list. Add contents you want printed + format later.
void LLCalender::printList()
{
	day_node *temp_node = this->LLHandle;

	while (temp_node->next != NULL)
	{
		cout << temp_node << endl;
		temp_node = temp_node->next;
	}

	cout << temp_node << endl;
}

// Node position starts at 0 for the handle. Function will
// at node directly at this position, bumping all other nodes forward by 1.
int LLCalender::addNode (unsigned int node_position, day_node *input_node)
{
	if (node_position > this->number_of_nodes || node_position < 0)
	{
		cout << "Error: addNode() tried to add node to invalid position in list ( <0 or >2 past end of list)\n";
		return -1;
	}

	if (node_position == 0 && this->LLHandle == NULL) // Case: LL is empty
	{
		LLHandle = input_node;
		last_node = input_node;
		this->number_of_nodes++;
		return 0;
	}
	else if (node_position == this->number_of_nodes) // Case: Appending to end of list
	{
		this->last_node->next = input_node;
		input_node->previous = this->last_node;
		this->last_node = input_node;
		this->number_of_nodes++;
		return 0;
	}
	else // Case: Adding node to occupied position within list and list is non-empty
	{
		day_node* temp_node = this->LLHandle;

		for (unsigned int i = 0; i < node_position; i++) 
		{
			temp_node = temp_node->next;
		}	

		input_node->previous = temp_node->previous;
		input_node->next = temp_node;
		temp_node->previous->next = input_node;
		temp_node->previous = input_node;
		this->number_of_nodes++;
		return 0;	
	}
}

int LLCalender::removeNode(unsigned int node_position)
{
	if (node_position > this->number_of_nodes || node_position < 0)
	{
		cout << "Error: removeNode() tried to add node to invalid position in list ( <0 or >2 past end of list)\n";
		return -1;
	}

	if (this->LLHandle == NULL && this->number_of_nodes == 0) // Case1: List already empty
	{
		cout << "Error: Tried to remove node from empty linked list\n";
	}
	else if (this->LLHandle->next == NULL && node_position == 0) // Case2: Removing only node in list
	{
		delete this->LLHandle;
		this->LLHandle = NULL;
		this->last_node = NULL;
		this->number_of_nodes--;
		cout << "Removed node " << node_position << " from list\n";
		return 0;
	}
	else // Case3: Removing node with >2 elements
	{
		day_node *temp_node = this->LLHandle;

		for (unsigned int i = 0; i < node_position; i++)
		{
			temp_node = temp_node->next;
		}


		if (this->number_of_nodes == node_position + 1) // Case3a: Removing end of list 
		{
			temp_node->previous->next = NULL;
			this->last_node = temp_node->previous;
			delete temp_node;
			this->number_of_nodes--;
			cout << "Removed node " << node_position << " from list\n";
			return 0;
		}
		else if (node_position == 0) // Case3b: Removing start of list
		{
			temp_node->next->previous = NULL;
			this->LLHandle = temp_node->next;
			delete temp_node;
			this->number_of_nodes--;
			cout << "Removed node " << node_position << " from list\n";
			return 0;
		}
		else // Case3c: Removing somewhere between start and end of list
		{
			temp_node->previous->next = temp_node->next;
			temp_node->next->previous = temp_node->previous;
			delete temp_node;
			this->number_of_nodes--;
			cout << "Removed node " << node_position << " from list\n";
			return 0;
		}
	}
	
}

// Creates a node for current day and appends it to list
int LLCalender::appendToday()
{
	day_node *today = new day_node();

	if (this->LLHandle == NULL) // Case: no nodes in list
	{
		this->LLHandle = today;
		this->last_node = today;
		return 0;
	}

	this->last_node->next = today; // Case: appending to end of non-empty list
	today->previous = this->last_node;
	this->last_node = today;
	this->number_of_nodes++; 
	return 0;
}


// END OF LINKED LIST CODE



int main(int argc, char *argv[])
{
	
	LLCalender *calender = new LLCalender();

	calender->appendToday();



	


	
	return 0;
}

