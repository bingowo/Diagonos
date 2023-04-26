#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
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
    int i, n1, n2, L;
    char s1[80] = { 0 }, s2[80] = { 0 }, s[80] = { 0 };
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        n1 = 0;
        n2 = 0;
        L=0;
        scanf("%s", s1);
        scanf("%s", s2);
        scanf("%s", s);
        L=strlen(s);
        printf("case #%d:\n", i);
        rev(s2, strlen(s2));
        if(strstr(s, s1)!=NULL)
        {
            n1 = (strstr(s, s1)-&s[0]+strlen(s1));
            printf("n1=%d\n",n1);
        }
        else 
        {
            n1 = -1;
        }
        rev(s, strlen(s));
        if(strstr(s, s2)!=NULL)
        {
            n2 = (strstr(s, s2)-&s[0]+strlen(s2));
            n2 = strlen(s) - n2;
            printf("n2=%d\n",n2);
        }
        else
        {
            n2 =-1;
        }
        if((n1==-1)||(n2==-1))
        {
            printf("0\n");
        }
        else 
        {
            printf("%d\n",n2-n1);
        }
    }
    return 0;
}