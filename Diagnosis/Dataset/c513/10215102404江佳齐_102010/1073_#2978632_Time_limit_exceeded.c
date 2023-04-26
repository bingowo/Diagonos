#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    long long int a,b,count=0;
    scanf("%lld %lld",&a,&b);
    for(long long int i=a;i<=b;i++)
    {
        if(i%9!=0)
        {
            int flag=0;
            long long int j=i;
            while(j)
            {
                int temp=j%10;
                j=j/10;
                if(temp==9)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0) count++;
        }
    }
    printf("%lld\n",count);
    return 0;
}
