#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int main() {
    char text[MAX_LEN];
    char *code = "launch-2025";
    scanf("%11s", text);

    for(int i = 0; i < 6; i++) {
        text[i] = tolower(text[i]);
    }

    if (!strcmp(code, text)) {
        puts("Код принят");
        return 0;
    }
    puts("Ошибка: неверный код!");
    return 1;
}