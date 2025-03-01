#include <stdio.h>
#include <string.h>

#define MAX_LEN 200

int main() {
    char text[MAX_LEN];
    scanf("%s", text);
    char *copy = strdup(text);
    printf("Оригинал: %s\nКопия: %s\n", text, copy);
    return 0;
}