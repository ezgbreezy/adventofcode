#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check argument count
    if (argc != 2)
    {
        printf("Usage: ./calories input.txt\n");
        return 1;
    }

    // Open file
    FILE *infile = fopen(argv[1],"r");

    // Declare buffer and string (string is for digit concatenation)
    BYTE buffer;
    char *number = malloc(sizeof(int));

    // Set string to null characters
    for (int i = 0; i < 8; i++)
    {
        number[i] = 0;
    }

    int calories = 0;
    int calories1 = 0;
    int calories2 = 0;
    int calories3 = 0;
    int digit = 0;
    int newline = 0;
    
    while (fread(&buffer, sizeof(BYTE), 1, infile) != 0)
    {
        // Check if current character is a newline 
        if (buffer == '\n')
        {
            if (newline == 0)
            {
                calories += atoi(number);
                digit = 0;
                printf("n:%s - c:%i\n", number, calories);
                for (int i = 0; i < 8; i++)
                {
                    number[i] = 0;
                }
            }
            newline++;
        }
        // Check if current character succeeding two newlines
        else if (newline > 1)
        {
            if (calories > calories1)
            {   
                calories3 = calories2;
                calories2 = calories1;
                calories1 = calories;
            }
            else if (calories > calories2)
            {
                calories3 = calories2;
                calories2 = calories;
            }
            else if (calories > calories3)
            {
                calories3 = calories;
            }
            calories = 0;
            newline = 0;
        }
         // Check if current character is a digit
        if (isdigit(buffer))
        {
            number[digit] = buffer;
            newline = 0;
            digit++;
        }
    }
    
    // Calculate final number if no trailing newline
    if (isdigit(buffer))
    {
        number[digit-1] = buffer;
        calories += atoi(number);
        printf("n:%s - c:%i\n", number, calories);
    }
    // Check if final number greater than max
    if (calories > calories1)
    {   
        calories3 = calories2;
        calories2 = calories1;
        calories1 = calories;
    }
    else if (calories > calories2)
    {
        calories3 = calories2;
        calories2 = calories;
    }
    else if (calories > calories3)
    {
        calories3 = calories;
    }

    // Print max
    printf("First: %i\nSecond: %i\nThird: %i\nTotal: %i\n", calories1, calories2, calories3, calories1 + calories2 + calories3);

    fclose(infile);
    free(number);

return 0;
}