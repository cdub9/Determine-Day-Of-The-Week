#include <iostream>
#include <string>

using namespace std;

const int NUMBER_OF_MONTHS = 12;
const int CENTURY = 100;
const int REFERENCE_YEAR = 1583;
const int DAYS_IN_YEAR = 365;
const int DAYS_IN_WEEK = 7;
const int LEAP_DAY = 29;
const int DAYS_IN_FEB_NON_LEAP_YEAR = 28;
const int FREQUENCY_OF_LEAP_YEAR = 4;
const int FIRST_CENTURY_LEAP_YEAR = 1600;
const int CURRENT_YEAR = 2016;
const int LONG_MONTH = 31;
const int SHORT_MONTH = 30;
const int DAYS_PRIOR_TO_JANUARY = 0;
const int DAYS_PRIOR_TO_FEBRUARY = 31;
const int DAYS_PRIOR_TO_MARCH = 59;
const int DAYS_PRIOR_TO_APRIL = 90;
const int DAYS_PRIOR_TO_MAY = 120;
const int DAYS_PRIOR_TO_JUNE = 151;
const int DAYS_PRIOR_TO_JULY = 181;
const int DAYS_PRIOR_TO_AUGUST = 212;
const int DAYS_PRIOR_TO_SEPTEMBER = 243;
const int DAYS_PRIOR_TO_OCTOBER = 273;
const int DAYS_PRIOR_TO_NOVEMBER = 304;
const int DAYS_PRIOR_TO_DECEMBER = 334;

