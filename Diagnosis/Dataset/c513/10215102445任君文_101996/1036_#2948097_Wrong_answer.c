#include<stdio.h>
#define N 100
void swap(long long* a,long long* b)
{
    long long temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
long long Abs(long long a)
{
    if(a<0)
        return -a;
    else
        return a;
}
int main()
{
    int i,j;
    int n;
    long long y[N]={0},x[N]={0};
    long long temp,m[N]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&x[i],&y[i]);
    }
    for(i=0;i<n;i++)
    {
        m[i]=Abs(x[i])+Abs(y[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(m[j]<m[j+1])
            {
                swap(&m[j],&m[j+1]);
                swap(&x[j],&x[j+1]);
                swap(&y[j],&y[j+1]);
            }
            else if(m[j]==m[j+1])
            {
                if(x[j]>x[j+1])
                {
                    swap(&m[j],&m[j+1]);
                    swap(&x[j],&x[j+1]);
                    swap(&y[j],&y[j+1]);
                }
                else if(x[j]==x[j+1])
                {
                    if(y[j]>y[j+1])
                    {
                        swap(&m[j],&m[j+1]);
                        swap(&x[j],&x[j+1]);
                        swap(&y[j],&y[j+1]);
                    }
                }
            }
        }
    }
    printf("%lld\n",Abs(x[1]-x[0])+Abs(y[1]-y[0]));
    return 0;
}