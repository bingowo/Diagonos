#include <stdio.h>
#include <string.h>
int main()
{
	int i,flag,len;
	char str[2005];
	gets(str);
	len = strlen(str);
	for(i = 0;i < len;i++)
	{
		if((str[i] >= 'A'&&str[i] <= 'Z')||(str[i] >= 'a'&&str[i] <= 'z'))
		{
			printf("%c",str[i]);
		}
		else
		{
			if((str[i+1] >= 'A'&&str[i+1] <= 'Z')||(str[i+1] >= 'a'&&str[i+1] <= 'z'))
			{
				printf("\n\n");
			}
		}		
	}
	
}