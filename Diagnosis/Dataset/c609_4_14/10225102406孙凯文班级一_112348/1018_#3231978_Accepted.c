#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void* b)
{
    int A=*(int *)a;
    int B=*(int *)b;
    return B-A;
}
int main()
{
    int n,x[100000];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        x[i]=a;
    }
    qsort(x,n,sizeof(x[0]),cmp);
    int sum=0;
    for(int i=0;i<n;i=i+2)
    {
        sum=sum+x[i]-x[i+1];
    }
    printf("%d",sum);
    return 0;
}

