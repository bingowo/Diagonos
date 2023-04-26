#include <stdio.h>
#include <string.h>

#define MAXN 121  // 数组的最大长度
int f[MAXN][MAXN];      // 存储斐波那契数列的数组，每个元素存储1个整数的1位
int len;

void BIGADD(int n)//高精加法
{
	for(int i=1; i<=len; i++)//两数相加
	    f[n][i]=f[n-1][i]+f[n-2][i];
	for(int i=1; i<=len; i++)//进位
		if(f[n][i]>=10)
		{
			f[n][i+1]+=f[n][i]/10;
			f[n][i]%=10;
			if(f[n][len+1]>0)len++;
		}
}

int main()
{
    int T;
    scanf("%d",&T);
    len=1;
	f[1][1]=1;
	f[2][1]=1;
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        for(int i=3; i<=n; i++)//开始计算
	        BIGADD(i);
	    for(int i=len; i>=1; i--)//输出
	        printf("%d",f[n][i]);
        printf("\n");
    }
    return 0;
}