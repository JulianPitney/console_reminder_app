#include "C:\\Users\\100489210\\Desktop\\console_reminder\\console_reminder_app\\console_calender.h"


  //**********************************************************************//
 //					console_calender Class							     //
//**********************************************************************//



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
int** console_calender::Create_Month(int Month, int Year, int* MonthLengthInput)
{
	int **Calender = new int*[6];
	for (unsigned int i = 0; i < 7; i++)
	{
		Calender[i] = new int[7];
	}

    ZeroCalender(Calender);


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
            Calender[r + SecondIndex][c + FirstOfMonthIndex] = Day;
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

	return Calender;
}


int*** console_calender::Create_Year(int Year)
{
    int ***year_output = new int**[12];

    for (unsigned int i = 0; i < 12; i++)
    {
        year_output[i] = this->Create_Month(i,Year,this->MonthLengths);
    }

    return year_output;
}


void console_calender::Print_Month(int*** year_calender_input, int month)
{
	// Prints month + day names
	cout << "         " << this->MonthNames[month] << endl;
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
            if (year_calender_input[month][i][c] == 0)
            {
                cout << "   ";
            }
            else
            {
                if (year_calender_input[month][i][c] < 10)
                {
                    cout << " ";
                }

                cout << year_calender_input[month][i][c] << " ";
            }
        }

        cout << endl;
     }
}

void console_calender::Print_Year(int ***Year_Calender)
{
	for (unsigned int i = 0; i < 12; i++)
	{
		this->Print_Month(Year_Calender, i);
	}
}



console_calender::console_calender()
{
    // Initializes arrays to contain all necessary information
    // IMPORTANT. DO NOT MODIFY.
	DayNames[0] = " S";
	DayNames[1] = " M";
	DayNames[2] = "Tu";
	DayNames[3] = " W";
	DayNames[4] = "Th";
	DayNames[5] = " F";
	DayNames[6] = "Sa";

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








