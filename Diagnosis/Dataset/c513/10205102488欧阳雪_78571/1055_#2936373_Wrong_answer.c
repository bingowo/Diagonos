#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 1000000
int main()
{
	char s[M]={0};
	scanf("%s",s);
	char ls[1000][1000]={0};
	int a[200]={0};
	int t=0,j=0;
	//printf("s:%s\n",s);
	for(int i=0;i<strlen(s);i++)
	{
		int k=i;
		//printf("k:%d\n",k);
		while(a[s[k]]<2&&s[k])
		{
			ls[t][j]=s[k];
			j++;
			k++;
			a[s[k]]++;
		}
		a[s[k]]++;
		j=0;
		t++;
	}
	int MAX=0,temp=0;
	for(int k1=0;k1<t;k1++)
	{
		if(strlen(ls[k1])>MAX){
			MAX=strlen(ls[k1]);
			temp=k1;
		}
	}
	printf("%s",ls[temp]);
 } 