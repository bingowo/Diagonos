#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int t(char c)
{
	if(c=='1')return 1;
	else if(c=='0')return 0;
	else return -1;
}

int main()
{
	int result;
	char input[50];
	int i;
	
	int c,cases;
	scanf("%d",&cases);
	for(c=0;c<cases;c++)
	{
		result=0;
		scanf("%s",&input);
		for(i=0;input[i]!='\0';i++)
		{
			result*=3;
			result+=t(input[i]);
		}
		
		printf("case #%d:\n%d",c,result);
		if(c!=cases-1)putchar('\n');
	}
	return 0;
}