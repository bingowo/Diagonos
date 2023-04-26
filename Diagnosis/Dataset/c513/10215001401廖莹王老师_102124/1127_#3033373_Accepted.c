#include <stdio.h>
#include <stdlib.h>
int gcd(int m,int n)
{
    if(n<=m && m%n==0)return n;
    else if(n>m)return gcd(n,m);
    else return gcd(n,m%n);
}
int main()
{
    int n=0,i=0,fz=0,fm=1,k=0;
    int a[150][2]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        char c;
        scanf("%d%c%d",&a[i][0],&c,&a[i][1]);
    }
    for(i=0;i<n;i++)
    {
        fm=fm*a[i][1]/gcd(fm,a[i][1]);
    }
    for(i=0;i<n;i++)fz=fz+a[i][0]*fm/a[i][1];
    k=gcd(fz,fm);
    fz=fz/k;fm=fm/k;
    if(fz==fm)printf("1");
    else printf("%d/%d",fz,fm);
    return 0;
}
