#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
long long int first(long long int a)
{
	long long int b=abs(a);
    while(b>=10)
    {
        b=b/10;
    }
    return b;
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
    int number;
    scanf("%d",&number);
    int a[number];
    long long int b[number][1000];
    for(int i=0;i<number;i++)
    {
        scanf("%d",&a[i]);
        for(int j=0;j<a[i];j++)
        {
            scanf("%lld",&b[i][j]);
        }
        qsort(b[i],a[i],sizeof(long long int),cmp);
    }
    for(int t=0;t<number;t++)
    {
        printf("case #%d:\n",t);
        for(int k=0;k<a[t]-1;k++)
        {
        	printf("%lld ",b[t][k]);
		}
		printf("%lld\n",b[t][a[t]-1]);
    }
    return 0;
}