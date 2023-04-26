#include<stdio.h>
int A(int x,int y)
{
    int arr1[32],arr2[32],i=0,count=0;
    for(i=0;i<32;i++)
	{arr1[i]=(x>>i)&1;}//通过移位和与运算，将二进制数从低位往高位倒着保存在数组中
	for(i=0;i<32;i++)
	{arr2[i]=(y>>i)&1;}
	for(i=0;i<32;i++)
	{
		if(arr1[i]!=arr2[i])//比较两个数组中相应元素是否相等
		count++;
	}
    return count;
}
int main()
{
    int t;//t为测试数据的组数
    int x,y;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&x,&y);
        printf("%d\n",A(x,y));
    }
    return 0;
}

