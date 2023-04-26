#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int GCD(int m,int n)
{int t;
    if(m<n){t=m;m=n;n=t;}
    m=m%n;
    if(n==0)return m;
    else return m==0?n:GCD(m,n);
}

int main()
{
    int n,i,j,num1,num2;char sign;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        num1=0;num2=0;
        if(i==0)getchar();
        while((sign=getchar())!='\n')
        {
            
            if(sign<0)
            {
                num1++;
                sign^=128;
            }
            while(sign>0)
            {
                if(sign%2==1)num1++;
                sign/=2;
            }
            num2+=8;
        }
        int GCD(int m,int n);
        j=GCD(num1,num2);
        num1/=j;num2/=j;
        printf("%d/%d\n",num1,num2);
    }
}