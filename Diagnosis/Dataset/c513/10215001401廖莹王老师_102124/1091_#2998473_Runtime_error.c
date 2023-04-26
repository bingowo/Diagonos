#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int cnt;
    int f;
    int a[5000];
}point;
point add(point a,point b)
{
    int i=0,j=0,m=0,n=0;
    point c;
    c.cnt=0;memset(c.a,0,sizeof(int)*5000);
    c.f=a.f;
    if(a.cnt>b.cnt)
    {
        for(i=0;i<b.cnt;i++)
        {
            m=a.a[i]+b.a[i]+n;
            c.a[i]=m%10;n=m/10;
        }
        for(i=b.cnt;i<a.cnt;i++)
        {
            m=a.a[i]+n;
            c.a[i]=m%10;n=m/10;
        }
        if(n>0){c.a[i]=n;i++;}
    }
    else
    {
        for(i=0;i<a.cnt;i++)
        {
            m=a.a[i]+b.a[i]+n;
            c.a[i]=m%10;n=m/10;
        }
        for(i=a.cnt;i<b.cnt;i++)
        {
            m=b.a[i]+n;
            c.a[i]=m%10;n=m/10;
        }
        if(n>0){c.a[i]=n;i++;}
    }
    c.cnt=i;
    return c;
}
point sub(point a,point b)
{
    point c={0,1,{0}};
    int i=0,j=0,m=0,n=0,f=1;
    if(a.cnt>b.cnt)f=1;
    else if(a.cnt<b.cnt)f=-1;
    else {for(i=a.cnt;i>=0;i--){if(a.a[i]>b.a[i]){f=1;break;}if(a.a[i]<b.a[i]){f=-1;break;}}}
    c.f=a.f*f;
    if(f==1)
       {
           for(i=0;i<b.cnt;i++)
        {
            m=a.a[i]-b.a[i]+n;
            if(m<0){c.a[i]=m+10;n=-1;}else{c.a[i]=m;n=0;}
        }
        for(i=b.cnt;i<a.cnt;i++)
        {
            m=a.a[i]+n;
            if(m<0){c.a[i]=m+10;n=-1;}else{c.a[i]=m;n=0;}
        }
        for(i=i-1;i>0;i--){if(c.a[i]!=0){i++;break;}}
       }

    else
        {
         for(i=0;i<a.cnt;i++)
        {
            m=b.a[i]-a.a[i]+n;
            if(m<0){c.a[i]=m+10;n=-1;}else{c.a[i]=m;n=0;}
        }
        for(i=a.cnt;i<b.cnt;i++)
        {
            m=b.a[i]+n;
            if(m<0){c.a[i]=m+10;n=-1;}else{c.a[i]=m;n=0;}
        }
        for(i=i-1;i>0;i--){if(c.a[i]!=0){i++;break;}}
    }
    if(i==0)c.cnt=1;
   else  c.cnt=i;
   return c;
}
point mul(point s,point t)
{
    point r={s.cnt+t.cnt,s.f*t.f,{0}};
    int i=0; int m=0,k=0,j=0,c=0;
    for(i=0;i<t.cnt;i++)
    {   m=0;
        for(j=0;j<s.cnt;j++)
        {
            m=s.a[j]*t.a[i]+c+r.a[i+j];r.a[i+j]=m%10;c=m/10;
        }
        k=i+j;while(c>0){m=c+r.a[k];r.a[k]=m%10;c=m/10;k++;}
    }
    for(i=s.cnt+t.cnt-1;i>0;i--){if(r.a[i]==0)r.cnt--;else break;}return r;
}
int main()
{
    int n,i,f=1,m=0,k=0;char s[500]={0};
    point sum1={0,1,{0}};point sum2={0,1,{0}};
    point a={0,1,{0}};point b={0,1,{0}};
    scanf("%s",s); scanf("%d",&n);
    if(n==0){printf("1");return;}
    for(i=0;s[i];)
    {   f=1;
        if(s[i]=='-'){f=-1;i++;}if(s[i]=='+'){f=1;i++;}
        while(isdigit(s[i])){m=m*10+s[i]-'0';i++;}m=m*f;
        if(s[i]=='i')
        {k=0;if(m==0)m=1*f;b.f=f;m=abs(m);while(m>0){b.a[k]=m%10;m=m/10;k++;}b.cnt=k;i++;}
        else {k=0;a.f=f;m=abs(m);while(m>0){a.a[k]=m%10;m=m/10;k++;}a.cnt=k;}
    }
    
    sum1=add(a,sum1);sum2=add(b,sum2);
    for(i=2;i<=n;i++)
    {
        int p;
        point c,d,e,k;
            c=mul(sum1,a);d=mul(sum2,b);
            e=mul(sum1,b);k=mul(sum2,a);
            if(c.f==d.f)sum1=sub(c,d);
            else sum1=add(c,d);
            if(e.f==k.f)sum2=add(e,k);
            else sum2=sub(e,k);
    }
    if(sum1.cnt>0 && sum2.cnt>0 )
    {if(sum1.a[sum1.cnt-1]!=0)
        {if(sum1.f<0)printf("-");
    for(i=sum1.cnt-1;i>=0;i--){printf("%d",sum1.a[i]);}}
    if(sum2.a[sum2.cnt-1]!=0)
    {
        if(sum2.f<0)printf("-");else printf("+");
        if(sum2.a[0]==1 && sum2.cnt==1);
        else{for(i=sum2.cnt-1;i>=0;i--){printf("%d",sum2.a[i]);}}
         printf("i");
    }
    }
    else if(sum1.cnt<=0  && sum2.cnt>0)
    {
       if(sum2.a[sum2.cnt-1]!=0)
    {
        if(sum2.f<0)printf("-");
        if(sum2.a[0]==1 && sum2.cnt==1);
        else{for(i=sum2.cnt-1;i>=0;i--){printf("%d",sum2.a[i]);}}
         printf("i");
    }
    else printf("0");
    }
    else if(sum1.cnt>0 && sum2.cnt<=0)
    {
        if(sum1.a[sum1.cnt-1]!=0)
        {if(sum1.f<0)printf("-");
    for(i=sum1.cnt-1;i>=0;i--){printf("%d",sum1.a[i]);}}
    }
    return 0;
}
