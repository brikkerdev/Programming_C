#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main()
{
    char message[MAX_LEN] = "*#*#*#*#hello*#*#**";
    char s2[] = "#*";
    size_t start = strspn(message, s2);
    char *message_buff = &message[start]; 
    size_t end = strcspn(message_buff, s2);
    message_buff[end] = '\0';
    printf("%s\n", message_buff);
    printf("Длина сообщения: %d\n", end);
    return 0;
}