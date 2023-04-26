#include <stdio.h>
#include <stdlib.h>

#define N 10000

int abs(int n)
{
    if(n<0)n=-n;
    return n;
}

int cmp(const void* a,const void* b)
{
    if ( abs(*(int*)a) /10 > abs(*(int*)b) /10)return -1;
    else if ( abs(*(int*)a) /10 < abs(*(int*)b) /10)return 1;
    else
    {
        if (*(int*)a <= *(int*)b )return -1;
        else return 1;
    }

}


int main()
{
    int num[N];
    for (int i=0;i<N;i++)num[i]=0;
    int n=0;
    while (~scanf("%d",&num[n++]));
    n--;

    qsort(num,n,sizeof(int),cmp);

    for (int i=0;i<n;i++)
   {
       printf("%d",num[i]);
       if (i==n-1)printf("\n");
       else printf(" ");
    }

    return 0;
}
