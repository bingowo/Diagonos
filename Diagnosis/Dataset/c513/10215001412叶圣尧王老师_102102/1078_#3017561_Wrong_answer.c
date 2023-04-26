#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int n;
void lefts(int p,double s,double*a)
{
    if(s>0)
    {
        int l1=p,l2=p;double max=a[p],min=a[p];
        int j=p;
        while(a[j]==a[j+1]&&j<=n)j++;
        if(a[j]<=a[j+1]){max=a[j+1];l2=j;}
        for(int i=p-1;i>=0;i--)
        {
            if(a[i]<min){min=a[i];max=a[i+1];l2=i;}
            if(a[i]>a[i+1])
            {
                if(max>=a[i])max=a[i];
                l1=i+1;
                break;
            }
        }
        if((max-min)*(l2-l1+1)>=s)
        {
            for(int i=l1;i<=l2;i++)
                a[i]+=s/(l2-l1+1);
        }
        else
        {
            for(int i=l1;i<=l2;i++)
                a[i]=max;
            s=s-(max-min)*(l2-l1+1);
            lefts(l1,s,a);rights(l2,s,a);
        }
    }
}

void rights(int p,double s,double*a)
{
    if(s>0)
    {
        int l1=p,l2=p;double max=a[p],min=a[p];
        int j=p;
        while(a[j]==a[j-1]&&j>=0)j--;
        if(a[j]<=a[j-1]){max=a[j-1];l1=j;}
        for(int i=p+1;i<=n+1;i++)
        {
            if(a[i]<min){max=min;min=a[i];l1=i;}
            if(a[i]>a[i-1])
            {
                if(max>=a[i])max=a[i];
                l2=i-1;
                break;
            }
        }
        if((max-min)*(l2-l1+1)>=s)
        {
            for(int i=l1;i<=l2;i++)
                a[i]+=s/(l2-l1+1);
        }
        else
        {
            for(int i=l1;i<=l2;i++)
                a[i]=max;
            s=s-(max-min)*(l2-l1+1);
            lefts(l1,s,a);rights(l2,s,a);
        }
    }
}

int main()
{
    int p;double s;scanf("%d %lf %d",&n,&s,&p);
    double a[n+2];
    for(int t=1;t<=n;t++)
        scanf("%lf",&a[t]);
    a[0]=1000000;a[n+1]=1000000;
    lefts(p,s/2,a);rights(p,s/2,a);
    for(int i=1;i<=n-1;i++)printf("%.0lf ",a[i]);printf("%.0lf",a[n]);
}
