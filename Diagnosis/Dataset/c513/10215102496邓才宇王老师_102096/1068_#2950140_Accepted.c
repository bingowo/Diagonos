#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    while(n!=-1||m!=-1)
    {
        long long int s[40];
        for(int k=0;k<40;k++)
            s[k]=0;
        s[m]=1;
        for(int i=m+1;i<n+1;i++)
        {
            s[i]=2*s[i-1]+pow(2,i-1-m)-s[i-1-m];
        }
        printf("%lld\n",s[n]);
        scanf("%d %d",&n,&m);
    }
}
