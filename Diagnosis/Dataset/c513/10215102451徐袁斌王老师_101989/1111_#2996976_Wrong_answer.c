#include <stdio.h>
#include <stdlib.h>
int main()
{
    char a[41][41],b[100];
    while(scanf("%s",b)!=EOF)
    {
	    for(int i=0;i<41;i++)
	    {
			for(int j=0;j<41;j++)
			{
				if(i==20&&j!=40) a[i][j]='-';
				else if(i==20) a[i][j]='>';
				else if(i==0&&j==20) a[i][j]='^';
				else if(j==20) a[i][j]='|';
				else a[i][j]='.';
			}
		}
		int c[4]={0},d=1,ans=0;
		for(int i=5;b[i-1]!='\0';i++)
		{
			if(b[i]>='0'&&b[i]<='9')
			{
				while(b[i]>='0'&&b[i]<='9')
				{
					ans+=ans*10+b[i]-'0';
					i++;
				}
				i--;
			}
			else if(b[i]=='x')
			{
				if(b[i+1]=='^')  continue;
				else {c[1]=d*ans;ans=0;d=1;}
			}
			else if(b[i]=='^')
			{
				i++;
				c[b[i]-'0']=d*ans;
				ans=0;d=1;
			}
			else if(b[i]=='+') d=1;
			else if(b[i]=='-') d=-1;
			else if(b[i]=='\0')
			{
				c[0]=d*ans;
			}
		}
		for(int x=-20;x<=20;x++)
		{
			int k=c[0]+x*c[1]+x*x*c[2]+x*x*x*c[3];
			if(k>20||k<-20) continue;
			else a[20-k][20+x]='*';
		}
		for(int i=0;i<41;i++)
		{
			for(int j=0;j<41;j++) printf("%c",a[i][j]);
			printf("\n");
		}
	}

	
}