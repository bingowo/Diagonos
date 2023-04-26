#include<stdio.h>
int A(int x)
{
    int B[32],i=0,count=0;
    for(i=0;i<32;i++)
	{B[i]=(x>>i)&1;}//通过移位和与运算，将二进制数从低位往高位倒着保存在数组中
	for(i=0;i<32;i++)
    {
        if (B[i]!=B[i+1]) count+=1;
        else count = 0;
    }
    return count;
}
int main()
{
    int t;//t为测试数据的组数
    int x;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&x);
        printf("case #%d",i);
        printf("%d\n",A(x));
    }
    return 0;
}