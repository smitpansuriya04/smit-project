#include <stdio.h>

#define TRUE 1
#define FALSE 0

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *months[] = {
    " ",
    "\n\nJanuary",
    "\n\nFebruary",
    "\n\nMarch",
    "\n\nApril",
    "\n\nMay",
    "\n\nJune",
    "\n\nJuly",
    "\n\nAugust",
    "\n\nSeptember",
    "\n\nOctober",
    "\n\nNovember",
    "\n\nDecember"
};

// Function to input the year
int inputyear(void) {
    int year;
    printf("Please enter a year (example: 1999): ");
    scanf("%d", &year);
    return year;
}

// Function to determine if it's a leap year
int determineleapyear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        days_in_month[2] = 29;
        return TRUE;
    } else {
        days_in_month[2] = 28;
        return FALSE;
    }
}

// Function to determine the day code for the year
int determinedaycode(int year) {
    int d1, d2, d3, daycode;

    d1 = (year - 1) / 4;
    d2 = (year - 1) / 100;
    d3 = (year - 1) / 400;
    daycode = (year + d1 - d2 + d3) % 7;
    return daycode;
}

// Function to print the calendar
void calendar(int year, int daycode) {
    int month, day;

    for (month = 1; month <= 12; month++) {
        printf("%s", months[month]);
        printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Print initial spaces
        for (int i = 0; i < daycode; i++) {
            printf("     ");
        }

        // Print days of the month
        for (day = 1; day <= days_in_month[month]; day++) {
            printf("%5d", day);

            // Move to the next line after Saturday
            if ((day + daycode) % 7 == 0) {
                printf("\n");
            }
        }

        // Update the daycode for the next month
        daycode = (daycode + days_in_month[month]) % 7;
        printf("\n");
    }
}

// Main function
int main(void) {
    int year, daycode;

    year = inputyear();
    daycode = determinedaycode(year);
    determineleapyear(year);
    calendar(year, daycode);

    return 0;
}
