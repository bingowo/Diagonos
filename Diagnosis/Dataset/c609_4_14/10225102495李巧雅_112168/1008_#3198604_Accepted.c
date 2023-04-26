#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void solveint(int n)
{
    int c=sizeof(n);
    unsigned char* p=(unsigned char*)&n;
    while(c)
    {
        printf("%02x ",*p++);
        c--;
    }
    printf("\n");
}
void solvedouble(double n)
{
    int c=sizeof(n);
    unsigned char* p=(unsigned char*)&n;
    while(c)
    {
        printf("%02x ",*p++);
        c--;
    }
    printf("\n");
}
int main()
{
    char s[50];
    while(scanf("%s",s)!=EOF)
    {
        if(strchr(s,'.')==NULL)
            solveint(atoi(s));
        else
            solvedouble(atof(s));
    }
    return 0;
}
