#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 80
double dpow(int n,int x)
{
    int i;double result=1;
    for(i=0;i<x;i++)
    result=result/n;
    return result;
}
int main()
{
    int n;char s[N];
    scanf("%d\n",&n);
    int i,j;double num=0;
    for(i=0;i<n;i++)
    {
        scanf("%s\n",s);
        for(j=2;s[j]!='\0';j++)
        num=num+(s[j]-'0')*dpow(8,-j+1);
        printf("case #%d:\n%lf\n",i,num);
    }
    return 0;
}