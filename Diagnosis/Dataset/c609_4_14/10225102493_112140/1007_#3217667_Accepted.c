#include <stdio.h>
#include <stdlib.h>


int ct(long long a)
{
    int i=0;
    if (a<0)
    {
        a=~a;
        while(a!=0)
        {
           if((a&1)!=0)i++;
           a>>=1;
        }
        i=64-i;
        return i;
    }
    while(a!=0)
    {
        if((a&1)!=0) i++;
        a>>=1;
    }
    return i;
}


int cmp(const void*a,const void*b)
{
    long long a1=*(long long*)a;long long a2=*(long long *)b;
    if(ct(a1)!=ct(a2)) return ct(a1)>ct(a2)?-1:1;
    /*11*/
    if(a1>a2) return 1;
    else return -1;
}



int main()
{
    int T,N;
    scanf("%d",&T);
    int j;
    for(j=0;j<T;j++)
    {
        scanf("%d",&N);
         long long a[N];
         int i;
         for(i=0;i<N;i++)
        {
            scanf("%lld ",&a[i]);
        }
        qsort(a,N,sizeof(long long),cmp);
        printf("case #%d:\n",j);
        for(i=0;i<N;i++)
        {
            printf("%lld ",a[i]);
        }
        printf("\n");
    }
    return 0;
}
