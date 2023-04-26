#include<stdio.h>
#include<string.h>
int factorial(int n)//阶乘的函数
{
	if(n==0) return 1;
	int a[100000]={1},i,j;
	int t=0,len=1,tem;//t为进位，len为位数
	for(i=2;i<=n;i++)
	{
		t=0;
		for(j=0;j<len;j++)
		{
			tem=a[j]*i;//乘积的值
	    	a[j]=(tem+t)%10;//每一位分离出来
			t=(tem+t)/10;
			if(t!=0&&j==len-1)//判断位数是否增加
			len++;
		}
	}
	for(i=0;a[i]==0;i++);
	return i;
}
int main()
{
	int n;
	int T;
	scanf("%d",&T);
	for(int cas=0;cas<T;cas++)
    {
        scanf("%d",&n);
        int ans=factorial(n);
        printf("case#%d:\n",cas);
        printf("%d\n",ans);
    }
}
