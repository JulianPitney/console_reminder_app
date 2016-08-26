#include <C:\\Users\\100489210\\Desktop\\console_reminder\\console_reminder_app\\console_planner.h>
#include <C:\\Users\\100489210\\Desktop\\console_reminder\\console_reminder_app\\shutdown.h>
#include <fstream>


struct tm* parseTimeStructStr(string timeStructStr);
LLCalender* loadInstance(char *loadFilePath);
bool checkListUpToDate(LLCalender* input_calender);