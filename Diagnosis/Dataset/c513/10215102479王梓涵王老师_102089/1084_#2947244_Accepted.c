#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		int times;
		scanf("%d",&times); 
		int j;
		long long int res=1;
		if(times == 0)
		{
			printf("case #%d:\n",i);
			printf("1\n");
		}
		else{
		
			for(j=0;j<times;j++)
			{
				res=res*2;
			}
			printf("case #%d:\n",i);
			printf("%lld\n",res);
		}
	}
	return 0;
}