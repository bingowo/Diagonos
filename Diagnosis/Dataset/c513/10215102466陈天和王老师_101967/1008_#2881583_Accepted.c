#include <stdio.h>

int main()
{
    int i,t;
    int a=1;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int a,b,c;
        int n=0;
        scanf("%d %d",&a,&b);
        c=a^b;//现在c的二进制就是ab异或的结果（异或运算如果位数不同则在少的一方前面补上零。

        while(c){
            if((c&1)==1){
                n++;
            }
            c=c>>1;
        }//使用右移和与预算计算一的位数。

//        while(c!=0)
//        {
//            n+=c%2;
//            c/=2;
//        }
        printf("%d\n",n);
    }
    return 0;
}

//进行位运算时你这个数据类型咋定义，比如64位32位，比如什么逻辑右移，算数右移