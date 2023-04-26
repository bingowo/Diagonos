#include <stdio.h>
#include <stdlib.h>



int f(int a,int n,int m,int x)
{
    if (x==n) return 0;
    if (x==n-1) return m;
    if (x==1 || x==2) return a;
    if (x==3) return 2*a;
    if (x>3 && x<n-1) return (f(a,n,m,x+1)+f(a,n,m,x-2))/2;
}



int main()
{
    int a,n,m,x;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    printf("%d\n",f(a,n,m,x));
    return 0;
}
