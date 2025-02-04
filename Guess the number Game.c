#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int num, guess, tries = 0;
    srand(time(0));
    num = rand() % 100 + 1; // Generate random number between 1 and 100
    printf("Guess My Number Game!\n\n");

    do
    {
        printf("Enter a guess between 1 and 100: ");
        scanf("%d", &guess);
        tries++;
        if (guess > num)
        {
            printf("Too High!\n");
        }
        else if (guess < num)
        {
            printf("Too Low!\n");
        }
        else
        {
            printf("\nCorrect! You got it in %d guesses.\n", tries);
        }
    } while (guess != num);

    return 0;
}

