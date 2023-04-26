#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

long long int zh(long long n)//将n从九进制转化成十进制
{
    int a[20]={0},k=0;
    while(n!=0)
    {
        a[k]=n%10;
        n/=10;
        k++;
    }//k是十进制位数，a中元素个数
    long long data=0;
    for(int i=k-1;i>=0;i--)
    data=data*9+a[i];
    return data;
}

long long g(long long a)
{
    long long d0 = a%10;
    for (long long x = a - d0; x <= a; x++) {	 // g in 1096.PPT
        char str[100] = {0};
        sprintf(str, "%lld", x);
        if (x%9 == 0 || strchr(str, '9') != 0) d0--;
    }
    return d0 + 8*zh(a - a%10)/9;	 // Ans in 1096.PPT
}

int main()
{
    long long int a,b,sheng1;
    scanf("%lld%lld",&a,&b);
    printf("%lld",g(b)-g(a)+1)；
    
    
    return 0;
}