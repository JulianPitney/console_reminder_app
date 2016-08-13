#include "console_calender.h"


// Function that fills the MonthName,MonthLength and DayName arrays with their appropriate values for later use.
void console_calender::SetCalender(string* DayInput, string* MonthNames, int* MonthLengths)
{
    DayInput[0] = " S";
    DayInput[1] = " M";
    DayInput[2] = "Tu";
    DayInput[3] = " W";
    DayInput[4] = "Th";
    DayInput[5] = " F";
    DayInput[6] = "Sa";

    MonthNames[0] = "January"; MonthLengths[0] = 31;
    MonthNames[1] = "February"; MonthLengths[1] = 28;
    MonthNames[2] = "March"; MonthLengths[2] = 31;
    MonthNames[3] = "April"; MonthLengths[3] = 30;
    MonthNames[4] = "May"; MonthLengths[4] = 31;
    MonthNames[5] = "June"; MonthLengths[5] = 30;
    MonthNames[6] = "July"; MonthLengths[6] = 31;
    MonthNames[7] = "August"; MonthLengths[7] = 31;
    MonthNames[8] = "September"; MonthLengths[8] = 30;
    MonthNames[9] = "October"; MonthLengths[9] = 31;
    MonthNames[10] = "November"; MonthLengths[10] = 30;
    MonthNames[11] = "December"; MonthLengths[11] = 31;



}

// Function that returns true if the input is a leap year.
bool console_calender::CheckForLeap(int Year)
{
    bool LeapYear = false;

    if (Year % 4 == 0)
    {
        LeapYear = true;
    }

    if (Year % 100 == 0)
    {
        LeapYear = false;
    }

    if (Year % 400 == 0)
    {
        LeapYear = true;
    }

    return LeapYear;
}

// Sets all values in calender to 0 to overwrite junk values that might be in the array
// in slots where no day exists for a particular month, to avoid outputting them.
void console_calender::ZeroCalender(int **CalenderInput)
{
    for (unsigned int i = 0; i < 6; i++)
    {
        for (unsigned int c = 0; c < 7; c++)
        {
            CalenderInput[i][c] = 0;
        }
    }
}


// Function for printing month. Takes in all the necessary pointers to arrays storing week and month name and length information.
// Also takes user input to specify which month/year it should output.
day*** console_calender::Create_Month(int Month, int Year, int** CalenderInput, int* MonthLengthInput)
{
    day*** month_output = new day**[6];

    for (unsigned int i = 0; i < 7; i++)
    {
        month_output[i] = new day*[7];

       for (unsigned int c = 0; c < 8; c++)
       {
           month_output[i][c] = new day;
       }
    }



    ZeroCalender(CalenderInput);


    // This block determines all the day length, first day and total day information.
    // It then translates that information into the appropriate index information for
    // initializing the calender and printing it.
    int JanFirst = (((1) + (5) * ((Year - 1) % (4))) + ((4) * ((Year - 1) % (100))) + ((6) * ((Year - 1) % (400)))) % (7) + (1);
    int TotalDays = 0;
    int Day = 1;

    if (CheckForLeap(Year))
    {
        MonthLengthInput[1] = 29;
    }
    else if (!CheckForLeap(Year))
    {
        MonthLengthInput[1] = 28;
    }



    for (int i = 0; i < Month; i++)
    {
        TotalDays += MonthLengthInput[i];
    }

    int FirstOfMonthIndex = JanFirst + (TotalDays % 7) - (1);
    int SecondIndex = 0;

    if (FirstOfMonthIndex >= 7)
    {
        FirstOfMonthIndex = FirstOfMonthIndex - 7;
        SecondIndex = 1;
    }


    // This block intializes the calender array using the information given
    // by the last block of code. I.e starts on correct day of given month and
    // ends on correct day.
    for (unsigned int r = 0; r < 6; r++)
    {
        for (unsigned int c = 0; c < 7; c++)
        {
            CalenderInput[r + SecondIndex][c + FirstOfMonthIndex] = Day;
            Day++;

            if (FirstOfMonthIndex + c >= 6)
            {
                FirstOfMonthIndex = 0;
                break;
            }


            if (Day > MonthLengthInput[Month])
            {
                break;
            }
        }

        if (Day > MonthLengthInput[Month])
        {
            break;
        }

        if (SecondIndex + r >= 5)
        {
            break;
        }
    }

    for (unsigned int i = 0; i < 6; i++)
    {
        for (unsigned int c = 0; c < 7; c++)
        {
            month_output[i][c]->day_number = CalenderInput[i][c];
            month_output[i][c]->month_number = Month;
            month_output[i][c]->year_number = Year;
        }
    }



    return month_output;

}


day**** console_calender::Create_Year(int Year)
{
    day ****year_output = new day***[12];

    for (unsigned int i = 0; i < 12; i++)
    {
        year_output[i] = this->Create_Month(i,Year,this->Calender,this->MonthLengths);
    }

    return year_output;
}


void console_calender::Print_Month(day*** month_calender_input)
{
    // Prints month name
    cout << " " << this->MonthNames[month_calender_input[0][0]->month_number] << "  " << month_calender_input[0][0]->year_number << endl;
    cout << endl;


    // Prints day names (these never change)
    for (unsigned int i = 0; i < 7; i++)
    {
        cout << this->DayNames[i] << " ";
    }
        cout << endl;


    // prints calender array with proper formating
    for (unsigned int i = 0; i < 6; i++)
    {
        for (unsigned int c = 0; c < 7; c++)
        {
            if (month_calender_input[i][c]->day_number == 0)
            {
                cout << "   ";
            }
            else
            {
                if (month_calender_input[i][c]->day_number < 10)
                {
                    cout << " ";
                }

                cout << month_calender_input[i][c]->day_number << " ";
            }
        }

        cout << endl;
     }
}



console_calender::console_calender()
{


    for (unsigned int i = 0; i < 7; i++)
    {
        Calender[i] = new int[7];
    }

    // Initializes arrays to contain all necessary information using SetCalender function.
    // ALSO IMPORTANT. DO NOT DELETE.
    SetCalender(DayNames, MonthNames, MonthLengths);
}








