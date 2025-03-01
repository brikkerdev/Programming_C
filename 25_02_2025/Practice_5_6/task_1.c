#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 200

void upper(char* text) {
    for (int i = 0; i < strlen(text); i++) {
        text[i] = toupper(text[i]);
    }
}

void lower(char* text) {
    for (int i = 0; i < strlen(text); i++) {
        text[i] = tolower(text[i]);
    }
}

void reverse(char* text) {
    int i = 0;
    int j = strlen(text) - 1;
    while (i < j) {
        char buff = text[i];
        text[i] = text[j];
        text[j] = buff;
        i++;
        j--;
    }
}

void execute(void (*func)(char*), char* text) {
    func(text);
}

typedef void (*oper_t)(char*);

oper_t oper[] =
{
    upper, lower, reverse
};
char* oper_names[] =
{
    "upper", "lower", "reverse"
};

int main() {
    char text[MAX_LEN];
    printf("Введите текст: ");
    scanf("%s", text);
    char com[20];
    do {
        printf("Введите команду: ");
        scanf("%s", com);
        
        for(int i = 0; i < 3; i++) {
            if (!strcmp(com, oper_names[i])) {
                execute(oper[i], text);
                printf("Результат: %s\n", text);
            }
        }
    } while(strcmp(com, "exit"));
    return 0;
}