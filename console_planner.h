#ifndef CONSOLE_PLANNER_H
#define CONSOLE_PLANNER_H
#include <iostream>                                     
#include <string>									   
#include <ctime>
#include <vector>

using namespace std;

  //**********************************************************************//
 //					Time Functions 									     //
//**********************************************************************//


struct tm* getCurrentTime(); 
void printTime(struct tm *inputTime);


  //**********************************************************************//
 //					Note Class									         //
//**********************************************************************//


class Note
{
public:
	Note();
	string getUserNote();
	void printNote();

private:
	string note;
	struct tm *noteInitTime;
};


  //**********************************************************************//
 //					LLCalender Class									 //
//**********************************************************************//


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
	int addNode(unsigned int node_position);
	int appendToday();

	void createNote_InDayNode(unsigned int nodePos);
	Note* getNote_FromDayNode(unsigned int nodePos, unsigned int noteNum);
	day_node* getDayNode(unsigned int nodePos);
	void printDayNode(unsigned int nodePos);
	void printList();

private:
};




#endif // CONSOLE_PLANNER_H