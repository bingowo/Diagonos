#include <stdio.h>
int main()
{
	int t,i=0;
	scanf("%d",&t);
	for(i;i<t;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		int m,d=1,num=0,j=0;
		m=x^y;
		for(j;j<32;j++)
		{
			if(m&d) num++;
			d=d<<1;
		}
		printf("%d\n",num);
		
	}
	return 0;
}