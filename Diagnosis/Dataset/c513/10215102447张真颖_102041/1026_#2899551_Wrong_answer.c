#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    int pa=*(int*)a,pb=*(int*)b;
    if(pa>pb) return 1;
    else if(pa<pb) return -1;
    return 0;
}

int main()
{
    int n=0;
    long int sum=0,*num;
    scanf("%d",&n);
    num=(long int*)malloc(n*sizeof(long int));
    for(int i=0;i<n;i++)
         scanf("%ld",num+i);
    qsort(num,n,sizeof(num[0]),cmp);
    for(int i=0;i<=n/2;i+=2)
        sum=sum-*(num+i)+*(num+i+1);
    printf("%ld",sum);
    free(num);
    return 0;
}
