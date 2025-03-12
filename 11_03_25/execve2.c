#include <stdio.h>
#include <unistd.h>

int main() {
    char *newprog_args[] = {
        "Tee-hee!",
        "newprog_arg1",
        "newprog_arg2",
        NULL
    };

    char *newprog_envp[] = {
        "USER=abrakadabra",
        "HOME=/home/abrakadabra",
        NULL
    };

    printf("Old PID: %d\n", getpid());
    execve("./newprog", newprog_args, newprog_envp);
    fprintf(stderr, "error");
    return 0;
}