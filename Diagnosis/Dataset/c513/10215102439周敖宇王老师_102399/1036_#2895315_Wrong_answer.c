#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    long long x,y;
    unsigned long long d;
}point;
unsigned long long fpow(int x,int y)
{
    unsigned long long rt=1;
    for(int i=1;i<=y;i++)
    {
        rt*=x;
    }
    return rt;
}
unsigned long long fabs(long long x)
{
    unsigned long long rt;
    if (x<0)  rt=-x;
    else  rt=x;
    return rt;
}
int getlen(unsigned long long x)
{
    int cnt=0,t,flag=1;
    if(x==1) return 1;
    while(x>0)
    {   
        t=x%2;
        x/=2;
        cnt++;
        if(t==1 && x==0 && flag==1)  cnt--;
        if(t==1)  flag=0;
    }
    return cnt;
}
long long move(point p1,point p2)
{
    unsigned long long t,len,powx,powy,dx,dy;
    dx=fabs(p1.x-p2.x);
    dy=fabs(p1.y-p2.y);
    if(dx==0 && dy==0)  return 0;
    powx=fpow(2,getlen(dx));
    powy=fpow(2,getlen(dy));
    //printf("pow=%llu %llu\n",powx,powy);
    unsigned long long x[]={dx,dx,2*powx-dx,2*powx-dx},y[]={dy,2*powy-dy,dy,2*powy-dy};
    if(dx==0)  {x[2]=0;x[3]=0;}
    if(dy==0)  {y[1]=0;y[2]=0;}
    for(int i=0;i<=3;i++)
    {
        //printf("x=%llu y=%llu x&y=%llu\n",x[i],y[i],x[i]&y[i]);
        //printf("%llu\n",x[i]+y[i]);
        if((x[i]&y[i])==0 && (x[i]%2+y[i]%2)%2==1)
        {
            len=getlen(x[i]+y[i]);
            //printf("len=%llu\n",len);
            return len;
        }
    }
    return -1;
}
int cmp(const void *a,const void *b)
{
    point *pa=(point*)a,*pb=(point*)b;
    if(pa->d > pb->d) return -1;
    else  if(pa->d < pb->d)  return 1;
    else  if(pa->x > pb->x)  return 1;
    else  if(pa->x < pb->x)  return -1;
    else  if(pa->y > pb->y)  return 1;
    else  return -1;
}
int main()
{
    point p[120];
    long long n,ans=0,t;
    unsigned long long dx,dy;
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&p[i].x,&p[i].y);
        p[i].d=fabs(p[i].x)+fabs(p[i].y);
    }
    //printf("\n");
    //printf("%lld %lld\n",p[0].x,p[0].y);
    //printf("%lld %lld\n",p[1].x,p[1].y);
    //printf("%lld %lld\n",p[2].x,p[2].y);
    //printf("%lld %lld\n",p[3].x,p[3].y);

    qsort(p,n,sizeof(point),cmp);

    //printf("\n");
    //printf("%lld %lld\n",p[0].x,p[0].y);
    //printf("%lld %lld\n",p[1].x,p[1].y);
    //printf("%lld %lld\n",p[2].x,p[2].y);
    //printf("%lld %lld\n",p[3].x,p[3].y);

    dx=fabs(p[0].x-p[1].x);
    dy=fabs(p[0].y-p[1].y);
    //printf("dx,dy=%llu %llu\n",dx,dy);
    if(dx==dy && dx==fpow(2,63))
    {
        printf("18446744073709551616\n");
    }
    else
    {
        printf("%llu\n",dx+dy);
    }
    for(int i=0;i<=n-2;i++)
    {
        t=move(p[i],p[i+1]);
        if(t==-1)
        {
            break;
        }
        else  ans+=t;
    }
    printf("%lld",ans);
    return 0;
}