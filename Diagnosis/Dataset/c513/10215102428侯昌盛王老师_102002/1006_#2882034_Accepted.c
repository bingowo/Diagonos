#include <stdio.h>
#include <string.h>
int main()
{
	int t,i=0;
	scanf("%d",&t);
	for(i;i<t;i++)
	{
		char m[100];
		scanf("%s",m);
		int len,j=0,sum=0;
		len=strlen(m)-1;
		for(j;j<len;j++)
		{
			if(m[j]=='-') {
				m[j]='1';
				sum=(sum-(m[j]-'0'))*3;
				
			}
			else sum=(sum+(m[j]-'0'))*3;
			
		}
		
		if(m[j]=='-') {
	
			m[j]='1';
			sum=sum-(m[j]-'0');
		}
		else sum=sum+(m[j]-'0');
		printf("case #%d:\n",i);
		printf("%d\n",sum);
	}
	return 0;
}