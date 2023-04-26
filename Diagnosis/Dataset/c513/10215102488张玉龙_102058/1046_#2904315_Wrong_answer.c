#include<stdio.h>
#include<string.h>
int main(){
	char s[10][101];
	int i,n;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		gets(s[i]);
	}
	for(i=0;i<n;i++)
	{	int m=1;
		for(int k=0;s[i][k]!='\0';k++)
		{
			if((int)s[i][k]==32)
			m++;
			if(s[i][k]=='a'&&(s[i][k-1]==' ')||(s[i][k-1]=='\0')&&(s[i][k+1]==' ')||(s[i][k+1]==' '))
			m--;
		}
		printf("%d\n",m);
	}
} 
