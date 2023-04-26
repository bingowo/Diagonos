#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n!=-1)
    {
        long long int sum=1<<n+1;
        for(long long int i=(1<<n+2)-1;i>=0;i--)
        {
            long long int temp=i;
            while(temp)
            {
                if(temp%2==1)
                {
                    if((temp>>1)%2==0)
                    {
                        if((temp>>2)%2==0) {sum--;break;}
                    }
                }
                temp=temp/2;
            }
        }
        printf("%lld\n",sum);
        scanf("%d",&n);
    }
    return 0;
}