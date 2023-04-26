#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>

typedef struct{
    long long x;
    long long y;
    unsigned long long d;
}st;

int cmp(const void*a,const void*b)
{
    st*a1=(st*)a;
    st*b1=(st*)b;
    if(a1->d!=b1->d) return a1->d<b1->d;
    else if(a1->x!=b1->x) return a1->x>b1->x;
    else return a1->y>b1->y;
}

long long cfr(unsigned long long x,unsigned long long y)
{
    int m=0;
    while(x!=0||y!=0)
    {
        if(x%2==1&&y%2==0)
        {
            if(x==1&&y==0) x--;
            else if((x+1)/2%2!=y/2%2) x++;
            else x--;
            x/=2;
            y/=2;
            m++;
        }
        else if(x%2==0&&y%2==1)
        {
            if(x==0&&y==1) y--;
            else if((y+1)/2%2!=x/2%2) y++;
            else y--;
            x/=2;
            y/=2;
            m++;
        }
        else break;
    }
    return m;
}

int main()
{
    int n,i,j;
    scanf("%d",&n);
    st k[n];
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld",&k[i].x,&k[i].y);
        k[i].d=llabs(k[i].x)+llabs(k[i].y);
    }
    qsort(k,n,sizeof(st),cmp);
    unsigned long long d1=llabs(k[0].x-k[1].x);
    unsigned long long d2=llabs(k[0].y-k[1].y);
    if(d1+d2==0&&d1>0) printf("18446744073709551616\n");
    else printf("%llu\n",d1+d2);
    unsigned long long x1,y1,step=0;
    int m=1;
    j=0;
    if(k[j].x==k[j+1].x&&k[j].y==k[j+1].y) j++;
    for(;j<n-1&&m!=0;j++)
    {
        x1=llabs(k[j].x-k[j+1].x);
        y1=llabs(k[j].y-k[j+1].y);
        m=cfr(x1,y1);
        step+=m;
    }
    printf("%lld\n",step);
    return 0;
}
