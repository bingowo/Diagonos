#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
long long int first(long long int b)
{
    while(b>=10||b<-10)
    {
        b=b/10;
    }
    return abs(b);
}
int cmp(const void *pa,const void *pb)
{
    long long int a,b;
    a=*((long long int *)pa);
    b=*((long long int *)pb);
    if(first(a)!=first(b))
    {
        return first(b)-first(a);
    }
    else
    {
        if(a>b)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}
int main()
{
    int number=0;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int a=0;
        scanf("%d",&a);
        long long int *b=(long long int*)malloc(a*sizeof(long long int));
        for(int j=0;j<a;j++)
        {
            scanf("%lld",&b[j]);
        }
        qsort(b,a,sizeof(long long int),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<a-1;k++)
        {
            printf("%lld ",b[k]);
		}
		printf("%lld\n",b[a-1]);
    }
    return 0;
}