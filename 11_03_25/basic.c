#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

extern char ** environ;

int main() {
    char * args[] = {
        "./superprog",
        NULL
    };
    pid_t result = fork();

    if (result == -1) {
        fprintf(stderr, "fork error");
        return 1;
    }

    if (result == 0) {
        execl("./superprog", "superprog", NULL);
        fprintf(stderr, "execl error");
        return 1;
    }
    else {
        printf("Я старый процесс basic.c\n");
    }
    return 0;
}