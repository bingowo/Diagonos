#include<stdio.h>
int ret(int x,int y)
{
	int a=x,b=y,c;
	if(x<y)
	{
		a=y;b=x;
	}
	for(;;)
	{
		c=a%b;
		if(c==0) break;
		a=b;
		b=c;	
	}
	return x/b;
}
int main()
{
	int a;
	char s[1000];
	scanf("%d",&a);
	getchar();
	while(gets(s))
	{
		int x=0,y=0;
		for(int i=0;s[i];i++)
		{
			y=y+8;
			unsigned char a=s[i];
			while(a>0)
			{
				if((a%2)==1) x++;
				a=a/2;
			}
		}
		int k=x;
		x=ret(x,y);
		y=ret(y,k);
		printf("%d/%d\n",x,y);
	}
	return 0;
}