#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


// create and fill tm struct with current system time
struct tm* get_current_time(){

time_t t = time(0);
struct tm *now = localtime(&t);
return now;

}

// START 0F NOTE CODE


// Print time contained in supplied tm struct
void print_time(struct tm* input_time){
	
cout << (input_time->tm_year + 1900) << '-'
	<< (input_time->tm_mon + 1) << '-'
	<< (input_time->tm_mday) << endl;
cout << (input_time->tm_hour) << ':'
	<< (input_time->tm_min) << ':'
	<< (input_time->tm_sec) << endl;
}


// Get note from user CL input
string takeNote(){

string note;

cout << "Inpute reminder: ";
getline(cin,note);
return note;

}



// Struct to contain notes and meta information
struct note_pkg
{
	string note;
	struct tm *creation_time;
};


// Create and fill note_pkg struct
note_pkg* make_note()
{
	note_pkg *pkg = new note_pkg();
	pkg->note = takeNote();
	pkg->creation_time = get_current_time();
	
	return pkg;
}

// EDIT THE FORMAT OF THIS TO LIKING LATER
// Print contents of note_pkg struct
void printNote(note_pkg* input_note)
{
	cout << input_note->note << endl;
	print_time(input_note->creation_time);	
}

// END OF NOTE CODE

// START OF LINKED LIST CODE


struct day_node
{
	day_node* next = NULL;
	day_node* previous = NULL;
	struct tm *day = get_current_time();	
};



class LLCalender
{
public:
	int number_of_nodes = 0;


	int removeNode(int node_position);	
	int addNode (int node_position, day_node *input_node);
	day_node* LLHandle = NULL; // start of list
	day_node* last_node = NULL; // end of list
private:





};


// Node position starts at 0 for the handle. Function will
// at node directly at this position, bumping all other nodes forward by 1.
int LLCalender::addNode (int node_position, day_node *input_node)
{
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

int LLCalender::removeNode(int node_position)
{
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


// END OF LINKED LIST CODE



int main(int argc, char *argv[])
{
	note_pkg *note1 = make_note();	
	printNote(note1);

	day_node *day1 = new day_node();
	day_node *day2 = new day_node();
	day_node *day3 = new day_node();
	day_node *day4 = new day_node();

	LLCalender *calender1 = new LLCalender();

	
	calender1->addNode(0,day1);
	calender1->addNode(1,day2);
	calender1->addNode(2,day3);
	calender1->addNode(3,day4);


	cout << calender1->LLHandle << endl;
	cout << day2->previous << endl;

	calender1->removeNode(0);

	cout << calender1->LLHandle << endl;
	cout << day2 << endl;

	cout << day2->previous << endl;

	
	return 0;
}

