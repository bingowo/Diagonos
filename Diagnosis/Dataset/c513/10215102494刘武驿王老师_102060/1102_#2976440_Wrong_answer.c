#include<stdio.h>
#include<math.h>
int main()
{
    unsigned long long n;
    scanf("%llu",&n);
    int m;
    m=sqrt(n);
    if(n==m*m)
    {
        if(n%2==0) printf("(%d,%d)",-m/2,-m/2);
        else printf("(%d,%d)",m/2,m==1?1:(m/2)+1);
        return 0;
    }
    if(n==2)
    {
        printf("(-1,-1)"); return 0;
    }
    else
    {
        if(m%2!=0)
        {
            int q=(m+1)*(m+1);
            m*=m;
            if(n-m>q-n)
            {
                int tmp=sqrt(q);
                tmp/=2;
                tmp=-tmp;
                printf("(%d,%d)",tmp,tmp+q-n);
            }
            else
            {
                int tmp1=sqrt(n)/2+1;
                int tmp2=sqrt(n)/2;
                tmp2-=n-m;
                printf("(%d,%d)",tmp2,tmp1);
            }
        }
        else
        {

            int q=(m+1)*(m+1);
            m*=m;
            if(n-m<q-n)
            {
                int tmp=-sqrt(n)/2;
                printf("(%d,%d)",tmp+n-m,tmp);
            }
            else
            {
                int tmp1=sqrt(q)/2+1;
                int tmp2=sqrt(q)/2;
                tmp1-=q-n;
                printf("(%d,%d)",tmp2,tmp1);
            }
        }
    }
}
