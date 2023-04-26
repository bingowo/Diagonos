#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void solveint(int n)
{
    int c=sizeof(n);
    unsigned char *p=(unsigned char*)&n;
    while(c--)
        printf("%02x",*p++);
    printf("\n");
}

void solvedouble(double n)
{
    int c=sizeof(n);
    unsigned char*p=(unsigned char*)&n;
    while(c--)
        printf("%02x",*p++);
    printf("\n");
}

int main()
{
    int n;char arr[100];
    while(scanf("%s",arr)!=EOF)
    {
        if(strchr(arr,'.')==NULL)solveint(atoi(arr));
        else solvedouble(atof(arr));
    }
}









