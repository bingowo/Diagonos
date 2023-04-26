#include<stdio.h>
#include<string.h>

int main()
{
	int T;
	scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
		int temp=n;
        int count=0;
		do
        {
			count++;
		}while(temp/=2);     //求得二进制的位数
        int flag=1;  //一个指标,比指标大的sum替换该指标从而求出最大值
        for(int j=0;j<count-1;j++)  //j最大为count-2,也就是第二位(从左往右),若为第一位会满足循环条件使sum变为2
		{
			int temp1=j;   //1左移的位数
			int sum=1; //记录非重复二进制串长度,如果左边一位与本位不同则sum++(加的是后一位)
			while((((n&(1<<temp1))==0)&&((n&(1<<(temp1+1)))!=0))   //注意括号! 位运算的优先级低于逻辑运算
                  ||(((n&(1<<temp1))!=0)&&((n&(1<<(temp1+1)))==0)))        //即与后一位的二进制数不同
            {
				sum++;
				temp1++;
				if(temp1==count)
				{
					break;
				}
			}
			if(sum>flag)
            {
				flag=sum;
			}
        }
        printf("case #%d:\n",i);
        printf("%d\n",flag);
    }

	return 0;
}
