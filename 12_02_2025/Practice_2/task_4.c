#include <stdio.h>

struct Employee
{
    char name[50];
    char position[50];
    float salary;
};


int main()
{
    int n;
    scanf("%d", &n);
    struct Employee employees[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %f", employees[i].name, employees[i].position, &employees[i].salary);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Name: %s\nPosition: %s\nSalary: %.2f\n\n", employees[i].name, employees[i].position, employees[i].salary);
    } 
    
}