#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int z=0; z<T; z++)
    {
        int m, n;
        double ans=1;
        unsigned long long tmp;
        scanf("%d%d",&m,&n);
        n=n>m/2?(m-n):n;
        for(int i=0; i<n; i++)
        {
            ans*=(m-i);
            ans/=(i+1);
        }
        tmp=(unsigned long long)ans;
        printf("case #%d:\n",z);
        printf("%lld\n",tmp);
    }

}
