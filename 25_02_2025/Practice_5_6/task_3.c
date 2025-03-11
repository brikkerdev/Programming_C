#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 200

typedef float (*oper_t)(float, float);

typedef struct
{
    char name;
    oper_t func;
} Command;


float add(float op1, float op2) {return op1 + op2;}
float sub(float op1, float op2) {return op1 - op2;}
float mult(float op1, float op2) {return op1 * op2;}
float divd(float op1, float op2) {return op1 / op2;}

float execute(oper_t func, float op1, float op2) {
    return func(op1, op2);
}

int main() {
    Command commands[] = {
        {'+', add},
        {'-', sub},
        {'*', mult},
        {'/', divd}
    };

    char *text = malloc(MAX_LEN);
    printf("Введите выражение (op1 (+,-,*,/) op2): ");
    scanf("%200s", text);
    
    char *str = text;
    char *endptr;
    char operation;
    float op1, op2;

    op1 = strtod(str, &endptr);
    operation = *endptr++;
    op2 = strtod(str = endptr, &endptr);

    if (!op1 || !operation || !op2) {
        puts("Некорректный ввод!");
        return 1;
    }

    if (op2 == 0) {
        puts("Деление на ноль!");
        return 1;
    }

    for(int i = 0; i < 4; i++) {
        if (operation == commands[i].name) {
            printf("%.2f %c %.2f = %.2f\n", op1, operation, op2, execute(commands[i].func, op1, op2));
            break;
        }
    }

    free(text);
    return 0;
}