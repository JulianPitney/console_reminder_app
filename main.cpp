#include <console_calender.h>
#include <console_planner.h>
#include <startup.h>
#include <shutdown.h>

const string loadFilePath = "C:\\Users\\ZeroLife\\Documents\\Visual Studio 2015\\Projects\\console_reminder\\console_reminder\\reminder_save_file.txt"; // Set this to path of load file
const string saveFilePatrh = ""; // Set this to path where list should be saved


int main(int argc, char *argv[])
{
	LLCalender *listHandle = new LLCalender();


	listHandle->addNode(0);
	listHandle->addNode(1);
	listHandle->addNode(2);
	listHandle->addNode(3);
	listHandle->addNode(4);

	listHandle->createNote_InDayNode(0);
	listHandle->createNote_InDayNode(0);
	listHandle->createNote_InDayNode(1);
	listHandle->createNote_InDayNode(1);
	listHandle->createNote_InDayNode(3);
	listHandle->createNote_InDayNode(5);


	
	


}