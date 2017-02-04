/*
 * Write a program "Kaleidoscope", that outputs an image
 * created from symmetrically placed asterisks '*'.
 * The image is formed inside of 2D array: 
 * 1) Fill the array's upper left quadrant with whitespaces ' '
 * 2) Randomly place asterisks '*' inside its upper left quadrant
 * 3) Copy this quadrant to other three
 * 4) Clear screen
 * 5) Output the array
 * 6) Delay
 * 7) Repeat
 */

#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE_NxN 20
#define KALEIDOSCOPE_REFRESH_TIMES 100
#define KALEIDOSCOPE_REFRESH_DELAY_SEC 1

#include<time.h>
void delay(double seconds);

int main() {
    
    // + 1 for the '\0'
    char arr[ARR_SIZE_NxN][ARR_SIZE_NxN + 1];
    srand((unsigned int)time(0));

    for (int refresh = 0; refresh < KALEIDOSCOPE_REFRESH_TIMES; refresh++) {

        // The image is formed inside of 2D array:
        for (int i = 0; i < ARR_SIZE_NxN / 2; i++) {
            for (int j = 0; j < ARR_SIZE_NxN / 2; j++) {

                if (rand() % 2)
                    // 1) Fill the array's upper left quadrant with whitespaces ' '
                    arr[i][j] = ' ';
                else
                    // 2) Randomly place asterisks '*' inside its upper left quadrant
                    //50% on putting asterisk
                    arr[i][j] = '*';

                // 3) Copy this quadrant to other three
                //upper right
                arr[i][j + ARR_SIZE_NxN / 2] = arr[i][j];
                //lower left
                arr[i + ARR_SIZE_NxN / 2][j] = arr[i][j];
                //lower right
                arr[i + ARR_SIZE_NxN / 2][j + ARR_SIZE_NxN / 2] = arr[i][j];
            }
            //close strings for otput:
            arr[i][ARR_SIZE_NxN] = '\0';
            arr[i + ARR_SIZE_NxN / 2][ARR_SIZE_NxN] = '\0';
        }
        


        // 4) Clear screen
        //stdlib.h
        system("cls");

        // 5) Output the array
        for (int i = 0; i < ARR_SIZE_NxN; i++)
            printf("%s\n", arr[i]);

        // 6) Delay
        delay(KALEIDOSCOPE_REFRESH_DELAY_SEC);
    }

    return 0;
}

void delay(double seconds)
{
    if (seconds < 0) {
        fputs("Invalid number of seconds passed to delay().\n", stderr);
        exit(EXIT_FAILURE);
    }
    unsigned int mseconds = (int)(seconds * CLOCKS_PER_SEC);
    clock_t goal = mseconds + clock();
    while (goal > clock());
}