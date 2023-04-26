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
    unsigned long long ans1=llabs(t1->x)+llabs(t1->y);
    unsigned long long ans2=llabs(t2->x)+llabs(t2->y);
    if (ans1<ans2)
        return 1;
    else if (ans1==ans2)
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
int slo(unsigned long long x,unsigned long long y)
{
    int f=-1,j=0,i=0;
    long long a[200];
    unsigned long long t=x+y;
    a[j++]=t%2;
    t=t/2;
    i++;
    while(t>0)
    {
        a[j++]=t%2;
        t=t/2;
        i++;
        if(a[j-1]==0&&a[j-2]==0)
        {
            f=1;
            break;
        }
    }
    if (f==-1)
        return i;
    else
        return -1;
}
unsigned long long abs1(unsigned long long x)
{
    if(x<0)
        return -x;
    else
        return x;
}
int main()
{
    int j,i,n,cnt,flag=-1;
    unsigned long long int ans,x1,y1;
    scanf("%d",&n);
    list *t=(list*)malloc(sizeof(list)*n);
    for(i=0; i<n; i++)
    {
        scanf("%lld %lld",&t[i].x,&t[i].y);
    }
    qsort(t,n,sizeof(list),cmp);
    i=0;
    ans=0;
    if (t[i].x>0&&t[i+1].x>0)
        ans=ans+t[i].x+t[i+1].x;
    else if(t[i].x<0&&t[i+1].x<0)
        ans=ans-t[i].x-t[i+1].x;
    else if(t[i].x>0&&t[i+1].x<0)
        ans=ans+t[i].x-t[i+1].x;
    else
        ans=ans+t[i+1].x-t[i].x;
    if (t[i].y>0&&t[i+1].y>0)
        ans=ans+t[i].y+t[i+1].y;
    else if(t[i].y<0&&t[i+1].y<0)
        ans=ans-t[i].y-t[i+1].y;
    else if(t[i].y>0&&t[i+1].y<0)
        ans=ans+t[i].y-t[i+1].y;
    else
        ans=ans+t[i+1].y-t[i].y;
    cnt=0;
    while(i<n-1&&flag==-1)
    {
        x1=0;y1=0;
        if (t[i].x>0&&t[i+1].x>0)
            x1=x1+t[i].x+t[i+1].x;
        else if(t[i].x<0&&t[i+1].x<0)
            x1=x1-t[i].x-t[i+1].x;
        else if(t[i].x>0&&t[i+1].x<0)
            x1=x1+t[i].x-t[i+1].x;
        else
            x1=x1+t[i+1].x-t[i].x;
        if (t[i].y>0&&t[i+1].y>0)
            y1=y1+t[i].y+t[i+1].y;
        else if(t[i].y<0&&t[i+1].y<0)
            y1=y1-t[i].y-t[i+1].y;
        else if(t[i].y>0&&t[i+1].y<0)
            y1=y1+t[i].y-t[i+1].y;
        else
            y1=y1+t[i+1].y-t[i].y;

        if ((x1%2+y1%2)%2==0)
            flag=1;
        else
        {
            j=slo(x1,y1);
            if (j!=-1)
                cnt+=j;
            else
                break;
        }
        i++;
    }
    free(t);
    printf("%llu\n",ans);
    printf("%d",cnt);
    return 0;
}