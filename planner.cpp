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
	int appendNode(day_node *input_node);
	int removeNode(int node_position);	
	day_node* LLHandle = NULL; // start of list
	day_node* last_node = NULL; // end of list
private:





};


int LLCalender::appendNode(day_node *input_node)
{
	if (this->LLHandle == NULL)
	{
		LLHandle = input_node;
		last_node = input_node;
		return 0;
	}

	this->last_node->next = input_node;
	input_node->previous = this->last_node;
	this->last_node = input_node;
	return 0;
}

int LLCalender::removeNode(int node_position)
{
	return 0;
}


// END OF LINKED LIST CODE



int main(int argc, char *argv[])
{
	note_pkg *note1 = make_note();	
	printNote(note1);

	day_node *day1 = new day_node();
	day_node *day2 = new day_node();
	day_node *day3 = new day_node();

	LLCalender *calender1 = new LLCalender();

	calender1->appendNode(day1);
	calender1->appendNode(day2);
	calender1->appendNode(day3);

	return 0;
}

