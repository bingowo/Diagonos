#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct 
{
    long x,y,d;
}point;
long fpow(int x,int y)
{
    long rt=1;
    for(int i=1;i<=y;i++)
    {
        rt*=x;
    }
    return rt;
}
int getlen(int x)
{
    int cnt=0;
    while(x>0)
    {   
        x/=2;
        cnt++;
    }
    return cnt;
}
long move(point p1,point p2)
{
    long t,len,powx,powy,dx,dy;
    dx=abs(p1.x-p2.x);
    dy=abs(p1.y-p2.y);
    powx=fpow(2,getlen(dx));
    powy=fpow(2,getlen(dy));
    //printf("%d %d\n",powx,powy);
    long x[]={dx,dx,2*powx-dx,2*powx-dx},y[]={dy,2*powy-dy,dy,2*powy-dy};
    for(int i=0;i<=3;i++)
    {
        //printf("x=%d y=%d x&y=%d\n",x[i],y[i],x[i]&y[i]);
        len=getlen(x[i]+y[i]);
        if((x[i]&y[i])==0 && (x[i]+y[i])%2==1)
        {
            //printf("len=%d\n",len);
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
    long n,ans=0,t,d[120];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%ld%ld",&p[i].x,&p[i].y);
        p[i].d=abs(p[i].x)+abs(p[i].y);
    }
    qsort(p,n,sizeof(point),cmp);
    printf("%ld\n",abs(p[0].x-p[1].x)+abs(p[0].y-p[1].y));
    for(int i=0;i<=n-2;i++)
    {
        t=move(p[i],p[i+1]);
        if(t==-1)
        {
            ans=0;
            break;
        }
        else  ans+=t;
    }
    printf("%ld",ans);
    return 0;
}