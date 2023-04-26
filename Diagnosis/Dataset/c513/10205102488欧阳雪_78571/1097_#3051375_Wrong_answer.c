#include<stdio.h>
#include<string.h>
int main()
{
	char s[100]={0};
	while(scanf("%s",s)!=EOF)
	{
		char b[200][100];
		int i=0,j=0;
		for(i=0;i<200;i++)
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
			b[100][1]=s[1];
			b[101][0]=s[0];
			j=100;
		}
		else if(s[1]>s[0])
		{
			b[101][1]=s[1];
			b[100][0]=s[0];
			j=101;
			
		}
		else{
			b[100][0]=s[0];
			b[100][1]=s[1];
			j=100;
		}
		int max=j,min=100;
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
			if(min>j)
			{
				min=j;
			}
		}
		for(int k1=max;k1>=min;k1--)
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
	}
    }
	return 0;
}