#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[50];
    int credits;
    char professor[50];
} Course;


int main()
{
    int n;
    scanf("%d", &n);
    Course* courses = malloc(sizeof(Course) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %s", courses[i].name, &courses[i].credits, courses[i].professor);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Course: %s\nCredits: %d\nProfessor: %s\n\n", courses[i].name, courses[i].credits, courses[i].professor);
    } 

    free(courses);
    return 0;
}
