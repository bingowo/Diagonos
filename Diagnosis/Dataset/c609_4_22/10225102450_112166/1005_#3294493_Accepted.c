#include<stdio.h>
#include<string.h>

int main()
{
	int T; 
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		char s[100];
		scanf("%s",s);
        int number=0;
		for(int j=0;j<strlen(s);j++)   //迭代
		{
			if(s[j]=='1')
			{
				number=3*number+1;
			}
			if(s[j]=='0')
			{
				number=3*number;
			}
			if(s[j]=='-')
			{
				number=3*number-1;
			}
		}
		printf("case #%d:\n",i);
		printf("%d\n",number);
	}
	return 0;
}
