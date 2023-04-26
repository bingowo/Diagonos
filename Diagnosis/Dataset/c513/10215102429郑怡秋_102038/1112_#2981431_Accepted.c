#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int n;
		scanf("%d",&n);
		int w,x,y,z;
		int tump=0;
		for(w=0;w<=n/4;w++)
		{
			for(x=0;x<=n/3;x++)
			{
				for(y=0;y<=n/2;y++)
				{
					int ans=4*w+3*x+2*y;
					if(ans<=n) tump++;
					if(ans>n) break;
				}
			}
		}
		printf("%d\n",tump);
	}
	return 0;
	
}