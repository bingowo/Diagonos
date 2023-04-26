#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int t,l=1;
	scanf("%d",&t);
	for(int j=0;j<t;j++)
	{
		char a[500]={0},b;
		scanf("%s",a);
		int i=1;b=a[0];
		printf("case #%d:\n",j);
		while(a[i]!='\0')
		{
			if(a[i]==b&&l<255)
			{
				l++;i++;
			}
			else if(a[i]!=b)
			{
				printf("%d%c",l,b);l=1;b=a[i];i++;
			}
			else
			{
				printf("255%c",b);i++;b=a[i];l=1;
			}
		}
		printf("%d%c",l,b);l=1;
		printf("\n");
	}

	
	
	

	
	return 0;
	
	
 } 