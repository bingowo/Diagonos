#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a, const void *b)
{
    long long int*p1=(long long int *)a;
    long long int*p2=(long long int *)b;
    if(*p1<*p2)
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
    int count,num;
    scanf("%d",&count);
    scanf("%d",&num);
    long long int A[10000];
    long long int*p=A;
    long long int*p1=A;
    long long int sum=0,min=0;
    for(int i=0;i<count;i++)
    {
        scanf("%lld",&A[i]);
    }
    qsort(p,count,sizeof(A[0]),cmp);
    p1=A;p=A;
    for(int j=0;j<num-1;j++)
        {
            min=min+*p1-*(p+1);
            p++;
        }
        p1=A;p=A;
    while(p1+num-1<A+count)
    {
        for(int j=0;j<num-1;j++)
        {
            sum=sum+*p1-*(p+1);
            p++;
        }
        if(min>sum)
        {
            min=sum;
        }
        p1++;
        p=p1;
        sum=0;
    }
    printf("%lld\n",min);

}
