#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int GCD(int m,int n)
{
    if(m>n)m-=n;
    if(m<n)n-=m;
    return m==n?m:GCD(m,n);
}

int main()
{
    int n,i,j,k,num0,num1,num2;char sign;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        num0=0;num1=0;
        while((sign=getchar())!=EOF)
        {
            k=sign;
            while(k>0)
            {
                if(k%2==0)num0++;
                else num1++;
                k/=2;
            }
        }
        num2=num1+num0;
        j=GCD(num1,num2);
        num1/=j;num2/=j;
        printf("%d/%d",num1,num2);
    }
}