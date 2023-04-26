#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long myabs(long long a)
{
    if(a>=0)
        return a;
    else
        return -a;
}

int firstnum(long long a)
{
    long long b=myabs(a);
    while(b>10)
        b=b/10;
    int c=b;
    //printf("%d no firstnum:%d\n",a,c);
    return c;
}

long long cmpfunc (const void * a, const void * b)
{
   int c=firstnum(*(long long*)b) - firstnum(*(long long*)a) ;
   if(c!=0)
        return c;
   else
        return ( *(long long*)a - *(long long*)b );
}
int main()
{
    int quesnum;
    scanf("%d\n",&quesnum);
    for(int i=0;i<quesnum;i++)
    {
        printf("case #%d:\n",i);
        int kazu;
        scanf("%d",&kazu);
        long long num[10001]={0};
        for(int j=0;j<kazu;j++)
            scanf("%lld",&num[j]);
        qsort(num,kazu,sizeof(num[0]),cmpfunc);
        for(int j=0;j<kazu-1;j++)
            printf("%lld ",num[j]);
        printf("%lld\n",num[kazu-1]);
    }

    return 0;
}
