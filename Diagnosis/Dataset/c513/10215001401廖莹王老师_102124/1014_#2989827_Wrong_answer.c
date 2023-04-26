#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int cnt;
    int a[1000];
}point;

int xiangjia(point*f,int k)
{
    int i=0,m=0,n=0;
    if(k<0)
    {
        for(i=f->cnt-1;i>=0;i--)
        {   m=f->a[i]+n+1;
            f->a[i]=m%3;
            n=m/3;
        }
        return n;
    }
    else
    {   n=k;
        for(i=0;i<=f->cnt-1;i++)
             {   m=f->a[i]+n+1;
            f->a[i]=m%3;
            n=m/3;
             }
        if(n>0){for(i=i;n>0;i++){f->a[i]=n%3;n=n/3;f->cnt++;}}
    }
    return 0;
}
void xiangjian(point*f,int k)
{
    int i=0,m=0;
    if(k>0)
    {
        for(i=f->cnt-1;i>=0;i--)
        {   m=f->a[i]-1;
            if(m==-1){f->a[i]=2;}
            else {f->a[i]=m;}
        }
        for(i=f->cnt-1;;i--){if(f->a[i]!=0)break;else f->cnt--;}
    }
    else
    { for(i=0;i<=f->cnt-1;i++)
             {  m=f->a[i]-1;
               if(m==-1){f->a[i]=2;}
               else {f->a[i]=m;}
             }
        for(i=i-1;;i--){if(f->a[i]!=0)break;else f->cnt--;}
    }
}
int main()
{
    int a=0,b=0,z=0,s=0,i=0;
    int m=3,n=0;
    point p,q;
    scanf("%d %d",&a,&b);
    p.cnt=1;q.cnt=1;
    memset(p.a,0,sizeof(p.a));memset(q.a,0,sizeof(q));
    z=a/b;s=a%b;
    for(i=0;z>0;i++){p.a[i]=z%3;p.cnt++;z=z/3;}
    if(s!=0){for(i=0;m<b;i++){q.a[i]=s/m;q.cnt++;s=s%m;m=m*3;}q.a[i]=s;q.cnt++;}
    if(q.cnt-1!=0)n=xiangjia(&q,-1);xiangjia(&p,n);
    if(q.cnt-1!=0)xiangjian(&q,1); xiangjian(&p,0);
    for(i=p.cnt-1;i>=0;i--){printf("%d",p.a[i]);}
     if(q.cnt-1!=0){printf(".");for(i=0;i<=q.cnt-1;i++){printf("%d",q.a[i]);}}
    return 0;
}
