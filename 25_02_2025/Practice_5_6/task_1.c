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

typedef void (*oper_t)(char*);

void execute(oper_t func, char* text) {
    func(text);
}

typedef struct {
    char *name;
    oper_t func;
} Command;


int main() {
    Command commands[] = {
        {"upper", upper},
        {"lower", lower},
        {"reverse", reverse},
        {NULL, NULL}
    };

    char text[MAX_LEN];
    printf("Введите текст: ");
    scanf("%200s", text);
    char com[20];
    do {
        printf("Введите команду: ");
        scanf("%20s", com);
        
        for(int i = 0; commands[i].name; i++) {
            if (!strcmp(com, commands[i].name)) {
                execute(commands[i].func, text);
                printf("Результат: %s\n", text);
                break;
            }
        }
    } while(strcmp(com, "exit"));
    return 0;
}