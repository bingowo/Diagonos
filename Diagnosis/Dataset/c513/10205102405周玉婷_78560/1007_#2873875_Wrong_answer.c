#include<stdio.h>//如果让你输出最长的，怎么办？ 
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
	int an=*(int*)a;
	int bn=*(int*)b;
	return bn-an;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)//总次数 
	{
		int n;
		scanf("%d",&n);//输入 
		int str[32];//将二进制情况放到数组里 ,注意是逆序放置 
		int check=1; 
		for(int j=0;j<32;j++)
		{
			if(n&check) str[j]=1;
			else str[j]=0;
			check=check<<1;
		}
		int len=1;//二进制串长度 
		int result[16];int k=0;
		int j=15; 
		while(str[j--]==0);//跳过前置0 
		for(int l=j+1;l>0;l--)
		{
		if(str[l]!=str[l-1])  
		len++;
		else if(len!=1)
			{
			result[k++]=len;len=1;
			}
		} 
		result[15]=1;
		qsort(result,16,sizeof(result[0]),cmp);
		printf("case #%d:\n%d\n",i,result[0]);
	 } 
	return 0;
	
 } 