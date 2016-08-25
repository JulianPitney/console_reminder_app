#include <console_planner.h>
#include <fstream>


struct tm* parseTimeStructStr(string timeStructStr);
LLCalender* loadInstance(char *loadFilePath);
bool checkListUpToDate(LLCalender* input_calender);