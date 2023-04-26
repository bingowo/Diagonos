#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct data{
	char s[500];
	char ym[300];
	char vs[300];
}wz[100];
int cmp(const void*a,const void*b)
{
	struct data aa=*(struct data*)a;
	struct data bb=*(struct data*)b;
	if(strcmp(aa.ym ,bb.ym )!=0)
	{
		return strcmp(aa.ym ,bb.ym );
	 } 
	else
	{
		return strcmp(aa.vs ,bb.vs );
	}
	
}
int main()
{
	int n;
	scanf("%d",&n);
	int i=0;
	char temp[500]={0};
	for(i=0;i<n;i++)
	{
		scanf("%s",temp);
		int j=0;
		while(temp[j]!=':')
		{
			j++;
		}
		if(temp[j-1]=='s')
		{
			continue;
		}
		strcpy(wz[i].s,temp);
		j=j+3;
		int k=0;
		while(wz[i].s[j]!='/')
		{
			wz[i].ym[k++]=wz[i].s[j];
			j++;
		}
		int t=0;
		while(wz[i].s[j]!='\0')
		{
			wz[i].vs[t++]=wz[i].s[j];
			j++;
		}
	}
	qsort(wz,n,sizeof(wz[0]),cmp);
	for(i=0;i<n;i++)
	{
		while(strcmp(wz[i].s,wz[i+1].s)==0)
		{
			i++;
		}
		printf("%s\n",wz[i].s);
	}
	return 0;
}