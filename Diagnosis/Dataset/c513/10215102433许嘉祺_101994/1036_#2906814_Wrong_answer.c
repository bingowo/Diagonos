#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
struct zu{
    long long x;
    long long y;
    unsigned long long xy
} a[100];
int cmp(const void*a,const void*b)
{
    unsigned long long a1=((struct zu*)a)->xy,b1=((struct zu*)b)->xy;
    if (a1>b1) return -1;
    else if (b1>a1)return 1;
    else if (((struct zu*)a)->x>((struct zu*)b)->x) return 1;
    else if (((struct zu*)a)->x<((struct zu*)b)->x) return -1;
    else if (((struct zu*)a)->y>((struct zu*)b)->y) return 1;
    else if (((struct zu*)a)->y>((struct zu*)b)->y) return 1;
}
int main()
{
    int n;
    unsigned long long b[100];
    scanf("%d",&n);
    for (int i=0; i<n; i++)
    {
        scanf("%lld %lld",&a[i].x,&a[i].y);
        a[i].xy=llabs(a[i].x)+llabs(a[i].y);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    unsigned long long t1,t2;
    t1=llabs(a[0].x-a[1].x);
    t2=llabs(a[0].y-a[1].y);
    for (int i=0; i<n-1; i++)
        if (t1>(unsigned long long )9223372036854775807&&t2>(unsigned long long)9223372036854775807&&i==0) {printf("18446744073709551616\n");b[0]=0;}
    else {b[i]=llabs(a[i].x-a[i+1].x)+llabs(a[i].y-a[i+1].y);if (i==0)printf("%llu\n",b[0]);}
    int count=0;
    for (int i=0; i<n-1; i++)
    {
        if ((b[i]==0&&a[i].x==a[i+1].x)||(b[i]%2==1))
        {
            while(b[i]>0)
            {
                if (b[i]==1)
                {
                    count++;
                    break;
                }
                else if(b[i]%4==1)
                {
                    count++;
                    b[i]=(b[i]+1)/2;
                }
                else
                {
                    count++;
                    b[i]=(b[i]-1)/2;
                }
            }

        }
        else break;
    }
    printf("%d\n",count);

    return 0;
}

