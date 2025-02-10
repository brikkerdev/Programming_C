#include <stdio.h>

int main()
{
    int age;
    char name[50];
    fgets(name, sizeof(name), stdin);
    scanf("%d", &age);
    printf("Name: %s Age: %d\n", name, age);
}