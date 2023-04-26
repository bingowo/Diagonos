#include <stdio.h>
int T,n,r;
char table[36] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N',
				'O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char res[10005] = {0};
int len = 0;
int main(void)
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&r);
		len = 0;
		int flag = 1;
		if(n<0) 
		{
			flag = -1;
			n = n*(-1);
		}
		while(n)
		{
			if(n<r)
			{
				res[len] = table[n];
				break;
			}
			else
			{
				res[len] = table[n%r];
				n /= r;
				len++;
			}
		}
		if(flag==-1) printf("-");
		int i;
		for(i=len;i>=0;i--) printf("%c",res[i]);
		putchar('\n');
	}
	return 0;
} 