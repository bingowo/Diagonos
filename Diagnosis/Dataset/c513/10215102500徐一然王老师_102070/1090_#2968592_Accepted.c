#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    long long int digit;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
        {
            break;
        }
    digit=(long long int)(n*log10(n))+1;//n^n的位数 这里是+1
    int left=pow(10.0,(n*log10(n)-digit+1));//n^n/10^(digit-1)的结果就是最左边的数啦~
    printf("%d\n",left);
    }
}