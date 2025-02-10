#include <stdio.h>

int main()
{
    char code;
    printf("Enter code: ");
    code = getchar();
    if ('A' <= code && code <= 'Z')
    {
        puts("Alright");
    }
    else
    {
        puts("No you can't");
    }
}