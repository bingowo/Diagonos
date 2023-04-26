#include<stdio.h>
int main( )
{
    int t; //输入几个数
    scanf("%d",&t);
    int i; //循环输入数
    long long a;

    long long m[1000];
    
    for (i=0;i<t;i++)
    ｛  int k=0;
        scanf("%lld",&a);
        do{ m[k]=a%2333;
        a=a/2333;
        //printf("%lld",m[k]);
        k++;
        } while(a>0);

    int j=k-1;
    for(;j>=0;j--)
    {
       printf("%lld ",m[j]);
    }
    printf("\n");
    }
    return 0;
}

