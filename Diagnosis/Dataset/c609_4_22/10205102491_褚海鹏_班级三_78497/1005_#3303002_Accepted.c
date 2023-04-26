#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		char s[100];
		unsigned long long int result=0;
		scanf("%s",s);
		for(int j=0;s[j];j++)
		{
			result=result*3;
			if(s[j]=='-')result=result-1;
			else if(s[j]=='1')result=result+1;
		}
		printf("case #%d:\n",i);
		printf("%llu\n",result);
	}
	return 0;
}