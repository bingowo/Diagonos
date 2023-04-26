
#include <stdio.h>
#include <stdlib.h>


int cmplmt(int *a)
{
    if (a<0) *a=-*a+1;
}

int pick(int a,int i)
{int b;
    a=cmplmt(&a);
    b=(a&(~(~0<<i)&(~0<<i-1)))>>(i-1);
    return b;
}

 int cmp(const void * a, const void * b)
 {
     int A,B,i;
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
    int N,T,i,j;
    long long a[10][10000];
    scanf("%d",&T);
    for(i=0;i<T;i++)
        {scanf("%d",&N);
        for(j=0;j<N;j++) 
            scanf("%d",a[i][j]);}
    i=1;

}
