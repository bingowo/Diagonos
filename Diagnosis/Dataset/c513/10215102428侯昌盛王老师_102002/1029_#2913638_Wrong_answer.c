#include <stdio.h>

#include <string.h>

void bsort(char *str,int n)
{
	int i,j;
	char k;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(str[j]<str[i] && str[j]>='A' && str[j]<='Z' && str[i]>='A'&&str[i]<='Z')
			{
				k=str[i];
				str[i]=str[j];
				str[j]=k;
			}
		}
	}
}

int main()
{
	int t,i;
	scanf("%d",&t);
	fflush(stdin);
	for(i=0;i<t;i++)
	{
		char str[201];
	
		
		gets(str);
		int len=strlen(str);
		//printf("%c\n",str[1]);
		bsort(str,len);
		printf("case #%d:\n",i);
		printf("%s\n",str);
	}
	return 0;
}