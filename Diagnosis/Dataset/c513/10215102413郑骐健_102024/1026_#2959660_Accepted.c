#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define  num 10007

int cmp(const void*p1,const void*p2)
{
    long long a = *(long long*)p1;
    long long b = *(long long*)p2;
    return (a>b)?-1:1;
}

int main()
{
    int t;
    scanf("%d",&t);
    long long *p1 = (long long *)malloc (sizeof(long long)*1e7);
    long long*p2 = p1;
    for(int i =0;i<t;i++)
    {
    scanf("%lld",p2);
    p2++;
    }
    qsort(p1,t,sizeof(long long),cmp);
    long long res = 0;
    for(int z=0;z < t;z+=2)
    {
        res+=(p1[z]-p1[z+1]);
    }
    printf("%lld",res);
    return 0;
}
