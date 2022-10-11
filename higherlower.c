#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define UPPER 10
#define LOWER 1

int main() {
    srand(time(0));

    printf("Welcome to Higher or Lower!\n");
    printf("---------------------------\n");

    printf("Type 's' to start.\n");
    char c = getchar();
    while((c = getchar()) != '\n' && c != EOF);
    printf("This is to test if the dynamic update in Terraform works.");

    printf("The range is %d to %d.\n\n", LOWER, UPPER);

    int score = 0;
    int number = (rand() % (UPPER - LOWER + 1)) + LOWER;
    int winning = true;
    while(winning) {
        printf("The number is %d. Higher (h) or Lower (l)?\n", number);
        char guess;
        while (!(guess == 'h' || guess == 'l')) {
            guess = getchar();
            char c = '.';
            while((c = getchar()) != '\n' && c != EOF);
            if (!(guess == 'h' || guess == 'l'))
                printf("Guess Higher (h) or Lower (l)!\n");
        }
        int newNumber = (rand() % (UPPER - LOWER + 1)) + LOWER;
        if ((newNumber >= number && guess == 'h') || (newNumber <= number && guess == 'l')) {
            printf("Correct!\n");
            number = newNumber;
            ++score;
        }
        else {
            printf("Incorrect, the number is %d. You lost!\n", newNumber);
            winning = false;
        }
        printf("Your score is %d.\n\n", score);
        guess = '.';
    }

    return 0;
}