int main() {

    string repeat_program;
    do {

        string month_given;
        int day_given = 0;
        int year_given = 0;

        cout << "Please enter a calendar date without a comma (e.g. January 1 2050): ";
        cin >> month_given >> day_given >> year_given;

        //Check that the month has been entered correctly
        bool month_correct = false;
        while (month_correct == false) {
            if (month_given == "January" || month_given == "February" || month_given == "March" || month_given == "April" || month_given == "May" || month_given == "June" || month_given == "July" || month_given == "August" || month_given == "September" || month_given == "October" || month_given == "November" || month_given == "December") {
                month_correct = true;
            }
            else {
                cout << "The month must be spelled out completely with the first letter capitalized. Please re-enter the month: ";
                cin >> month_given;
            }
        }

        //Check that the day is valid for the given month
        if (month_given == "January" || month_given == "March" || month_given == "May" || month_given == "July" || month_given == "August" || month_given == "October" || month_given == "December") {
            while (day_given > LONG_MONTH || day_given < 0) {
                cout << "The day you entered is not valid for " << month_given << ". Please re-enter the day: ";
                cin >> day_given;
            }
        }
        else if (month_given == "September" || month_given == "April" || month_given == "June" || month_given == "November") {
            while (day_given > SHORT_MONTH || day_given < 0) {
                cout << "The day you entered is not valid. Keep in mind that there are only 30 days in " << month_given << ". Please re-enter the day: ";
                cin >> day_given;
            }
        }

        //Check that the year is valid (1583 or later)
        while (year_given < REFERENCE_YEAR) {
            cout << "Please re-enter the year. It must be 1583 or later: ";
            cin >> year_given;
        }

        //Check if it's a leap year
        bool leap_year = false;
        if (year_given % CENTURY == 0 && year_given % 400 == 0) {
            leap_year = true;
        }
        else if (year_given % 4 == 0) {
            leap_year = true;
        }

        //Make sure that the day is valid for February in consideration of leap years
        if (month_given == "February") {
            if (leap_year == true) {
                while (day_given > LEAP_DAY || day_given < 0) {
                    cout << "The day you entered is not valid for the given month. Please re-enter the day: ";
                    cin >> day_given;
                }
            }
            else {
                while (day_given > DAYS_IN_FEB_NON_LEAP_YEAR || day_given < 0) {
                    cout << "The day you entered is not valid. Keep in mind that " << year_given << " is not a leap year. Please re-enter the day: ";
                    cin >> day_given;
                }
            }
        }

        //Compute the number of non-century leap years between 1583 and the year given
        int leap_year_counter = 0;
        for (int i = REFERENCE_YEAR; i <= year_given; i++) {
            if (i % FREQUENCY_OF_LEAP_YEAR == 0 && i % 100 != 0) {
                leap_year_counter++;
            }
        }

        //Compute the number of century leap years between 1583 and the year given
        int century_leap_year_counter = 0;
        if (year_given > FIRST_CENTURY_LEAP_YEAR) {
            century_leap_year_counter = 1 + (year_given - FIRST_CENTURY_LEAP_YEAR) / 400;
        }
        else if (year_given == FIRST_CENTURY_LEAP_YEAR) {
            century_leap_year_counter = 1 + (year_given - FIRST_CENTURY_LEAP_YEAR) / 400;
        }

        //Compute the number of days from the reference date (January 1, 1583) to the date given by the user
        int year_to_days = (year_given - REFERENCE_YEAR) * DAYS_IN_YEAR;
        int numerical_days = year_to_days + (day_given - 1) + leap_year_counter + century_leap_year_counter;

        /*
        Convert the given month to days and add it to the numerical date
        If the given day of the year is prior to February 29th on a leap year then subtract 1 day because we're adding leap days separately based on the year provided
        */
        if (month_given == "January" && leap_year == true) {
            numerical_days--;
        }
        if (month_given == "February" && leap_year == true && day_given < LEAP_DAY) {
            numerical_days = numerical_days-- + DAYS_PRIOR_TO_FEBRUARY;
        }
        else if (month_given == "March") {
            numerical_days += DAYS_PRIOR_TO_MARCH;
        }
        else if (month_given == "April") {
            numerical_days += DAYS_PRIOR_TO_APRIL;
        }
        else if (month_given == "May") {
            numerical_days = numerical_days + DAYS_PRIOR_TO_MAY;
        }
        else if (month_given == "June") {
            numerical_days = numerical_days + DAYS_PRIOR_TO_JUNE;
        }
        else if (month_given == "July") {
            numerical_days = numerical_days + DAYS_PRIOR_TO_JULY;
        }
        else if (month_given == "August") {
            numerical_days = numerical_days + DAYS_PRIOR_TO_AUGUST;
        }
        else if (month_given == "September") {
            numerical_days = numerical_days + DAYS_PRIOR_TO_SEPTEMBER;
        }
        else if (month_given == "October") {
            numerical_days = numerical_days + DAYS_PRIOR_TO_OCTOBER;
        }
        else if (month_given == "November") {
            numerical_days = numerical_days + DAYS_PRIOR_TO_NOVEMBER;
        }
        else if (month_given == "December") {
            numerical_days = numerical_days + DAYS_PRIOR_TO_DECEMBER;
        }

        /*Compute the remainder of total days between dates (numerical_days) divided by 7 days in a week
        Determine the day of the week from the remainder based on the fact that January 1, 1583 was a Saturday
        */
        int remainder = numerical_days % DAYS_IN_WEEK;
        string day_of_week;
        if (remainder == 0) {
            day_of_week = "Saturday";
        }
        else if (remainder == 1) {
            day_of_week = "Sunday";
        }
        else if (remainder == 2) {
            day_of_week = "Monday";
        }
        else if (remainder == 3) {
            day_of_week = "Tuesday";
        }
        else if (remainder == 4) {
            day_of_week = "Wednesday";
        }
        else if (remainder == 5) {
            day_of_week = "Thursday";
        }
        else if (remainder == 6) {
            day_of_week = "Friday";
        }

        //Output the day of the week in the correct tense
        cout << endl;
        if (year_given < CURRENT_YEAR) {
            cout << month_given << " " << day_given << ", " << year_given << " was a " << day_of_week << "." << endl;
        }
        else if (year_given > CURRENT_YEAR) {
            cout << month_given << " " << day_given << ", " << year_given << " will be a " << day_of_week << "." << endl;
        }
        else if (year_given == CURRENT_YEAR) {
            if (month_given == "January" || month_given == "February" || month_given == "March" || month_given == "April" || month_given == "May" || month_given == "June" || month_given == "July" || month_given == "August" || month_given == "September") {
                cout << month_given << " " << day_given << ", " << year_given << " was a " << day_of_week << "." << endl;
            }
            else if (month_given == "November" || month_given == "December") {
                cout << month_given << " " << day_given << ", " << year_given << " will be a " << day_of_week << "." << endl;
            }
            else if (month_given == "October" && day_given < 14) {
                cout << month_given << " " << day_given << ", " << year_given << " was a " << day_of_week << "." << endl;
            }
            else if (month_given == "October" && day_given == 14) {
                cout << month_given << " " << day_given << ", " << year_given << " is a " << day_of_week << "." << endl;
            }
            else if (month_given == "October" && day_given > 14) {
                cout << month_given << " " << day_given << ", " << year_given << " will be a " << day_of_week << "." << endl;
            }
        }

        cout << endl;
        cout << "Would you like to enter another date? (Y or N): ";
        cin >> repeat_program;
    }
    while (repeat_program == "Y");
    

    system("pause");
    return 0;
}
