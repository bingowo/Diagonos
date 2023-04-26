#include<stdio.h>
#include<stdlib.h>
int n,sum,signal;
char s[100050][105];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);
	char head=s[0][0];
	char end;
	int tap;
	for(tap=0;s[0][tap]!='\0';tap++)
		;
	tap--;
	end=s[0][tap];	
	for(int i=1;i<n;i++)
	{
		if(s[i][0]!=head)
		{
			printf("-1");
			return 0;
		}
		int j;
		for(j=0;s[i][j]!='\0';j++)
			;
		j--;
		if(s[i][j]!=end)
		{
			printf("-1");
			return 0;
		}	
	}
	/*while(!signal)
	{
		
	}*/
	printf("%d",sum);
	return 0;
}