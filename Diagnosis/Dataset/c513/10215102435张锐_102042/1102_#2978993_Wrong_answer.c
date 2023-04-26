#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    long long int n;
    scanf("%lld",&n);long long int num=0;
    long long int temp=(long long int)sqrt(n);
    if(n==0) printf("(0,0)\n");
    else
    {
        if(temp%2==1) ;
        else temp-=1;
        num=temp*temp;
        long long int bushu=temp;
        long long int a=(temp-1)/2,b=a+1;
        for(int i=1;num<n;i++)
        {
            if((n-num)<bushu)
            {
                if(i%4==0) b=b+(n-num);
                if(i%4==1) a=a-(n-num);
                if(i%4==2) b=b-(n-num);
                if(i%4==3) a=a+(n-num);
                break;
            }
            else
            {
                if(i%4==0) b=b+bushu,num+=bushu;
                if(i%4==1) a=a-bushu,num+=bushu,bushu++;
                if(i%4==2) b=b-bushu,num+=bushu;
                if(i%4==3) a=a+bushu,num+=bushu,bushu++;
            }

        }
        printf("(%lld,%lld)\n",a,b);
    }

    return 0;
}
