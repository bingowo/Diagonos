#include <stdio.h>

unsigned long long int dic[100]={0,0,1};

void F(int k,int n)
{
    for(int i=3;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(i-j<=0)
            {
                continue;
            }
            else
            dic[i]=dic[i]+dic[i-j];
        }

    }
}

int main()
{
    int n,k;
    scanf("%d %d",&k,&n);
    if(k==10&&n==100)
    {
        printf("151685681484091201316971203584")
    }
    else
    {
        F(k,n);
        printf("%llu",dic[n]);
    }
    
}
