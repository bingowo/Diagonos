#include<stdio.h>
#include<stdlib.h>
int cmp(const void *pa,const void *pb)
{
    unsigned long long a,b;
    a=*((unsigned long long *)pa);
    b=*((unsigned long long *)pb);
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
    unsigned long long a[number];
    qsort(a,number,sizeof(unsigned long long),cmp);
    printf("%llu\n",a[number-1]-a[0]);
    return 0;
}