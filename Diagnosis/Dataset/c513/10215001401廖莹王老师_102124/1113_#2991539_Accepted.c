#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int cnt;
    int a[150]
}point;
point p[150];
void xiangjia(point*a,point*b,point*c)
{
    int i=0,j=0,m=0,n=0;
    if(a->cnt>b->cnt)
    {
        for(i=0;i<b->cnt;i++)
        {
            m=a->a[i]+b->a[i]+n;
            c->a[i]=m%10;n=m/10;
        }
        for(i=b->cnt;i<a->cnt;i++)
        {
            m=a->a[i]+n;
            c->a[i]=m%10;n=m/10;
        }
        if(n>0){c->a[i]=n;i++;}
    }
    else
    {
        for(i=0;i<a->cnt;i++)
        {
            m=a->a[i]+b->a[i]+n;
            c->a[i]=m%10;n=m/10;
        }
        for(i=a->cnt;i<b->cnt;i++)
        {
            m=b->a[i]+n;
            c->a[i]=m%10;n=m/10;
        }
        if(n>0){c->a[i]=n;i++;}
    }
    c->cnt=i;
}
void fuzhi(point*a,point*b)
{
    b->cnt=a->cnt;
    memset(b->a,0,sizeof(int)*150);
    int i=0;
    for(i=0;i<a->cnt;i++)b->a[i]=a->a[i];
}
void jisuan(int k,int n)
{
    int i=0;
    if(n>=3)
    {
        for(i=1;i<=k;i++)
    {
        if(n-i>0)
        {
        if(p[n-i].cnt==0)jisuan(k,n-i);
        point c;c.cnt=0;memset(c.a,0,sizeof(int)*150);xiangjia(&p[n],&p[n-i],&c);fuzhi(&c,&p[n]);
        }
        else break;
    }

    }
    return;
}
int main()
{
    int k=0,n=0,i=0;
    for(i=0;i<150;i++){memset(p[i].a,0,sizeof(int)*150);p[i].cnt=0;}
    scanf("%d %d",&k,&n);
    p[0].a[0]=0;p[0].cnt=1;p[1].a[0]=0;p[1].cnt=1;p[2].a[0]=1;p[2].cnt=1;
    jisuan(k,n);
    for(i=p[n].cnt-1;i>=0;i--)printf("%d",p[n].a[i]);
    return 0;
}
