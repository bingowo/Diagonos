#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    long long primenum[33]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109};
    char snum[26][4]={'\0'};
    char a;
    int x1,x2=0;
    while((a=getchar())!=10)
    {
        if(a==',')
        {
            x1++;   //下标在x1结束
            x2=0;
        }
        else
        {
            snum[x1][x2]=a;
            x2++;
        }
    }
    long long num[26]={0};
    for(int i=0;i<x1+1;i++)
        num[i]=atoi(snum[i]);
    long long sum=0;
    long long weight=1;
    for(int i=x1;i>=0;i=i-1)
    {
        sum=sum+num[i]*weight;
        weight=weight*primenum[x1-i];
    }
    printf("%lld",sum);
    return 0;
}
