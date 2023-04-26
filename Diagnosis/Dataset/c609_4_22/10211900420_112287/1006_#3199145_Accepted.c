#include<stdio.h>
#include<string.h>
unsigned long long pow(unsigned long long a,unsigned long long b)
{
    unsigned long long sum,i;
    sum=1;
    for(i=0;i<b;i++)
    {
        sum=sum*a;
    }
    return sum;
}
int main()
{
    char a[100],b[100];
    unsigned long long len,sum,m,n,j,i,T;
    scanf("%llu",&T);
    for(i=0;i<T;i++)
    {
        sum=0;
        scanf("%s",&a);
        len=strlen(a);
        b[1]=a[0];
        for(j=1;j<len;j++)
        {
            if(a[j]!=a[0])
            {
                b[0]=a[j];
                break;
            }
        }
        n=2;
        for(j;j<len;j++)
        {
            for(m=0;m<n;m++)
            {
                if(b[m]==a[j])
                    break;
                if(b[m]!=a[j] && m==n-1)
                {
                    b[n]=a[j];
                    n++;
                    break;
                }
            }
        }
        for(j=0;j<len;j++)
        {
            for(m=0;m<n;m++)
            {
                if(b[m]==a[j])
                    break;
            }
            sum=sum+m*pow(n,len-j-1);
        }
        printf("case #%llu:\n%llu\n",i,sum);
    }
    return 0;
}
