#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
    pid_t p = fork();
    if (p == -1) {
        fprintf(stderr, "Fork error\n");
        return 1;
    }
    if (p == 0) {
        printf("Мы - дочерний процесс с PID = %d\n", getpid());
    }
    else {
        printf("Мы - родительский процесс с PID = %d\n", getpid());
    }
    sleep(10);
    return 0;
}