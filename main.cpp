#include <console_calender.h>
#include <console_planner.h>
#include <startup.h>
#include <shutdown.h>

int main(int argc, char *argv[])
{
	LLCalender *listHandle = new LLCalender();
	startup_proc(listHandle);
	listHandle->addNode(1);
	listHandle->addNode(1);
	listHandle->addNode(1);
	listHandle->addNode(1);
	listHandle->addNode(1);
	listHandle->addNode(1);


	listHandle->printList();
	saveInstance(listHandle);
	
	listHandle->createNote_InDayNode(-11);
	listHandle->createNote_InDayNode(0);
	listHandle->createNote_InDayNode(0);
	listHandle->createNote_InDayNode(2);
	listHandle->createNote_InDayNode(2);
	listHandle->createNote_InDayNode(3);
	listHandle->createNote_InDayNode(5);
	listHandle->createNote_InDayNode(5);
	listHandle->createNote_InDayNode(5);
	listHandle->createNote_InDayNode(5);
	listHandle->createNote_InDayNode(8);

	
	saveInstance(listHandle);

}