#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 200

void alloc_memory(char*);
void free_memory(char*);
void write_memory(char*);
void print_memory(char*);

typedef void (*func_t)(char*);

typedef struct {
    char *name;
    func_t func
} Command;

char *arg;
size_t mem_len = 1;

Command commands[] = {
    {"alloc", alloc_memory},
    {"free", free_memory},
    {"write", write_memory},
    {"print", print_memory},
    {NULL, NULL}
};

void alloc_memory(char* memory) {
    size_t size = (size_t)atoi(arg);
    if (size != NULL && size > 1) {
        memory = realloc(memory, size);
        mem_len = size;
        printf("Allocated %zu bytes.\n", size);
    }
    else {
        puts("Failed to allocate");
    }
}

void free_memory(char* memory) {
    if (mem_len > 0) {
        free(memory);
        mem_len = 0;
        puts("Memory free.");
    }
    else {
        puts("Already free");
    }
}

void write_memory(char* memory) {
    size_t len = strlen(arg);
    if (len-1 <= mem_len) {
        memory = strncpy(memory, arg, len);
        memory[len] = '\0';
        puts("Writed.");
    }
    else {
        puts("Not enough space");
    }

}

void print_memory(char* memory) {
    printf("Memory: %s", memory);
    puts("Printed.");
}

int main() {
    void *memory = malloc(1);
    
    char com[MAX_LEN];
    size_t index;

    do {
        printf("Enter command: ");
        fgets(com, MAX_LEN, stdin);
        index = strcspn(com, " ");
        if (strlen(com) == index) com[index-1] = '\0';
        else com[index] = '\0';
        
        printf("command: %s\n", com);
        arg = &com[index+1];

        for (int i = 0; commands[i].name != NULL; i++) {
            if (!strcmp(commands[i].name, com)) {
                commands[i].func(memory);
            }
        }

    } while (strncmp(com, "exit", 4));
    free_memory(memory);
    return 0;
}