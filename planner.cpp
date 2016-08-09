#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;


// create and fill tm struct with current system time
struct tm* get_current_time(){

time_t t = time(0);
struct tm *now = localtime(&t);
return now;

}


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

// Print contents of note_pkg struct
void printNote(note_pkg* input_note)
{
	cout << input_note->note << endl;
	print_time(input_note->creation_time);	
}





int main(int argc, char *argv[])
{
	note_pkg *note1 = make_note();	
	printNote(note1);

	return 0;
}
