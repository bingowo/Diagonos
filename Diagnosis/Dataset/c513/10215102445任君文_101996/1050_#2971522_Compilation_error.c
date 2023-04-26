#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define M 500
void swap(char* x, char* y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void rev(char* s, int n)
{
    int i;
    for (i = 0; i < n / 2; i++)
    {
        swap(s + i, s + n - i - 1);
    }
}
int main()
{
    int T;
    int i, n1, n2;
    char s1[80] = { 0 }, s2[80] = { 0 }, s[80] = { 0 };
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        n1 = 0;
        n2 = 0;
        scanf("%s", s1);
        scanf("%s", s2);
        scanf("%s", s);
        printf("case #%d:\n", i);
        rev(s2, strlen(s2));
        n1 = (strstr(s, s1)-&s[0]+strlen(s1));
        rev(s, strlen(s));
        n2 = (strstr(s, s2)-&s[0]+strlen(s2));
        n2 = strlen(s) - n2;
        if((n2-n1)<0)
        {printf("0\n")};
        else
        {printf("%d\n",n2-n1)};
    }
    return 0;
}