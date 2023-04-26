#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int cmp(const void*a,const void*b)
{
    int *p1,*p2;int i=0;
    p1=*((int*)a);
    p2=*((int*)b);
    return *p1-*p2;
}

int main()
{
    int n;scanf("%d",&n);int sum=0;
    int*x;;x=(int*)malloc((n+1)*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&(*(x+i)));
    }
    qsort(x,n,sizeof(int),cmp);
    for(int i=0;i<n/2;i++)sum+=abs(*(x+2*i+1)-*(x+2*i));
    printf("%d",sum);
    free(x);
}