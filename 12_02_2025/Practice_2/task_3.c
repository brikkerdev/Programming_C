#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
    char name[50];
    Date date;
    char description[200];
} Event;

int main()
{
    int n;
    scanf("%d", &n);
    Event* events = malloc(sizeof(Event) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d %s", events[i].name, &events[i].date.day, &events[i].date.month, &events[i].date.year, events[i].description);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Event: %s\nDate: %d/%d/%d\nDescription: %s\n\n", events[i].name, events[i].date.day, events[i].date.month, events[i].date.year, events[i].description);
    } 

    free(events);
    return 0;
}