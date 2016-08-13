#include <console_calender.h>
#include <console_planner.h>



int main(int argc, char *argv[])
{
	console_calender* calender1 = new console_calender();
	int*** year_2016 = calender1->Create_Year(2016);
	calender1->Print_Year(year_2016);
}