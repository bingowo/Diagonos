#include<stdio.h>
int main()
{
	int n,r;
	char s[100];
	while(scanf("%d %d",&n,&r)!=-1)
	{
		int i,k=0,sum=0;
		while(n)
		{
			sum+=n%r;
			n=n/r;
		}
		
		while(sum)
		{
			if(sum%r>=0&&sum%r<=9)
				s[k++]=sum%r+'0';
			else
				s[k++]=sum%r-10+'A';
			sum=sum/r;
			
		}
		for(i=k-1;i>=0;i--)	
			printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}
————————————————
版权声明：本文为CSDN博主「小-黯」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_44625774/article/details/106017654