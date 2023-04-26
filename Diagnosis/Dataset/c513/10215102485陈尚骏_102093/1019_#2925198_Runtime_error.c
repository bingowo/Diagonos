#include <stdio.h>
#include <stdlib.h>

void qSort(long long *a,int l,int h)
{
    if(l>=h) return ;
    int i=l,j=h;
    long long key=a[l];
    while(i<j)
    {
        while(key<=a[j])
            j--;
        a[i]=a[j];
        while(key>=a[i])
            i++;
        a[j]=a[i];
    }
    a[i]=key;
    qSort(a,l,i-1);
    qSort(a,i+1,h);
}

int main()
{
    int m,n,i,k;
    while(scanf("%d %d",&n,&m))
    {
        long long s[n];
        if(n==0) break;
        for(i=0;i<n;i++)
        {
            s[i]=i+1;
            s[i]=s[i]+30000000000LL;
        }
        for(k=0;k<m;k++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if(c==1)
            {
                s[a-1]-=300000000;
                s[a-1]+=100000;
                s[b-1]+=100000000;
                s[b-1]+=100;
            }
            else if(c==-1)
            {
                s[a-1]-=100000000;
                s[b-1]-=100000000;
            }
        }
        for(i=0; i<n; i++) s[i]=(s[i]-200000*((s[i]/100000)%1000)+99900000);
        qSort(s,0,n-1);
        for(i=0;i<n;i++)
        {
            if(i==n-1) printf("%d\n",s[i]%100);
            else printf("%d ",s[i]%100);}
    }
    return 0;
}
