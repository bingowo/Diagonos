#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
long long int first(long long int a)
{
	long long int b=a;
    while(b>=10)
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
    if(first(a)>first(b))
    {
        return -1;
    }
    else if(first(a)<first(b))
    {
    	return 1;
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
    long long int b[number][10000];
    for(int i=0;i<number;i++)
    {
        scanf("%d",&a[i]);
        long long int link[a[i]];
        for(int j=0;j<a[i];j++)
        {
            scanf("%lld",&link[j]);
        }
        qsort(link,a[i],sizeof(long long int),cmp);
        for(int m=0;m<a[i];m++)
        {
            b[i][m]=link[m];
        }
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