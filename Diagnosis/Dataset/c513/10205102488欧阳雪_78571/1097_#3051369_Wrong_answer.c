#include<stdio.h>
#include<string.h>
int main()
{
	char s[100]={0};
	while(scanf("%s",s)!=EOF)
	{
		char b[100][100];
		int i=0,j=0;
		for(i=0;i<100;i++)
		{
			for(j=0;j<100;j++)
			{
				b[i][j]=' ';
			}
		}
		if(strlen(s)==1)
		{
			printf("%s\n",s);
			continue;
		}
		else
		{
		if(s[1]<s[0])
		{
			b[0][1]=s[1];
			b[1][0]=s[0];
			j=0;
		}
		else if(s[1]>s[0])
		{
			b[1][1]=s[1];
			b[0][0]=s[0];
			j=1;
			
		}
		else{
			b[0][0]=s[0];
			b[0][1]=s[1];
			j=0;
		}
		int max=j;
		for(i=2;i<strlen(s);i++)
		{
			if(s[i]>s[i-1])
			{
				b[j+1][i]=s[i];
				j++;
			}
			else if(s[i]<s[i-1])
			{
				b[j-1][i]=s[i];
				j--;
			}
			else{
				b[j][i]=s[i];
			}
			if(max<j){
				max=j;
			}
		}
		for(int k1=max;k1>=0;k1--)
		{
			int k2=99;
			while(k2>=0)
			{
				if(b[k1][k2]=='B')
				{
					k2--;
					continue;
				}
				else break;
			}
			for(int t=0;t<=k2;t++)
			{
				printf("%c",b[k1][t]);
			}
			printf("\n");
		}
		printf("\n");
	}
    }
	return 0;
}