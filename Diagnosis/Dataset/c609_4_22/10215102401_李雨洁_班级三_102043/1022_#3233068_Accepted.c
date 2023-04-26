#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void* a, const void* b)
{
    char* p1, * p2, * d1, * d2;
    
    p1 = *((char**)a);
    p2 = *((char**)b);
    int i = 0;
    while (*(p1 + i) != '@')  i++; //查找@的位置
    d1 = p1 + i + 1;
    i = 0;
    while (*(p2 + i) != '@')  i++;
    d2 = p2 + i + 1;
    if (strcmp(d1, d2) == 0)
        return strcmp(p2, p1);
    else
        return strcmp(d1, d2);
}

int main()
{
    int n;
    scanf("%d\n", &n);
    char** email;
    email = (char**)malloc(n * sizeof(char*));
    char s[1000001], * p;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        int len = strlen(s);
        p = (char*)malloc(len + 1);
        strcpy(p, s);
        *(email + i) = p;
    }
    qsort(email, n, sizeof(char*), cmp);
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", email[i]);
    }
    for (int i = 0; i < n; i++)//内存的释放
    {
        p = email[i];
        free(p);
    }
    free(email);
    return 0;
}