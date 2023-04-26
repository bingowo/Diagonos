#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    long long x,y;
} list;
int cmp(const void *a,const void *b)
{
    list* t1=(list*)a;
    list* t2=(list*)b;
    if (llabs(t1->x)+llabs(t1->y)<llabs(t2->x)+llabs(t2->y))
        return 1;
    else if (llabs(t1->x)+llabs(t1->y)==llabs(t2->x)+llabs(t2->y))
    {
        if(t1->x>t2->x)
            return 1;
        else if(t1->x<t2->x)
            return -1;
        else
        {
            if(t1->y>t2->y)
                return 1;
            else
                return -1;
        }
    }
    else
        return -1;
}
int slo(long long x,long long y)
{
    int f=-1,j=0,i=0,a[100];
    long long t=x+y;
    long long p=1;
    while(p<t)
    {
        p=p<<1;
        i++;
    }
    a[j++]=t%2;
    t=t/2;
    while(t>0)
    {
        a[j++]=t%2;
        t=t/2;
        if(a[j]==0&&a[j-1]==0)
        {
            f=1;break;
        }
    }
    if (f=1)
        return -1;
    else
        return i;
}
int main()
{
    int i,n,cnt,flag=-1;
    long long int ans,x1,y1;
    scanf("%d",&n);
    list *t=(list*)malloc(sizeof(list)*n);
    for(i=0; i<n; i++)
    {
        scanf("%lld %lld",&t[i].x,&t[i].y);
    }
    qsort(t,n,sizeof(list),cmp);
    ans=llabs(t[0].x-t[1].x)+llabs(t[0].y-t[1].y);
    i=0;
    cnt=0;
    while(i<n-1&&flag==-1)
    {
        x1=llabs(t[i].x-t[i+1].x);
        y1=llabs(t[i].y-t[i+1].y);
        if ((x1%2+y1%2)%2==0)
            flag=1;
        else
        {
            if (slo(x1,y1)!=-1)
                cnt+=slo(x1,y1);
            else
                break;
        }
    }
    printf("%lld\n",ans);
    printf("%d",cnt);
}
