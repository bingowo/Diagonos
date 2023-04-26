#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int t,a;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int ans=0,b=0;
		scanf("%d",&a);
		a=a-a%5;
		while(a>=5)
		{
			b=a;
			while(b>=5)
			{
				if(b%5==0) {b=b/5;ans++;}
				else break;
			}
			a=a-5;
		}
		printf("case #%d:\n%d\n",i,ans);
		
	}
	
	
}