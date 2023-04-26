#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int n;
    scanf("lld",&n);
    int re[400],i=0;
    if(n==0) re[i++]=0;
    else
    {
        while(n)
        {
            if(n>0)
            {
                if(n%(-2)==0)
                {
                    re[i++]=0;
                    n/=(-2);
                }
                else if(n%(-2)!=0)
                {
                    re[i++]=(-n)%2;
                    n=(-n)/2;
                }
            }
            else
            {
                re[i++]=(-n)%2;
                n=(1-n)/2;
            }
        }
    }
    i;
    int len=i;
    for(i=len-1; i>=0; i--)
    {
        printf("%d",&re[i]);
    }
    return 0;
}

