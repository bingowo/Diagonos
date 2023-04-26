#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int cnt;
    int f;
    int a[100];
}point;
point p[1010][1010];
point add(point a,point b)
{
    int i=0,j=0,m=0,n=0;
    point c;c.cnt=0;memset(c.a,0,sizeof(int)*100);
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

point xishu(int k,int n,int m)
{
    if(k>1)
    {
        if(n>0 && m>0)
        {   point c,d;
            if(p[n-1][m].cnt==0)p[n-1][m]=xishu(k-1,n-1,m);
            if(p[n][m-1].cnt==0)p[n][m-1]=xishu(k-1,n,m-1);
            c=mul(p[0][1],p[n][m-1]);d=mul(p[1][0],p[n-1][m]);
            if(c.f==d.f)p[n][m]=add(c,d);
            else p[n][m]=sub(c,d);

        }
        else if(n==0)
        {
            if(p[n][m-1].cnt==0)p[n][m-1]=xishu(k-1,n,m-1);
            p[n][m]=mul(p[0][1],p[n][m-1]);
        }
        else if(m==0)
        {
            if(p[n-1][m].cnt==0)p[n-1][m]=xishu(k-1,n-1,m);
            p[n][m]=mul(p[1][0],p[n-1][m]);
        }

    }
    return p[n][m];
}
int main()
{
    int n,i,f=1,m=0,k=0;char s[500]={0};
    point sum1={0,1,{0}};point sum2={0,1,{0}};
    scanf("%s",s); scanf("%d",&n);
    for(i=0;i<1010;i++){for(k=0;k<1010;k++){ p[i][k].cnt=0;p[i][k].f=1;memset(p[i][k].a,0,sizeof(int)*100);}}
    p[1][0].cnt=0;p[1][0].f=1;p[0][1].cnt=0;p[0][1].f=1;
    for(i=0;s[i];)
    {   f=1;
        if(s[i]=='-'){f=-1;i++;}if(s[i]=='+'){f=1;i++;}
        while(isdigit(s[i])){m=m*10+s[i]-'0';i++;}m=m*f;
        if(s[i]=='i')
        {k=0;if(m==0)m=1*f;p[0][1].f=f;m=abs(m);while(m>0){p[0][1].a[k]=m%10;m=m/10;k++;}p[0][1].cnt=k;i++;}
        else {k=0;p[1][0].f=f;m=abs(m);while(m>0){p[1][0].a[k]=m%10;m=m/10;k++;}p[1][0].cnt=k;}
    }
    p[0][0].cnt=1;p[0][0].a[0]=1;p[0][0].f=1;
     for(i=0;i<=n;i++)
    {
        if(p[i][n-i].cnt==0)p[i][n-i]=xishu(n,i,n-i);
        if((n-i)%2==0)
        {   int c=(n-i)/2,q=0;if(c%2==0)q=1;else q=-1;
            p[i][n-i].f=p[i][n-i].f*q;
            if(sum1.f==p[i][n-i].f)sum1=add(sum1,p[i][n-i]);
            else sum1=sub(sum1,p[i][n-i]);
        }
        else
        {
            int c=(n-i)/2,q=0;if(c%2==0)q=1;else q=-1;
            p[i][n-i].f=p[i][n-i].f*q;
            if(sum2.f==p[i][n-i].f)sum2=add(sum2,p[i][n-i]);
            else sum2=sub(sum2,p[i][n-i]);
        }
    }
    if(sum1.a[sum1.cnt-1]!=0 && sum2.a[sum2.cnt-1]!=0)
    {if(sum1.f<0)printf("-");
    for(i=sum1.cnt-1;i>=0;i--){printf("%d",sum1.a[i]);}
     if(sum2.f<0)printf("-");else printf("+");
     for(i=sum2.cnt-1;i>=0;i--){printf("%d",sum2.a[i]);}printf("i");
    }
    else if(sum1.a[sum1.cnt-1]==0 && sum2.a[sum2.cnt-1]!=0)
    {
        if(sum2.f<0)printf("-");
     for(i=sum2.cnt-1;i>=0;i--){printf("%d",sum2.a[i]);}printf("i");
    }
    else if(sum1.a[sum1.cnt-1]!=0 && sum2.a[sum2.cnt-1]==0)
    {
        if(sum1.f<0)printf("-");
    for(i=sum1.cnt-1;i>=0;i--){printf("%d",sum1.a[i]);}
    }
    return 0;
}
