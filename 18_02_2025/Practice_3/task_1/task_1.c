#include <stdio.h>
#include <stdlib.h>

// Глобальные переменные
int global_var = 42; // .data
int uninitialized_global_var; // .bss 

// Статическая переменная
static int static_var = 10; // .data

// Структура
struct Point {
    int x;
    int y;
};

struct Point global_point = {1, 2}; // .data

// Функция
void print_message() { // .text
    static int static_local_var = 5; // .data
    int local_var = 3;
    printf("Message from function!\n");
}

int main() { // .text
    int auto_var = 100;
    int *dynamic_var = malloc(4); // malloc - *UND*
    if (dynamic_var) {
        *dynamic_var = 200;
    }

    struct Point stack_point = {3, 4};

    print_message();

    free(dynamic_var); // free - *UND*

    return 0;
}