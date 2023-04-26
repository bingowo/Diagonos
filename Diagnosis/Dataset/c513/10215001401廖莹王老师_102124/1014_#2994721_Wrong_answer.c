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
      if(k<0)n=0;
   else  n=k;
        for(i=0;i<=f->cnt-1;i++)
             {   m=f->a[i]+n+1;
            f->a[i]=m%3;
            n=m/3;
             }
        if(k>=0){if(n>0){for(i=i;n>0;i++){f->a[i]=n%3;n=n/3;f->cnt++;}}}
    return n;
}
void xiangjian(point*f,int k)
{
    int i=0,m=0;

     for(i=0;i<=k-1;i++)
             {  m=f->a[i]-1;
               if(m==-1){f->a[i]=2;}
               else {f->a[i]=m;}
             }


}
int main()
{
    int a=0,b=0,z=0,s=0,i=0,k=0;
    int m=0,n=0;
    point p,q;
    scanf("%d %d",&a,&b);
    p.cnt=0;q.cnt=0;m=b;
    memset(p.a,0,sizeof(p.a));memset(q.a,0,sizeof(q));
    z=a/b;s=a%b;
    if(z==0){p.a[0]=0;p.cnt=1;}
    for(i=0;z>0;i++){p.a[i]=z%3;p.cnt++;z=z/3;}k=p.cnt;
    if(s!=0){for(i=0;m>=3;i++){q.a[i]=s%3;q.cnt++;s=s/3;m=m/3;}}
    if(q.cnt!=0)n=xiangjia(&q,-1);xiangjia(&p,n);
    if(q.cnt!=0)xiangjian(&q,q.cnt); xiangjian(&p,k);
     for(i=p.cnt-1;i>0;i--){if(p.a[i]!=0)break;else p.cnt--;}
    for(i=p.cnt-1;i>=0;i--){printf("%d",p.a[i]);}
     if(q.cnt!=0){printf(".");for(i=q.cnt-1;i>=0;i--){printf("%d",q.a[i]);}}
    return 0;
}
