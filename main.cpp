#include <console_calender.h>
#include <console_planner.h>
#include <startup.h>
#include <shutdown.h>

const string loadFilePath = ""; // Set this to path of load file
const string saveFilePatrh = ""; // Set this to path where list should be saved


int main(int argc, char *argv[])
{
	LLCalender *listHandle = new LLCalender();


	checkListUpToDate(listHandle);
	listHandle->addNode(1);

	listHandle->createNote_InDayNode(0);
	listHandle->createNote_InDayNode(0);
	listHandle->createNote_InDayNode(0);

	saveInstance(listHandle, "reminder_save_file.txt");
	
	loadList("C:\\Users\\ZeroLife\\Documents\\Visual Studio 2015\\Projects\\console_reminder\\console_reminder\\reminder_save_file.txt");
	


}