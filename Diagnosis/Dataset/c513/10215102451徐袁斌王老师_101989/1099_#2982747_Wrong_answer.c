#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int t;
	char x[32]={'0','0','E','T','I','A','N','M','S','U','R','W','D','K','G','O','H','V','F','0','L','0','P','J','B','X','C','Y','Z','Q','0'};
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		char a[1001];
		printf("case #%d:\n",i);
		scanf("%s",a);
		for(int j=0;a[j]!='\0';j++)
		{
			int b=1;
			if(a[j]=='/'&&a[j+1]=='/'&&a[j+2]=='/'&&a[j+3]=='/'&&a[j+4]=='/') {printf(".");j=j+5;}
			else if(a[j]=='/'&&a[j+1]=='/'&&a[j+2]=='/') {printf(" ");j=j+3;}
			else if(a[j]=='/'){j++;}
			
			while(a[j]!='/'&&a[j]!='\0')
			{
				if(a[j]=='.') {b*=2;j++;}
				else {b=b*2+1;j++;}
			}
			if(b==63) printf("0");
			else if(b==47) printf("1");
			else if(b==39) printf("2");
			else if(b==35) printf("3");
			else if(b==33) printf("4");
			else if(b==48) printf("6");
			else if(b==56) printf("7");
			else if(b==60) printf("8");
			else if(b==62) printf("9");
			else printf("%c",x[b]);
			j--;
		}
		printf("\n");
	}
}