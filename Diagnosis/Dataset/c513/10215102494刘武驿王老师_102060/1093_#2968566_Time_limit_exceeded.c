#include<stdio.h>
int main()
{
    long long unsigned n;
    scanf("%llu",&n);
    while(1)
    {
        n++;
        int test=0;
        if(n%9!=0)
        {
            long long unsigned tmp=n;
            while(tmp)
            {
                int wei=tmp%10;
                if(wei==9) break;
                tmp/=10;
            }
            if(tmp==0) test=1;
        }
        if(test==1) break;
    }
    printf("%llu",n);
}