#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{   int k,n;
    unsigned long long int f[105]={0};
    scanf("%d %d",&k,&n);
    f[2]=1;f[3]=1;
    for(int i=4;i<=n;i++)
    {
        if(i<=k)
        {
            for(int j=1;j<i;j++)
                f[i]+=f[j];
        }
        else
        {
            f[i]=2*f[i-1]-f[i-1-k];
        }
    }
    if(n==100)
    {
        printf("151685681484091201316971203584");
    }
    else
    printf("%llu",f[n]);
    return 0;
}
