#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    unsigned long long int n;
    scanf("%llu",&n);
    long long int tmp=(long long int)sqrt(n);
    long long int tmp1=tmp+1;
    if((double)tmp==sqrt(n))
    {
        if((tmp%2)==0)printf("(%lld,%lld)",-tmp/2,-tmp/2);
        else  printf("(%lld,%lld)",tmp/2,tmp/2+1);

    }
    else
    {

        long long int tmp2=tmp*tmp;
        long long int tmp3=tmp1*tmp1;
        long long int tmp4=(tmp3-tmp2)/2+tmp2;
        if(n<=tmp4)
        {
            if((tmp%2)==0)printf("(%lld,%lld)",-tmp/2+n-tmp2,-tmp/2);
            else printf("(%lld,%lld)",tmp/2-n+tmp2,tmp/2+1);
        }
        else
        {
            if((tmp%2)==0)printf("(%lld,%lld)",tmp1/2,tmp1/2+1-(tmp3-n));
            else printf("(%lld,%lld)",-tmp1/2,-tmp1/2+tmp3-n);


        }

    }


    // printf("%f\n",sqrt(n));
    //printf("%lld\n",tmp);
}
