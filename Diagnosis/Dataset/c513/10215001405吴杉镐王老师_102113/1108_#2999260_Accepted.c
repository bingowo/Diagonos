#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define M 1000000007
int T,n,m;
int hav[1005];

int main()
{
    scanf("%d",&T);
    for(int c=0;c<T;c++)
    {
        for(int i=0;i<m;i++)
            hav[i]=0;
        scanf("%d%d",&n,&m);
        printf("case #%d:\n",c);
        printf("%d",n/m); //整数部分
        n%=m;
        if(n==0)
            continue; //整除的情况
        putchar('.');
        int pos=0;
        //下面是关键
        while(n)
        {
            //非常的巧妙
            //hav数组相当于是一个利用余数n
            //为下标的一个记录开始循环位置
            //的数组
            //第二次相同的n出现时
            //代表出现循环
            //即可输出！
            if(hav[n]!=0)
            {
                printf("\n%d-%d",hav[n],pos);
                break;
            }
            hav[n]=++pos;
            //利用整型数进行浮点数运算的原理！
            n*=10;
            printf("%d",n/m);
            n%=m;
            //要会！
        }
        puts("");
    }
    return 0;
}
//相当精彩的算法