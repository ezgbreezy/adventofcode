#include <stdio.h>

int main(void)
{
    char newline = '\n';
    char *text = "Hello\nWorld";

    int i = 0;
    while (text[i] != '\0')
    {
        if (text[i] == newline)
        {
            printf("Newline found!\n");
            break;
        }
        i++;
    }

return 0;
}