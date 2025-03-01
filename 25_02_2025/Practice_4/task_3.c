#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char text[MAX_LEN] = "Гагарин;Титов;Армстронг;Коллинз;Олдрин";
    char *cosmonauts = strtok(text, ";");

    while (cosmonauts != NULL) {
        printf("%s\n", cosmonauts);
        cosmonauts = strtok(NULL, ";");
    }
    return 0;
}