#include <stdio.h>
#include <stdlib.h>

long long arr[22]={0};
int a,n,m,x;



long long f(int x)
{

    if (x>3 && x<n-1)
    {
        if (arr[x]==-1)
            arr[x]=(f(x+1)+f(x-2))/2;
    }
    return arr[x];
}



int main()
{
    for (int i=0;i<22;i++)
        arr[i]=-1;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    arr[n]=0; arr[n-1]=m; arr[1]=a; arr[2]=a; arr[3]=2*a;
    printf("%lld\n",f(x));
    return 0;
}
