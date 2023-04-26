#include <stdio.h>
#include <stdlib.h>
int cmplmt(long long *a)
{
    if(a<0) *a=(~*a|~0<<63)+1;
}

int pick(long long a,int i)
{   int b;
    cmplmt(&a);
    b=(a&(~(~0<<i)&(~0<<i-1)))>>(i-1);
    return b;
}


 int cmp(const void * a, const void * b)
 {
     int A=0,B=0,i;
     for(i=1;i<65;i++)
        {if(pick(*(long long*)a,i)==1)A++;
        if(pick(*(long long*)b,i)==1)B++;}
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
        scanf("%lld",*(a+i)+j);}
        for(i=0;i<T;i++)
        {qsort(*(a+i),N[i],8,cmp);
        printf("case #%d:\n",i);
        for(j=0;j<N[i]-1;j++) 
        printf("%lld ",*(*(a+i)+j));
        printf("%lld",*(*(a+i)+j));
        printf("\n");}
return 0;
}
