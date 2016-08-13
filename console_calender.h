#ifndef CONSOLE_CALENDER_H
#define CONSOLE_CALENDER_H
#include <iostream>                                     // Calender Calculator
#include <string>									   // Julian Pitney, 100489210
#include <fstream>

using namespace std;


struct day
{
    string *note0 = NULL;
    string *note1 = NULL;
    string *note2 = NULL;
    string *note3 = NULL;
    string *note4 = NULL;

    int day_number = 0;
    int month_number = 0;
    int year_number = 0;

};

class console_calender
{
public:
    console_calender();
    void SetCalender(string* DayInput, string* MonthNames, int* MonthLengths);
    bool CheckForLeap(int Year);
    void ZeroCalender(int **CalenderInput);
    day*** Create_Month(int Month, int Year, int** CalenderInput, int* MonthLengthInput);
    day**** Create_Year(int Year);
    void Print_Month (day ***Month_Calender);

    // Creates pointers and initializes them to arrays of various types and sizes to store
    // relevant information. IMPORTANT. DO NOT DELETE. WILL BREAK EVERYTHING.
    int *MonthLengths = new int[12];
    string *MonthNames = new string[12];
    string *DayNames = new string[7];

    // This calender array is constantly passed around among functions like a cheap whore. Don't edit it.
    int **Calender = new int*[6];
};

#endif // CONSOLE_CALENDER_H
