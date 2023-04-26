#include<stdio.h>
main()
{
	int T,i=0;
	scanf("%d",&T);
	for(i;i<T;i++)
	{
		int x,y,m=0,j=0;
		scanf("%d %d",&x,&y);
		while((x!=0)||(y!=0))
		{
			if((x%2)!=(y%2)) m++;
			x/=2;
			y/=2;
		}
		printf("%d\n",m);
	}
}