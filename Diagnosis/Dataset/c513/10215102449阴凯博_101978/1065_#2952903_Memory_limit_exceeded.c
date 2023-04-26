#include <stdio.h>
#include <stdlib.h>

long long arr[22]={0};


long long f(int a,int n,int m,int x)
{
    arr[n]=0; arr[n-1]=m; arr[1]=a; arr[2]=a; arr[3]=2*a;
    if (x>3 && x<n-1)
    {
        if (arr[x]==-1)
            arr[x]=(f(a,n,m,x+1)+f(a,n,m,x-2))/2;
    }
    return arr[x];
}



int main()
{
    int a,n,m,x;
    for (int i=0;i<22;i++)
        arr[i]=-1;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    printf("%lld\n",f(a,n,m,x));
    return 0;
}
