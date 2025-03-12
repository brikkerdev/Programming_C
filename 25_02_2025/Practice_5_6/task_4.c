#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 20
#define MAX_TEXT_LEN 200

bool check_asc(char *word1, char *word2) {
    return 1;
}
bool check_len(char *word1, char *word2) {
    return strlen(word1) > strlen(word2);
}
bool check_num(char *word1, char *word2) {
    int l1, l2;
    for (int i = 0; i < strlen(word1); i++) {
        if (strchr("aeiouAEIOU", word1[i])) l1++;
    }
    for (int i = 0; i < strlen(word2); i++) {
        if (strchr("aeiouAEIOU", word2[i])) l2++;
    }
    return l1 > l2;
}

typedef bool (*func)(char*, char*);

func checks[3] = {
    check_asc, check_len, check_num
};

void swap(void* v1, void* v2, int size)
{
    char buffer[size];
    memcpy(buffer, v1, size);
    memcpy(v1, v2, size);
    memcpy(v2, buffer, size);
}

void qsort(void* v, int size, int left, int right, func check) {
    void *vt, *v3;
    int i, last, mid = (left + right) / 2;
    if (left >= right)
        return;
    void* vl = (char*)(v + (left * size));
    void* vr = (char*)(v + (mid * size));
    swap(vl, vr, size);
    last = left;
    for (i = left + 1; i <= right; i++) {
        vt = (char*)(v + (i * size));
        if (check((char*)vl, (char*)vt)) {
            ++last;
            v3 = (char*)(v + (last * size));
            swap(vt, v3, size);
        }
    }
    v3 = (char*)(v + (last * size)); 
    swap(vl, v3, size); 
    qsort(v, size, left, last - 1, check); 
    qsort(v, size, last + 1, right, check); 
}

int main() {
    char *array[MAX_LEN];
    char *text = malloc(MAX_TEXT_LEN);
    puts("Введите слова (через пробел): ");
    fgets(text, MAX_TEXT_LEN, stdin);
    
    int i = -1;
    char *word = strtok(text, " ");
    while (word) {
        i++;
        array[i] = word;
        word = strtok(NULL, " ");
    }
    
    int option;
    puts("Выберите вариант сортировки:\n1 - по алфавиту\n2 - по длине строки\n3 - по количеству гласных букв\nВведите число: ");
    scanf("%1d", option);
    //qsort(array, sizeof(char*), 0, i, checks[option]);
    free(text);
}