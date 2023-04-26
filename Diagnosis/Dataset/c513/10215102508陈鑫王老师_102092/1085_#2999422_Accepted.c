#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 500
void chartoint(char s[],int a[])
{
    int len=strlen(s);
    for(int j=N-1,i=len-1;i>=0;i--,j--)
    {
        a[j]=s[i]-'0';
    }
}
void minusbig(int a[],int b[])
{
    for(int i=N-1;i>=0;i--)
    {
        if(a[i]>=b[i])a[i]-=b[i];
        else
        {
            a[i]=10+a[i]-b[i];
            a[i-1]-=1;
        }
    }
}
void print(int a[])
{
    int i;
    for(i=0;i<N&&a[i]==0;i++);
    if(i==N)printf("0\n");
    else
    {
    for(;i<N;i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
    }
}
int main()
{
    char s1[501],s2[501];
    while(scanf("%s %s",s1,s2)==2)
    {
        int ret=1;
        if(strlen(s1)<strlen(s2))
            ret=0;
        else if(strlen(s1)==strlen(s2))
            ret=strcmp(s1,s2)<0?0:1;
        int a[N]={0},b[N]={0};
        if(ret==1)
        {
        chartoint(s1,a);
        chartoint(s2,b);
        }
        else
        {
            chartoint(s1,b);
            chartoint(s2,a);
        }
        minusbig(a,b);
        if(ret==0)printf("-");
        print(a);



    }
    return 0;
}
