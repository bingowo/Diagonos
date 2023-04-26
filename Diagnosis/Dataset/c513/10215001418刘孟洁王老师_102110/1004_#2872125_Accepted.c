#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 1000
void solveint(int c)
{
    int n=sizeof(c);
    unsigned char *p=(unsigned char*)&c;
    for(n=sizeof(c)-1;n>=0;n--)
    printf("%02x%c",*p++,n==0?'\n':' ');

}
void solvedouble(double c)
{
    int n=sizeof(c);
    unsigned char *p=(unsigned char*)&c;
    for(n=sizeof(c)-1;n>=0;n--)
    printf("%02x%c",*p++,n==0?'\n':' ');

}

int main()
{
    char s[N];
    while(scanf("%s",s)!=EOF)
    {
        if(strchr(s,'.')==0)
            solveint(atoi(s));
        else solvedouble(atof(s));
    }
    return 0;
}
