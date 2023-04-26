#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int flag;
    int cnt;
    int a[150];
}point;
point p[50];
int re[150];
void fuzhi(char s[150],int k)
{
    int i=strlen(s);
    p[k].cnt=i;p[k].flag=1;
    for(i=i-1;i>=0;i--)
    {
        if(s[i]=='-'){p[k].flag=-1;p[k].cnt--;break;}
        p[k].a[p[k].cnt-i-1]=s[i]-'0';
    }
}
void xiangjia(point a,point b)
{
    int i=0,j=0,m=0,n=0;
    if(a.cnt>b.cnt)
    {
        for(i=0;i<b.cnt;i++)
        {
            m=a.a[i]+b.a[i]+n;
            re[i]=m%10;n=m/10;
        }
        for(i=b.cnt;i<a.cnt;i++)
        {
            m=a.a[i]+n;
            re[i]=m%10;n=m/10;
        }
        if(n>0){re[i]=n;i++;}
    }
    else
    {
        for(i=0;i<a.cnt;i++)
        {
            m=a.a[i]+b.a[i]+n;
            re[i]=m%10;n=m/10;
        }
        for(i=a.cnt;i<b.cnt;i++)
        {
            m=b.a[i]+n;
            re[i]=m%10;n=m/10;
        }
        if(n>0){re[i]=n;i++;}
    }
    for(i=i-1;i>=0;i--)printf("%d",re[i]);
}
void xiangjian(point a,point b)
{
    int i=0,j=0,m=0,n=0;
    if(a.cnt>=b.cnt)
    {
         for(i=0;i<b.cnt;i++)
        {
            m=a.a[i]-b.a[i]+n;
            if(m<0){re[i]=m+10;n=-1;}else{re[i]=m;n=0;}
        }
        for(i=b.cnt;i<a.cnt;i++)
        {
            m=a.a[i]+n;
            if(m<0){re[i]=m+10;n=-1;}else{re[i]=m;n=0;}
        }
        for(i=i-1;i>=0;i--){if(re[i]!=0){i++;break;}}
    }
    else
        {
         for(i=0;i<a.cnt;i++)
        {
            m=b.a[i]-a.a[i]+n;
            if(m<0){re[i]=m+10;n=-1;}else{re[i]=m;n=0;}
        }
        for(i=a.cnt;i<b.cnt;i++)
        {
            m=b.a[i]+n;
            if(m<0){re[i]=m+10;n=-1;}else{re[i]=m;n=0;}
        }
        for(i=i-1;i>=0;i--){if(re[i]!=0){i++;break;}}
    }
      for(i=i-1;i>=0;i--)printf("%d",re[i]);
}
int main()
{
    int n=0,i=0,j=0,k=0;
    int min=0,max=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        char s[150]={0};
        scanf("%s",s);fuzhi(s,i);
    }
    for(i=1;i<n;i++)
    {
        if(p[i].flag>p[max].flag)max=i;
        else if(p[max].cnt<p[i].cnt && p[i].flag==p[max].flag){if(p[i].flag==1)max=i;else max=max;}
        else if(p[max].cnt>p[i].cnt && p[i].flag==p[max].flag){if(p[i].flag==1)max=max;else max=i;}
        else if(p[max].cnt==p[i].cnt && p[i].flag==p[max].flag)
        {
            for(k=p[i].cnt-1;k>=0;k--){if(p[i].a[k]>p[max].a[k]){if(p[i].flag==1)max=i;else max=max;break;}if(p[i].a[k]<p[max].a[k]){if(p[i].flag==1)max=max;else max=i;break;}}
        }
    }
    for(i=1;i<n;i++)
    {
        if(p[i].flag<p[min].flag)min=i;
        else if(p[min].cnt>p[i].cnt && p[i].flag==p[min].flag){if(p[i].flag==1)min=i;else min=min;}
        else if(p[min].cnt<p[i].cnt && p[i].flag==p[min].flag){if(p[i].flag==1)min=min;else min=i;}
        else if(p[min].cnt==p[i].cnt && p[i].flag==p[min].flag)
        {
            for(k=p[i].cnt-1;k>=0;k--){if(p[i].a[k]<p[min].a[k]){if(p[i].flag==1)min=i;else min=min;break;}if(p[i].a[k]>p[min].a[k]){if(p[i].flag==1)min=min;else min=i;break;}}
        }
    }
    if(p[max].flag!=p[min].flag)xiangjia(p[max],p[min]);
    else xiangjian(p[max],p[min]);

    return 0;
}
