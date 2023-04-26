#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct{
	int l;
	int a[1010];
}F;
F f[150];
int main() {
	int T;
	scanf("%d",&T);
	f[1].l=1;f[2].l=1;
	f[1].a[1]=1;f[2].a[1]=1;
	for(int j=3;j<=120;j++)
	{
		int len = f[j-1].l >f[j-2].l ? f[j-1].l + 1 : f[j-2].l+ 1; //存储运算结果的最大位数
   		int flag = 0;//保存是否有进位
    	int temp = 0;
    	int cnt=1;
    	for (int i = 1; i <= len; i++)
		{
        	temp = f[j-1].a[i]+f[j-2].a[i] + flag;
        	f[j].a[cnt++] = temp % 10;//对应位的计算结果放在数组的对应位上
        	flag = temp / 10;
    	}
    	if(flag>0)
    		f[j].a[cnt++]=flag;
    	f[j].l = cnt;
	}
    for(int t=0;t<T;t++)
    {
    	printf("case #%d:\n",t);
    	int n;
    	scanf("%d",&n);
    	if(n==0)
    	{
    		printf("0\n");
    		continue;
		}
    	int len = f[n].l;
    	while (f[n].a[len] == 0) 
			len--; //去除先导0
    	while (len > 0) 
			printf("%d",f[n].a[len--]);
    	printf("\n");
	}
    return 0;
}