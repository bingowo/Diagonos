#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
void solveint(int a)
{
    int A=a;
    unsigned char*p=&A;
    for(int i=0;i<sizeof(int);i++)
    {
        printf("%02x ",*p);
        p++;
    }
    printf("\n");
}
void solvedle(double a)
{
    double A=a;
    unsigned char*p=&A;
    for(int i=0;i<sizeof(double);i++)
    {
        printf("%02x ",*p);
        p++;
    }
}
int main()
{
    char s[31];
    while(scanf("%s",s)!=EOF)
    {
        if(!strchr(s,'.'))
            solveint(atoi(s));
        else
            solvedle(atof(s));
    }
	return 0;
}
