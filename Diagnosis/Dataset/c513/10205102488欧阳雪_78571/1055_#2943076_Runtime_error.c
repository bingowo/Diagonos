#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 100000
int main()
{
	char s[M]={0};
	scanf("%s",s);
	//char ls[1000][1000]={0};
	char ls[M]={0}; 
	int t=0,j=0;
	//printf("s:%s\n",s);
	char temp[M]={0};//用以记录上次遍历的得到的串 
	for(int i=0;i<strlen(s);i++)
	{
		int a[200]={0};//标记s[i]出现个数
		int k=i;
		a[s[k]]++;
		//printf("k:%d\n",k);
		while(a[s[k]]<2&&s[k])
		{
			ls[j]=s[k];
			j++;
			k++;
			a[s[k]]++;
		}
		ls[j]=0;
		//printf("ls:%s\n",ls);
		j=0;
		if(strlen(ls)>strlen(temp)){
			strcpy(temp,ls);
		}
	}
	printf("%s",temp);
/*	int MAX=0,temp=0;
	for(int k1=0;k1<t;k1++)
	{
		if(strlen(ls[k1])>MAX){
			MAX=strlen(ls[k1]);
			temp=k1;
		}
	}
	printf("%s",ls[temp]);*/
 } 