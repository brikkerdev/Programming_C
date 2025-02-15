#include <stdio.h>

typedef struct
{
    int int_value;
    float float_value;
    char string[50];
} Data;

int main()
{
    Data data;
    int n;
    scanf("%d", &n);
    
    switch (n)
    {
        case 1:
            scanf("%d", &data.int_value);
            printf("Integer: %d\n", data.int_value);
            break;
        
        case 2:
            scanf("%f", &data.float_value);
            printf("Float: %.2f\n", data.float_value);
            break;

        case 3:
            scanf("%s", &data.string);
            printf("String: %s\n", data.string);
            break;

        default:
            puts("Wrong option");
            return 1;
    }
    
    return 0;
}