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
    int n,i,j,k,num0,num1,num2;char sign[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        num0=0;num1=0;
        getchar();gets(sign);
        for(j=0;j<strlen(sign);j++)
        {    k=sign[j];
            while(k>0)
            {
                if(k%2==0)num0++;
                else num1++;
                k/=2;
            }
        }
        num2=num1+num0;
        int GCD(int m,int n);
        j=GCD(num1,num2);
        num1/=j;num2/=j;
        printf("%d/%d",num1,num2);
    }
}
