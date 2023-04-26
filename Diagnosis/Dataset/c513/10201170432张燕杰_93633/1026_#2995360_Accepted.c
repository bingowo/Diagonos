#include<stdio.h>
#include<malloc.h>
#include<math.h>

int cmp(const void*a,const void*b)
{
    int *p1 = (int*)a;
    int *p2 = (int*)b;
    return *p2-*p1;
}
int main()
{
    int n;
    scanf("%d",&n);
    int*num  = (int*)malloc(sizeof(int)*n);
    for(int i = 0;i<n;i++)
    {
        scanf("%d",num+i);
    }
    qsort(num,n,sizeof(int),cmp);
    int sum = 0;
    for(int i = 0;i<n;i = i+2)
    {
        sum = abs(*(num+i)-*(num+i+1))+sum;
    }
    printf("%d",sum);
    return 0;
}
