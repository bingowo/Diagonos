#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void solveint(int n)
{
    int c=sizeof(n);
    unsigned char *p=(unsigned char*)&n;
    while(c--)
        printf("%02x ",*p++);

    printf("\n");
}
void solvedouble(double d)
{
    int c=sizeof(d);
    unsigned int *p=(unsigned int*)&d;
    while(c--)
        printf("%02x ",*p++);
    printf("\n");
}
int main()
{
    char s[100];
    while(scanf("%s",s)!=EOF)
    {
        if(strchr(s,'.')==0)solveint(atoi(s));
        else solvedouble(atof(s));
    }

    return 0;
}
