#include <stdio.h>
#include <string.h>
int T;
int main(void)
{
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++)
	{
		char num[100] = {0};
		scanf("%s",num);
		int len = strlen(num); 
		int res = 0;
		for(int i=0;i<len;i++)
		{
			int add = 0;
			if(num[i]=='-') add = -1;
			else if(num[i]=='0') add = 0;
			else if(num[i]=='1') add = 1;
			res = res*3+add;
		}
		printf("case #%d:\n",kase);
		printf("%d\n",res);
	}
	return 0;
}