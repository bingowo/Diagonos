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
	int i1=0;
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
		strcpy(wz[i1].s,temp);
		j=j+3;
		int k=0;
		while(wz[i1].s[j]!='/')
		{
			wz[i1].ym[k++]=wz[i1].s[j];
			j++;
		}
		int t=0;
		while(wz[i1].s[j]!='\0')
		{
			wz[i1].vs[t++]=wz[i1].s[j];
			j++;
		}
		i1++; 
	}
	qsort(wz,i1,sizeof(wz[0]),cmp);
	for(i=0;i<i1;i++)
	{
		printf("%s\n",wz[i].s);
	}
	return 0;
}