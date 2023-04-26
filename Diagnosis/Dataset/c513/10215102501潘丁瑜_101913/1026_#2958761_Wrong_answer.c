#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void *b)
{
    long long int*c=(long long int *)a;
    long long int*d=(long long int *)b;
    if(*c>*d)
    {
        return -1;
    }
    else return 1;
}
int main()
{
    long long int n,i,j,sum=0;
    long long int num[100000]={0};
    scanf("%lld\n",&n);
    i=0;
    for(i=0;i<n;i++)
    {
    	scanf("%d",&num[i]);
	}
    qsort(num,n,sizeof(num[0]),cmp);

    for(j=0;j<n;j+=2)
    {
        sum+=num[j]-num[j+1];
    }
    printf("%lld\n",sum);
    return 0;
}