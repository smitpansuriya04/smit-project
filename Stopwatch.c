#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Include for sleep function

int main() {
    int hour, minute, second;
    hour = minute = second = 0;

    while (1) {
        system("cls"); // Use "cls" for Windows
        printf("%02d : %02d : %02d\n", hour, minute, second);
        fflush(stdout);
        
        second++;
        if (second == 60) {
            minute += 1;
            second = 0;
        }
        if (minute == 60) {
            hour += 1;
            minute = 0;
        }
        if (hour == 24) {
            hour = 0;
            minute = 0;
            second = 0;
        }

        sleep(1); // Wait for 1 second
    }

    return 0;
}

