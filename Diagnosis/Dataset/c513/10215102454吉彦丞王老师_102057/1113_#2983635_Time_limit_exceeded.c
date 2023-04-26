#include<stdio.h>
unsigned long long num(int k,int n)
{
    if(n==1)
    {
        return 0;
    }
    else if(n==2)
    {
        return 1;
    }
    else
    {
        unsigned long long t=0;
        if(k>=n)
        {
            for(int i=0;i<n;i++)
            {
                t=t+num(k,i);
            }
        }
        else
        {
            for(int i=n-k;i<n;i++)
            {
                t=t+num(k,i);
            }
        }
        return t;
    }
    
}
int main()
{
    int k,n;
    scanf("%d%d",&k,&n);
    printf("%llu",num(k,n));
    return 0;
}