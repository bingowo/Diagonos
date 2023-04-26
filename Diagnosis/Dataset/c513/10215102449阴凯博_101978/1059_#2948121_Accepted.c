#include <stdio.h>
#include <stdlib.h>

int gcd(int m,int n)
{
    if (n==0) return m;
    else return gcd(n,m%n);
}

int cmp1(const void*a,const void* b)
{
    int* pa=(int*)a; int* pb=(int*)b;
    return (*pa<*pb)?1:-1;
}



int main()
{
    int n,s,sum;
    scanf("%d %d",&n,&s);
    int* arr=(int*)malloc(n*sizeof(int));
    int i,j;
    for (i=0;i<n;i++)
        scanf("%d",&arr[i]);
    qsort(arr,n,sizeof(arr[0]),cmp1);
    sum=s;
    for (i=0;i<n;i++)
        sum+=arr[i];
    int avg=sum/n,remain=n,ss=s;
    for (i=0;i<n;i++)
    {
        if (arr[i]<avg)
            ss-=(avg-arr[i]);
        if (arr[i]>avg)
            remain--;
    }
    if (ss==0)
        printf("%d\n",avg);
    else if (ss>0)
    {
        if(avg)
            printf("%d+%d/%d",avg,ss/gcd(remain,ss),remain/gcd(remain,ss));
        else
            printf("%d/%d",ss/gcd(remain,ss),remain/gcd(remain,ss));

    }

    else if (ss<0)
    {
        while (ss<0)
        {
            avg--;
            ss=s;
            for (i=0;i<n;i++)
                if (arr[i]<avg)
                    ss-=(avg-arr[i]);
        }
        remain=n;
        for (i=0;i<n;i++)
            if (arr[i]>avg)
                remain--;
        if (ss==0)
            printf("%d\n",avg);
        else if (ss>0)
            printf("%d+%d/%d",avg,ss/gcd(remain,ss),remain/gcd(remain,ss));

    }
    free(arr);


    return 0;
}
