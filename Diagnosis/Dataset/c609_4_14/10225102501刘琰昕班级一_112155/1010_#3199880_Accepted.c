#include <stdio.h>
#include <stdlib.h>

//定义返回非负余数与对应商的除法
int mod(int a,int b,int *quotient,int *remainder)
{
	if(a<0&&a%b!=0)
    {
		*quotient=a/b+1;
		*remainder=a-(a/b+1)*b;
	}
	else
    {
        *quotient=a/b;
        *remainder=a%b;
    }
}

//定义映射数组
char base[]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

void TtoR(long long N,long long R)
{
    if(N!=0)
    {
        int quotient,remainder;
        mod(N,R,&quotient,&remainder);
        TtoR(quotient,R);
        printf("%c",base[remainder]);
    }
}

int main()
{
    long long N,R;
    scanf("%lld%lld",&N,&R);
    if(N==0)printf("0\n");
    else
    {
        TtoR(N,R);
        printf("\0");
    }
}
