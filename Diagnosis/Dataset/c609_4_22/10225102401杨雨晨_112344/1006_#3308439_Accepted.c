#include<stdio.h>
int change(char *s)
{	
	int i; 
	int a[128];for (i=0;i<128;i++)a[i]=-1;
	int digit=0,N=1;char *p=s;//指针为什么要复制？
	a[*p]=1;
	while (*++p){//指针开始移动
		if (a[*p]==-1)
		{a[*p]=digit;
		digit=digit?digit+1:2;
		N++;}}
	if (N<2){N=2;}//最小是二进制 
	long long ans=0;
	p=s;
	while(*p)ans=ans*N+a[*p++];// 
    printf("%lld\n",ans);
}
int main()
{	int t,i;
	char a[100];
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{	scanf("%s",&a);
	
		printf("case #%d:\n",i);
		change(a);
	}
}