#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main()
{
    char message[MAX_LEN] = "ehgru#hello*dasiju";
    char s2[] = "#*";
    size_t start = strcspn(message, s2);
    char *message_buff = &message[start+1]; 
    size_t end = strcspn(message_buff, s2);
    message_buff[end] = '\0';
    printf("%s\n", message_buff);
    return 0;
}