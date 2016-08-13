#ifndef CONSOLE_CALENDER_H
#define CONSOLE_CALENDER_H
#include <iostream>                                     // Calender Calculator
#include <string>									   // Julian Pitney, 100489210
#include <fstream>

using namespace std;




class console_calender
{
public:

    console_calender();
    bool CheckForLeap(int Year);
    void ZeroCalender(int **CalenderInput);
    int** Create_Month(int Month, int Year, int* MonthLengthInput);
    int*** Create_Year(int Year);
    void Print_Month (int ***Year_Calender, int month);
	void Print_Year(int ***Year_Calender);

    // Creates pointers and initializes them to arrays of various types and sizes to store
    // relevant information. IMPORTANT. DO NOT DELETE. WILL BREAK EVERYTHING.
    int *MonthLengths = new int[12];
    string *MonthNames = new string[12];
    string *DayNames = new string[7];

};

#endif // CONSOLE_CALENDER_H
