#include <stdio.h>
#include <stdlib.h>
/*long long f(int n)
{
    if(n==1)
        return 1;
    else if(n==0)
        return 0;
    else if(n==2)
        return 2;
    else if(n==3)
        return 4;
    else if(n==4)
        return 8;
    else
        return f(n-1)+f(n-2)+f(n-3)+f(n-4);

}*/
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        long long a[55]={0,1,2,4,8};
        scanf("%d",&n);
        long long cnt=0;
        for(int i=5;i<=n;i++)
        {
            a[i]=a[i-1]+a[i-2]+a[i-3]+a[i-4];
        }

       // f(n);
        printf("case #%d:\n%lld\n",i,a[n]);
    }
    return 0;
}
