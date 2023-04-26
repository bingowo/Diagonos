#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int T;
int main(void)
{
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++)
	{
		char s[100],s1[100],s2[100];
		scanf("%s %s %s",s1,s2,s);
		int len = strlen(s);
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		int a1=-1,a2=-1,b1=-1,b2=-1;
		int flag = 1;
		for(int i=0;i+len1<=len;i++)
		{
			if(strncmp(s1,s+i,len1)==0)
			{
				if(flag)
				{
					a1 = i;
					flag = 0;
				}
				a2 = i;
			}
		}
		flag = 1;
		for(int i=0;i+len2<=len;i++)
		{
			if(strncmp(s2,s+i,len2)==0)
			{
				if(flag)
				{
					b1 = i;
					flag = 0;
				}
				b2 = i;
			}
		}
		printf("case #%d:\n",kase);
		if(a1==-1 || b1==-1) printf("0\n");
		else
		{
			int res = b2-a1-len1;
			if(res < a2-b1-len2) res = a2-b1-len2;
			if(res < 0) res = 0;
			printf("%d\n",res);
		}
	}
	return 0;
}