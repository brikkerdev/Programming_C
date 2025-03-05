#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 200

void delete(char* text) {
    char *src, *dst;
    size_t d = 0;
    for (src = dst = text; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != ' ') dst++;
        else d++;
    }
    *dst = '\0';
}

void change(char* text) {
    for (int i = 0; i < strlen(text); i++) {
        if (strchr("aeiouAEIOU", text[i])) {
            text[i] = '*';
        }
    }
}

void invert(char* text) {
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] >= 65 && text[i] <= 90) {
            text[i] += 32;
        }
        else if (text[i] >= 97 && text[i] <= 122) {
            text[i] -= 32;
        }
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
        {"delete", delete},
        {"change", change},
        {"invert", invert},
        {NULL, NULL}
    };

    char *text = malloc(MAX_LEN);
    printf("Введите текст: ");
    fgets(text, MAX_LEN, stdin);
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

    free(text);
    return 0;
}