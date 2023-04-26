#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
    int c,d;
    c=*(int*)a;
    d=*(int*)b;
    if(zh(c)!=zh(d))
        return zh(d)-zh(c);
    else
    {
        if(c>d) return 1;
        else return -1;
    }
}
int zh(int a)
{
        int num=0;
        int m=1;
        for(int i=0;i<64;i++)
            {
                if(a&m==1)
                    num++;
                m=m<<1;
            }
    return num;
}
void Sort(unsigned *p, unsigned n)
{
   qsort(p,n,sizeof(int),cmp);
}
int main()
{
    int T;
    long long int k[10000];
    scanf("%d",&T);
    for(int j=0;j<T;j++)
    {
        int N;
        scanf("%d",&N);
        for(int q=0;q<N;q++)
        {
            scanf("%lld",&k[q]);
        }
        Sort(k,N);
        for(int i=0;i<N-1;i++)
            printf("%lld ",k[i]);
    }
    return 0;
}