#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int cmp(const void *p1,const void *p2)
{
    unsigned long long p_1 = *(unsigned long long*)p1;
    unsigned long long p_2 = *(unsigned long long*)p2;
    return (p_1<p_2)?1:-1;
}

int main()
{
    unsigned long long x,y;
    unsigned long long *p1 = (unsigned long long *)malloc (sizeof(unsigned long long)*1e7);
    unsigned long long *p2 = (unsigned long long *)malloc (sizeof(unsigned long long)*1e7);
    scanf("%lu%lu",&x,&y);
     unsigned long long *p1_ = p1;
     unsigned long long *p2_ = p2;
    for(long long i=0;i< x;i++)
    {
        scanf("%lu",p1_);
        p1_++;
    }
    qsort(p1,x,sizeof(unsigned long long),cmp);
    p2[0] = p1[0];
    for(long long i =1;i<x;i++)
    {
        p2[i] =p2[i-1]+p1[i];
    }
    unsigned long long max = p1[0]*(y-1)-(p2[y-1]-p2[0]);
    for(long long p=1;p<=x-y;p++)
    {
        max = (max >p1[p]*(y-1)-(p2[p+y-1]-p2[p]))?p1[p]*(y-1)-(p2[p+y-1]-p2[p]):max;
    }
    printf("%lu",max);

    return 0;
}
