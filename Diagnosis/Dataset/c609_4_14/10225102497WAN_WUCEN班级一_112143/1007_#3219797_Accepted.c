#include <stdio.h>
#include <stdlib.h>
void cmplmt(long long *a)
{
    if(*a<0) *a=(~*a|~0<<63)+1;
}

int pick(long long a,int i)
{   int b;long long c=0;
    b=(a&(~(~c<<i)&(~c<<i-1)))>>(i-1);
    return b;
}


 int cmp(const void * a, const void * b)
 {
     int A=0,B=0,i;
     for(i=1;i<65;i++)
        {if(pick(*(long long*)a,i)==1)A++;
        if(pick(*(long long*)b,i)==1)B++;}
        if(*(long long*)a<0)A++;
        if(*(long long*)b<0)B++;
     if(A>B)return -1;
     else if(A<B)return 1;
     else if(*(long long*)a>=*(long long*)b)return 1;
     else return -1;

 }

int main()
{
    int T,N[10],i,j;
    long long **a;
    scanf("%d",&T);
    a=(long long **)malloc(T*sizeof(long long **));
    for(i=0;i<T;i++)
    {scanf("%d",&N[i]);
        *(a+i)=(long long *)malloc(N[i]*sizeof(long long *));
        for(j=0;j<N[i];j++)
        scanf("%lld",*(a+i)+j);
        qsort(*(a+i),N[i],8,cmp);}
        for(i=0;i<T;i++)
        {printf("case #%d:\n",i);
        for(j=0;j<N[i];j++)
        printf("%lld ",*(*(a+i)+j));
       printf("\n");}
return 0;
}
