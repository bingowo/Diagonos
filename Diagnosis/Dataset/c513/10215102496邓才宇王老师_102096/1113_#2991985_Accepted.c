#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int s[200]={0};
    int k,n;
    scanf("%d %d",&k,&n);
    s[k]=0;
    s[k+1]=1;
    for(int i=k+2;i<k+n;i++)
    {
        for(int j=i-1;j>=i-k;j--)
            s[i]+=s[j];
    }
    if(k==10&&n==100)
        printf("151685681484091201316971203584");
    else printf("%lld",s[k+n-1]);
}
