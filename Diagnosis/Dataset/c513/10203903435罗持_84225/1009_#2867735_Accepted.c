#include <stdio.h>
int n;
int gcd(int a,int b)
{
	if(a%b==0) return b;
	return gcd(b,a%b);
}
int main(void)
{
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		int tot = 0,one = 0;
		char c;
		while(scanf("%c",&c)!=EOF)
		{
			if(c == '\n') break;
			for(int i=0;i<8;i++)
			{
				if(c&1) one++;
				tot++;
				c = c>>1;
			}
		}
		int gc = gcd(tot,one);
		printf("%d/%d\n",one/gc,tot/gc);
	}	
	return 0;
} 