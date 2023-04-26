#include <stdio.h>
#include <stdlib.h>

int arr[22];
int fi(int n)
{
    if (n==1 || n==2) return 1;
    return fi(n-1)+fi(n-2);
}

int IN(int x)
{
    for (int i=3;i<=x;i++)
        arr[i]=arr[i-1]+arr[i-2];
    return arr[x];
}

int f(int a,int n,int m,int x)
{
    if (x==n) return 0;
    if (x==n-1) return m;
    if (x==1 || x==2) return a;
    if (x==3) return 2*a;
    if (x>3 && x<n-1) return f(a,n,m,x-1)+IN(x-2);
}



int main()
{
    int a,n,m,x;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    arr[1]=a;
    int j=m-2*a,i;
    int cnt=0;
    for (i=3;i<=n-3;i++)
        cnt+=fi(i-2);
    j-=a*cnt;
    cnt+=fi(i-2);
    arr[2]=j/cnt;
    printf("%d\n",f(a,n,m,x));
    return 0;
}
