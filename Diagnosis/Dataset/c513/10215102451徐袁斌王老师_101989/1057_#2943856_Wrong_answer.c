#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int i=1,j=0,k=0;
	char w[1000],s[2000];
	scanf("%s",w);
	if(w[0]>='a'&&w[0]<='z')
	{
		s[1000]=w[0]-32;
	}	
	else s[1000]=w[0];
	while(w[i]!='\0')
	{
		if(w[i]>='a'&&w[i]<='z')
		{
			w[i]=w[i]-32;
		}
		else
		{
			if(w[i]>=s[1000-k])
			{
				printf("%c\n",w[i]);
				k++;
				s[1000-k]=w[i];
				i++;
			}
			else
			{
				j++;
				s[1000+j]=w[i];
				i++;
			}
		}
	}
	for(int i=0;i<=j+k;i++)
	{
		printf("%c",s[1000-k+i]);
	}
	return 0;
	
	
 } 