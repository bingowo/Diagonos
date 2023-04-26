#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int f=0;f<t;f++)
    {
        long long int n;
        scanf("%lld",&n);
        if(n==0) printf("0\n");
        int s[10];int p=0;
        while(n)
        {
            s[p++]=n%2333;
            n=n/2333;
        }
        for(int i=p-1;i>=0;i--)
        {
            printf("%d",s[i]);
            if(i!=0) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}