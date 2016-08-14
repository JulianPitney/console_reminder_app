#include <console_calender.h>
#include <console_planner.h>
#include <startup.h>


int main(int argc, char *argv[])
{
	LLCalender *listHandle = new LLCalender();
	startup_proc(listHandle);
	cout << listHandle->getDayNode(0) << endl;
	

}