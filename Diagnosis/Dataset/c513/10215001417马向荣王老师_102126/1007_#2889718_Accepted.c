#include<stdio.h>
int main(void)
{
    int T=0;//问题数
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        long long int n=0;//用十进制表示的正整数
        scanf("%lld\n",&n);
        printf("case #%d:\n",i);
        int first=n%2;
        int second=0;
        int count=1;//负责记number在遇到相同的之前的个数
        int number=1;//记不同的个数
        while(n!=0)
        {
            n>>=1;
            second=n%2;
            if(first!=second) number++;
            else
            {
                if(count<number) count=number;//把数字给count
                number=1;//重置
            }
            first=second;//比下一个
        }
        if(number>count) count=--number;
        printf("%lld\n",count);
    }
    return 0;
}