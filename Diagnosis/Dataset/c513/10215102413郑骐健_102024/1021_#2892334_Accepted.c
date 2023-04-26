#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

char order[27];
int ser(char a)
{

    for (int i = 0;i < 26;i++)
    {
        if((a == order[i])||(a == order[i] +'a'-'A'))return i;
    }
}
int cmp(const void* p1, const void* p2)
{
    char* p_1 = *(char**)p1;
    char* p_2 = *(char**)p2;
    int z = 0;
    while (p_1[z] && p_2[z])
    {
        if (ser(p_1[z]) == ser(p_2[z]))z++;
        else if (ser(p_1[z]) > ser(p_2[z]))return 1;
        else return 0;
    }
    if (p_1[z] == 0) return 0;
    else return 1;
    return 0;
}
int main()
{
while (scanf("%s", order) != EOF)
    {
    getchar();
    char** p = (char*)malloc(sizeof(char*) * 100);
    int n = 0;
    char s[30];
    char c;
     
    do
    {
        scanf("%s%c", s, &c);
        p[n] = (char*)malloc(sizeof(char) * 21);
        strcpy(p[n], s);
        n++;
    }   
    while (c != '\n');

    qsort(p, n, sizeof(char*), cmp);

    for (int g = 0;g < n;g++)
    {
        printf("%s", p[g]);
        if (g != n - 1)printf(" ");
        else printf("\n");
    }

    for (int i = 0;i < n;i++)
    {
        free(p[i]);
    }
    free(p);

   }
    return 0;

}
