#include <stdio.h>
#include <stdlib.h>

int arr[22];

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
    if (x>3 && x<n-1) return f(a,n,m,x-1)+IN(x)-IN(x-1);
}



int main()
{
    int a,n,m,x;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    arr[1]=a;
    arr[2]=(m-(n-3)*a)/(n-3);
    printf("%d\n",f(a,n,m,x));
    return 0;
}
