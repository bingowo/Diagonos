#include<stdio.h>
#include<stdlib.h>
int cmp(const void *pa,const void *pb)
{
    long long a,b;
    a=*((long long *)pa);
    b=*((long long *)pb);
    if(a>b)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int number;
    scanf("%d",&number);
    long long a[number];
    for(int i=0;i<number;i++)
    {
    	scanf("%ll",&a[i]);
	}
    qsort(a,number,sizeof(long long),cmp);
    printf("%llu\n",a[number-1]-a[0]);
    return 0;
}