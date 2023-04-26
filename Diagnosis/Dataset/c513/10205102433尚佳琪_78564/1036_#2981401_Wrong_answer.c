#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node
{
    long long x,y;
    long long x1,y1;
    long long l;
}NODE;
int cmp(const void *a,const void *b)
{
    NODE s1=*(NODE*)a;
    NODE s2=*(NODE*)b;

        if(s2.l>s1.l)
            return 1;
        else
            return -1;


        if(s1.x>s2.x)
            return 1;
        else
            return -1;


         if(s1.y>s2.y)
            return 1;
        else
            return -1;

}
int main()
{
    int n;
    scanf("%d",&n);
    NODE a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld",&a[i].x,&a[i].y);
        a[i].x1=a[i].x>0?a[i].x:-a[i].x;
        a[i].y1=a[i].y>0?a[i].y:-a[i].y;
        a[i].l=a[i].x1+a[i].y1;
    }
    qsort(a,n,sizeof(a[0]),cmp);
    unsigned long long len=0,temp=0;
    int ans=0;
    long long temp1=a[0].y-a[1].y;
        temp1=temp1>0?temp1:-temp1;
    long long temp2=a[0].x-a[1].x;
        temp2=temp2>0?temp2:-temp2;
    len=temp1+temp2;
   // printf("%lld\n",len);
    for(int i=0;i<n-1;i++)
    {
        long long temp1=a[i].y-a[i+1].y;
            temp1=temp1>0?temp1:-temp1;
        long long temp2=a[i].x-a[i+1].x;
            temp2=temp2>0?temp2:-temp2;
        temp=temp1+temp2;
        if(temp%2==0&&temp!=0)
        {
            break;
        }
        if(temp==0)
            continue;
        for(int j=0;j<64;j++)
        {
            if(temp<=(pow(2,j+1)-1))
            {
                ans=ans+j+1;

                break;
            }
        }
    }
    printf("%llu\n%lld",len,ans);
    return 0;
}
