#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	int x,y; 
	scanf("%d%d",&x,&y);
	if((x+y)%2==0)
		printf("-1");
	else
	{
		int n=1;
		for(int i=1;;i++)
		{
			n*=2;
			if(n>(x+y))
			{
				printf("%d",i);
				return 0;
			}
		}
	}
	return 0;
 } 