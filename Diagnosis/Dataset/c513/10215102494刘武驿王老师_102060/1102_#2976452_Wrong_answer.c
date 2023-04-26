#include<stdio.h>
#include<math.h>
int main()
{
    unsigned long long n;
    scanf("%llu",&n);
    long long int m;
    m=sqrt(n);
    if(n==m*m)
    {
        if(n%2==0) printf("(%lld,%lld)",-m/2,-m/2);
        else printf("(%lld,%lld)",m/2,m==1?1:(m/2)+1);
        return 0;
    }
    if(n==2)
    {
        printf("(-1,1)"); return 0;
    }
    else
    {
        if(m%2!=0)
        {
            long long int q=(m+1)*(m+1);
            m*=m;
            if(n-m>q-n)
            {
                long long int tmp=sqrt(q);
                tmp/=2;
                tmp=-tmp;
                printf("(%lld,%lld)",tmp,tmp+q-n);
            }
            else
            {
                long long int tmp1=sqrt(n)/2+1;
                long long int tmp2=sqrt(n)/2;
                tmp2-=n-m;
                printf("(%lld,%lld)",tmp2,tmp1);
            }
        }
        else
        {

            long long int q=(m+1)*(m+1);
            m*=m;
            if(n-m<q-n)
            {
                long long int tmp=-sqrt(n)/2;
                printf("(%lld,%lld)",tmp+n-m,tmp);
            }
            else
            {
                long long int tmp1=sqrt(q)/2+1;
                long long int tmp2=sqrt(q)/2;
                tmp1-=q-n;
                printf("(%lld,%lld)",tmp2,tmp1);
            }
        }
    }
}
