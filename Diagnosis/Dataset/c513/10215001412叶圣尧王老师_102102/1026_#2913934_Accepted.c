#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct st 
{
    int y;
};

int cmp(const void*a,const void*b)
{
    return (*(struct st*)a).y-(*(struct st*)b).y;
}

int main()
{
    int n;scanf("%d",&n);int sum=0;
    struct st x[100000];
    for(int i=0;i<n;i++)
        scanf("%d",&x[i].y);
    qsort(x,n,sizeof(x[0]),cmp);
    for(int i=0;i<n/2;i++)sum+=x[i*2+1].y-x[i*2].y;
    printf("%d",sum);
    
}