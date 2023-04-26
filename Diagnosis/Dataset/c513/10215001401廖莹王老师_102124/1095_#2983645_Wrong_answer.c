#include <stdio.h>
#include <stdlib.h>
#define  N 100000
typedef struct
{
    int cnt;
    int a[N];
    int f;
}point;
void xiangjian(point*a,point*b,point*c)
{
    int i=0,j=0,m=0,n=0,f=1;
    if(a->cnt>b->cnt)f=1;
    else if(a->cnt<b->cnt)f=-1;
    else {for(i=a->cnt;i>=0;i--){if(a->a[i]>b->a[i]){f=1;break;}if(a->a[i]<b->a[i]){f=-1;break;}}}
    c->f=a->f*f;
    if(f==1)
       {
           for(i=0;i<b->cnt;i++)
        {
            m=a->a[i]-b->a[i]+n;
            if(m<0){c->a[i]=m+10;n=-1;}else{c->a[i]=m;n=0;}
        }
        for(i=b->cnt;i<a->cnt;i++)
        {
            m=a->a[i]+n;
            if(m<0){c->a[i]=m+10;n=-1;}else{c->a[i]=m;n=0;}
        }
        for(i=i-1;i>0;i--){if(c->a[i]!=0){i++;break;}}
       }

    else
        {
         for(i=0;i<a->cnt;i++)
        {
            m=b->a[i]-a->a[i]+n;
            if(m<0){c->a[i]=m+10;n=-1;}else{c->a[i]=m;n=0;}
        }
        for(i=a->cnt;i<b->cnt;i++)
        {
            m=b->a[i]+n;
            if(m<0){c->a[i]=m+10;n=-1;}else{c->a[i]=m;n=0;}
        }
        for(i=i-1;i>0;i--){if(c->a[i]!=0){i++;break;}}
    }
    if(i==0)c->cnt=1;
   else  c->cnt=i;
}
void xiangjia(point*a,point*b,point*c)
{
    int i=0,j=0,m=0,n=0;
    if(a->f==1)c->f=1;else c->f=-1;
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
    b->cnt=a->cnt;b->f=a->f;
    memset(b->a,0,sizeof(int)*N);
    int i=0;
    for(i=0;i<a->cnt;i++)b->a[i]=a->a[i];
}
int main()
{
   char s[100000]={0};
   scanf("%s",s);
   long long i=0,k=0,d,j,m,h=0;int t[100000];
   point qr,qi,a,b;
   memset(qr.a,0,sizeof(int)*N);memset(qi.a,0,sizeof(int)*N);memset(a.a,0,sizeof(int)*N);memset(b.a,0,sizeof(int)*N);
   for(i=2;s[i];i++)
   {
       if(s[i]>='A')d=s[i]-'A'+10;
       else d=s[i]-'0';
       j=8;

       for(k=0;k<4;k++)
       {
           if(d&j)t[(i-2)*4+k]=1;
           else t[(i-2)*4+k]=0;
           j=j>>1;
       }


   }
a.cnt=1;b.cnt=1;qr.cnt=1;qi.cnt=1;a.f=1;b.f=1;qr.f=1;qi.f=1;
for(m=0;m<(i-2)*k;m++)
{
    point x,g;memset(x.a,0,sizeof(x.a));memset(g.a,0,sizeof(g.a));
    x.cnt=1;x.a[0]=t[m];x.f=1;
    if(qr.f==qi.f)xiangjia(&qr,&qi,&g);else xiangjian(&qr,&qi,&g);
    if(qr.f==qi.f)xiangjian(&qr,&qi,&b);else xiangjia(&qr,&qi,&b);
    if(g.f==x.f)xiangjian(&x,&g,&a);else xiangjia(&x,&g,&a);
    fuzhi(&a,&qr);fuzhi(&b,&qi);

}
if(a.a[a.cnt-1]==0 &&b.a[b.cnt]!=0 ){if(b.f==-1)printf("-"); if(b.cnt==1 && b.a[0]==1)printf("i");else{for(h=b.cnt-1;h>=0;h--)printf("%d",b.a[h]);printf("i");}}
else
{
    if(b.a[b.cnt-1]==0 ){if(a.f==-1)printf("-");for(h=a.cnt-1;h>=0;h--)printf("%d",a.a[h]);}
    else
    {
        if(a.f==-1)printf("-");for(h=a.cnt-1;h>=0;h--)printf("%d",a.a[h]);
        if(b.f==-1)printf("-");else printf("+");
        {
            if(b.cnt==1 && b.a[0]==1)printf("i");
            else{for(h=b.cnt-1;h>=0;h--)printf("%d",b.a[h]);printf("i");}
        }

    }
}
    return 0;
}

