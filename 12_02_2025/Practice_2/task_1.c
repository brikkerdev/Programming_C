#include <stdio.h>

struct Student
{
    char Name[50];
    int Age;
    float GPA;
};


int main()
{
    int n;
    scanf("%d", &n);
    struct Student students[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %f", students[i].Name, &students[i].Age, &students[i].GPA);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Name: %s\nAge: %d\nGPA: %.1f\n\n", students[i].Name, students[i].Age, students[i].GPA);
    } 
    
}