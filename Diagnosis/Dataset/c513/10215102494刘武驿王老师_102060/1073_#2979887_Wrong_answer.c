#include<stdio.h>
int main()
{
    long long unsigned a,b;
    scanf("%llu %llu",&a,&b);
    long long unsigned tmp,count=0;
    for(tmp=a;tmp<=b;tmp++)
    {
        if(tmp%9==0) continue;
        else
        {
            long long unsigned tmp1=tmp;
            int test=0;
            while(tmp1)
            {
                int n=tmp%10;
                if(a==9)
                {
                    test=1;
                    break;
                }
                tmp1/=10;
            }
            if(count==0) count++;
        }
    }
    printf("%llu",count);
}