#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void solveint(int d)
{
    int sz=sizeof(d);
    char *p=(char*)&d;
    while(sz--!=0)
    {
        printf("%02x",*p);
        *p++;
    }
    printf("\n");
}
void solvedouble(double c)
{
    int sz=sizeof(c);
    char *p=(char*)&c;
    while(sz--!=0)
    {
        printf("%02x",*p);
        *p++;
    }
    printf("\n");
}




int main()
{
    char s[64];
    while (scanf("%s", s) != EOF)
        if (strchr(s, '.') == 0)
            solveint(atoi(s));
        else
            solvedouble(atof(s));
    return 0;
}