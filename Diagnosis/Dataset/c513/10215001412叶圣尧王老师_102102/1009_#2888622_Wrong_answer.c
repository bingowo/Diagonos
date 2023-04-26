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
    int n,i,j,k,num1,num2;char sign;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        num1=0;num2=0;
        getchar();
        while((sign=getchar())!='\n')
        {
            k=sign;
            while(k>0)
            {
                if(k%2==1)num1++;
                k/=2;
            }
            if(sign<='9'&&sign>='0')num2+=32;
            else num2+=8;
        }
        int GCD(int m,int n);
        j=GCD(num1,num2);
        num1/=j;num2/=j;
        printf("%d/%d\n",num1,num2);
    }
}
