#include <stdio.h>
#include <stdlib.h>

typedef union {
    int int_value;
    char char_value[20];
} Grade;

int main()
{
    int n;
    scanf("%d", &n);
    Grade* grades = malloc(sizeof(Grade) * n);

    for(int i = 0; i < n; i++)
    {
        int input;
        scanf("%d", &input);

        switch (input)
        {
            case 0:
                scanf("%d", &grades[i].int_value);
                printf("Grade: %d\n", grades[i].int_value);
                break;
            
            case 1:
                scanf("%s", grades[i].char_value);
                printf("Grade: %s\n", grades[i].char_value);
                break;

            default:
                puts("Wrong Input");
                return 1;
        }

    }
    
    free(grades);
    return 0;
}