//2022.2.23忘记了之前的知识，写了一个下午，还有很多思维上错误：惯性思维，不易察觉的bug.加油，变好！ 

#include<stdio.h>
#include<stdlib.h> //以二进制中1的个数排序，由大到小，相同以数本身的大小，由小到大
//按特定要求排序，算法：qsort,cmp,位运算求1的个数，循环 
typedef long long int lli;
int count(lli x)//求二进制1的个数，位运算 
{
	lli check=1;int num_1=0;//xxxxxxxxxx刚才把check设为int了 
	for(int i=0;i<64;i++)//xxxxxxxxxxxxxxxxx之前设为 i<63，想着check只需要向左移动63位即可 ，但这样只&了63位，没发觉这样循环最后一个左移用不到， 
	{
		if(x&check) num_1++;
		check=check<<1;
	}
	return num_1;
}
int cmp(const void*a,const void*b)//比较规则。求位数，比较，返回合适的值 xxxxxxxxx之前cmp的返回类型设为lli了，一定要注意return的类型与定义的返回类型相同！ 
{
	lli an=*(lli*)a;//先由指针得到数据 
	lli bn=*(lli*)b;
	int a1=count(an);//求位数 
	int b1=count(bn);
	if(a1!=b1) return b1-a1;//按要求（由大到小）返回值 
	else return  an>bn?1:-1; //相同，比本身，由小到大 
	
}
int main()
{
	int times;
	scanf("%d",&times);//总次数 
	int time=0;//xxxxxxxxxxxxxxxxx用来记录第几轮，注意要放在while循环外 ,或者使用for(int i=0;i<times;i++) 直接记录 
	while(times--)
	{
		int n;
		scanf("%d",&n);
		lli num[n];//一次多少个待排序的数 
		for(int j=0;j<n;j++)//输入数据 
		{
			scanf("%lld",&num[j]);
		}
		qsort(num,n,sizeof(lli),cmp);//排序 
		printf("case #%d:\n",time++);
		for(int i=0;i<n;i++)//输出 
		printf("%lld ",num[i]);//学习一下大佬的写法	printf("%lld%c",num[i],n-j==1?'\n':' ');
		printf("\n");
	
	}
	return 0;
}
