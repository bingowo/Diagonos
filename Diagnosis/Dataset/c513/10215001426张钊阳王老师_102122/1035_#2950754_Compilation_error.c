#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct yuan
{
    long long r,h;
    long long d,c;
}a[1100];
long long cmp(yuan a,yuan b)
{
    return a.c>b.c;
}
int main()
{
    long long n,m,maxn=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].r>>a[i].h;
        a[i].d=a[i].r*a[i].r;
        a[i].c=2*a[i].r*a[i].h;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        long long ans=a[i].c+a[i].d;
        int count1=1;
        for(int j=1;j<=n&&count1<m;j++)
        {
            if(i==j||a[i].r<a[j].r)    continue;
            ans+=a[j].c;
            count1++;
        }
        maxn=max(maxn,ans);
    }
    cout<<maxn<<endl;
    return 0;
}