#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int n;
typedef struct{
	int flag;
	char num[500],ori[200];
}Node;
Node a[1005];
int cmp(const void *e1,const void *e2){
	Node x=*(Node *)e1,y=*(Node*)e2;
	if(x.flag!=y.flag)
		return x.flag-y.flag;
	else if(x.flag==1)
		return strcmp(x.num,y.num);
	else 
		return strcmp(y.num,x.num);
}
int main()
{
	scanf("%d",&n);
	char s[10000];
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		int pos=-1,flag=1,len=strlen(s);
		strcpy(a[i].ori,s);
		for(int j=0;j<len;j++)
		{
			if(s[j]=='-')
				flag=-1;
			if(s[j]=='.')
				pos=j;
		}	
		if(pos==-1)
			pos=len;
		for(int j=0;j<400;j++)
			a[i].num[j]='0';
		for(int j=0;j<len;j++)
			if(s[j]!='-'&&s[j]!='+')
				a[i].num[200-pos+j]=s[j];
		a[i].num[200]='.';
		a[i].num[400]='\0';
		a[i].flag=flag;
	}
	qsort(a+1,n,sizeof(Node),cmp);
	for(int i=1;i<=n;i++)
		printf("%s\n",a[i].ori);
	return 0;
 } 