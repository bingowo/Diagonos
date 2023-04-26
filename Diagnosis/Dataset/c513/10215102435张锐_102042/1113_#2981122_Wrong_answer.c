#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int s[200]={0};
    s[0]=0;s[1]=1;
    int k,n;
    scanf("%d%d",&k,&n);
    if(k>2)
    {
        for(int i=2;i<k;i++)
        {
            for(int j=0;j<i;j++)
                s[i]+=s[j];
        }
    }
    for(int i=k;i<n;i++)
    {
        for(int j=1;j<=k;j++) s[i]+=s[i-j];
    }
    printf("%lld\n",s[n-1]);
    return 0;
}
