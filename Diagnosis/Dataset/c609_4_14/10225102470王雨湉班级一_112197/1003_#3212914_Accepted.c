#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,s[50];
    scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
        int j=0;
        long long int n;
        scanf("%lld",&n);
        if(n==0)
            printf("0");
        else
        {
            while(n>0)
            {
                s[j++]=n%2333;
                n/=2333;
            }
            for(j; j>0; j--)
            {
                printf("%d ",s[j-1]);
            }
        }
        printf("\n");
    }
    return 0;
}
