#include <stdio.h>
#include <stdlib.h>

long long int a[51]={0};

long long int move(int n,long long int* a)
{
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    if(n==3)
        return 4;
    if(n==4)
        return 8;
    if(a[n]!=0)
        return a[n];
    else
    {
        a[n]=move(n-1,a)+move(n-2,a)+move(n-3,a)+move(n-4,a);
        return a[n];
    }
}

long long int step_num(int n)
{
    if(n==1)
    {
        a[1]=1;
        return 1;
    }
    if(n==2)
    {
        a[2]=2;
        return 2;
    }
    if(n==3)
    {
        a[3]=4;
        return 4;
    }
    if(n==4)
    {
        a[4]=8;
        return 8;
    }
    else
        return (move(n-1,a)+move(n-2,a)+move(n-3,a)+move(n-4,a));
}

int main()
{
    int T,question_num;
    scanf("%d",&T);
    for(question_num=0;question_num<T;question_num++)
    {
        int n;
        scanf("%d",&n);
        long long int way=0;
        way=step_num(n);
        printf("%lld\n",way);
    }
}