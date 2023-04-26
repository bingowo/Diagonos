#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int get(long long n)
{
    long long m=n;
    int l=0;
    while(m!=0)
    {
        l=abs(m%10);
        m/=10;
    }
    return l;
}

int cmp(const void* a,const void* b)
{
    long long x,y;
    int a1,b1;
    x=*(long long*)a;
    y=*(long long*)b;
    a1=get(x);b1=get(y);
    if(a1!=b1)return b1-a1;
    else{
        if(x>y)return 1;
        else if(x<y)return -1;
        else return 0;
    }
}



int main()
{
    int x,y;long long num;
    scanf("%d",&x);
    for(int i=0;i<x;i++)
    {
        scanf("%d",&y);
        long long n[y+1];
        for(int j=0;j<y;j++)scanf("%lld",&n[j]);
        qsort(n,y,sizeof(n[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<y;j++)printf("%lld ",n[j]);
        printf("\n");
    }
    return 0;
}