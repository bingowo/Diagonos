#include <stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        long long int n;int m=0;int i=0;
        int a[100]={0}
        scanf("%d",&n);
        while(n!=0)
        {
            m=n%2333;
            n=n/2333;
            a[i]=m;
            i++;
        }
        for(;i--;i>=0)
        {
            printf("%d",a[i]);
        }
    }
    return 0;
}