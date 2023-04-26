#include<stdio.h>
const int maxn=25;
int aa,n,m,x,a[maxn],b[maxn];
int main()
{
    scanf("%d%d%d%d",&aa,&n,&m,&x);
    a[1]=b[2]=1;
    for(int i=3;i<=n;i++) a[i]=a[i-1]+a[i-2],b[i]=b[i-1]+b[i-2];
    if(n==1) printf("%d\n",a);
    else {
        int bb=(m-(a[n-1]+1)*aa)/(b[n-1]-1);
        printf("%d\n",aa*(a[x]+1)+(b[x]-1)*bb);
    }
    return 0;
}