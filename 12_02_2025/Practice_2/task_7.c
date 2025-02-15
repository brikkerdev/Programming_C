#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char Name[50];
    int Age;
    float GPA;
} Student;


int main()
{
    int n;
    scanf("%d", &n);
    Student* students = malloc(sizeof(Student) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %f", students[i].Name, &students[i].Age, &students[i].GPA);
    }

    for (int i = 0; i < n; i++)
    {
        Student* student = &students[i];
        printf("Name: %s\nAge: %d\nGPA: %.1f\n\n", student->Name, student->Age, student->GPA);
    } 

    free(students);
    return 0;
}
