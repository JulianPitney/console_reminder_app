#include <C:\\Users\\100489210\\Desktop\\console_reminder\\console_reminder_app\\console_planner.h>

  //**********************************************************************//
 //					Time Functions 									     //
//**********************************************************************//


struct tm* getCurrentTime() {

	time_t t = time(0);
	struct tm *now = new struct tm;
	localtime_s(now, &t);
	return now;
}

void printTime(struct tm *inputTime)
{
	cout << (inputTime->tm_year + 1900) << '-'
		<< (inputTime->tm_mon + 1) << '-'
		<< (inputTime->tm_mday) << endl;
	cout << (inputTime->tm_hour) << ':'
		<< (inputTime->tm_min) << ':'
		<< (inputTime->tm_sec) << "\n\n";
}


  //**********************************************************************//
 //					Note Class									         //
//**********************************************************************//


Note::Note()
{
	note = this->getUserNote();
	noteInitTime = getCurrentTime();
}

Note::Note(string input_note)
{
	note = input_note;
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




  //**********************************************************************//
 //					LLCalender Class									 //
//**********************************************************************//


// Node position starts at 0 for the handle. Function will
// at node directly at this position, bumping all other nodes forward by 1.
int LLCalender::addNode (unsigned int node_position)
{
	if (node_position > this->number_of_nodes || node_position < 0)
	{
		cout << "Error: addNode() tried to add node to invalid position in list ( <0 or >2 past end of list)\n";
		return -1;
	}

	day_node *new_node = new day_node;

	if (node_position == 0 && this->LLHandle == NULL) // Case: LL is empty
	{
		LLHandle = new_node;
		last_node = new_node;
		this->number_of_nodes++;
		return 0;
	}
	else if (node_position == 0 && this->LLHandle != NULL) // Case: Adding node to start of non empty list
	{
		new_node->next = this->LLHandle;
		this->LLHandle->previous = new_node;
		this->LLHandle = new_node;
		this->number_of_nodes++;

		return 0;
	}
	else if (node_position == this->number_of_nodes) // Case: Appending to end of list
	{
		this->last_node->next = new_node;
		new_node->previous = this->last_node;
		this->last_node = new_node;
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

		new_node->previous = temp_node->previous;
		new_node->next = temp_node;
		temp_node->previous->next = new_node;
		temp_node->previous = new_node;
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
		this->number_of_nodes++;
		return 0;
	}

	this->last_node->next = today; // Case: appending to end of non-empty list
	today->previous = this->last_node;
	this->last_node = today;
	this->number_of_nodes++; 
	return 0;
}

// Prints list. Add contents you want printed + format later.
void LLCalender::printList()
{
	for (unsigned int i = 0; i < this->number_of_nodes; i++)
	{
		this->printDayNode(i);
	}

	
}

// Returns pointer to day_node at position nodePos in list. Returns NULL if error.
day_node* LLCalender::getDayNode(unsigned int nodePos)
{
	if (nodePos >= this->number_of_nodes || nodePos < 0)
	{
		cout << "Error: getDayNode() tried to access node at invalid position in list ( <0 or past end of list)\n";
		return NULL;
	}

	day_node* outputNode = this->LLHandle;
	for (unsigned int i = 0; i < nodePos; i++)
	{
		outputNode = outputNode->next;
	}

	return outputNode;
}

// Creates note inside day_node returned by getDayNode()
void LLCalender::createNote_InDayNode(unsigned int nodePos)
{
	day_node *temp = this->getDayNode(nodePos);
	if (temp != NULL)
	{
		temp->noteList.push_back(Note());
	}
	else
	{
		cout << "Error: createNote_InDayNote() tried to create note inside NULL day_node ptr\n";
	}
	
}

// Returns Note object from specified day_node in list. Returns NULL on failure.
Note* LLCalender::getNote_FromDayNode(unsigned int nodePos, unsigned int noteIndex)
{
	if (noteIndex < 0 || noteIndex >= this->number_of_nodes)
	{
		cout << "Error: getNote_FromDayNode() tried to access note outside bounds of vector\n";
		return NULL;
	}

	day_node *temp = this->getDayNode(nodePos);
	if (temp == NULL)
	{
		cout << "Error: getNote_FromDayNode() detected NULL pointer returned from getDayNode()\n";
		return NULL;
	}
	else
	{
		return &temp->noteList.at(noteIndex);
	}
}

void LLCalender::printDayNode(unsigned int nodePos)
{
	day_node *node_to_print = this->getDayNode(nodePos);

	for (unsigned int i = 0; i < node_to_print->noteList.size(); i++)
	{
		node_to_print->noteList.at(i).printNote();
	}
}






