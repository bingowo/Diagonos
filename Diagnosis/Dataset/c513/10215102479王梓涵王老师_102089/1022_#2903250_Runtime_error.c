#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *a,const void *b)
{
	char *p1,*p2,*domain1,*domain2;
	int i=0;
	*p1=((char**)a);
	*p2=((char**)b);
	//用户名 
	while(*(p1+i)!='@') i++;
	//域名 
	domain1=p1+i+1;

	i=0;
	while(*(p2+i)!='@') i++;
	domain2=p2+i+1;
	
	//比较
	if(strcmp(domain1,domain2)==0) return strcmp(p2,p1);
	else return strcmp(domain2,domain1);
}

int main()
{
	int n;
	char **email;
	scanf("%d\n",&n);
	email=(char**)malloc(n*sizeof(char *));
	char s[1000001],*p;
	int i,len;
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		len=strlen(s);
		//动态分配空间，防止单独的邮件地址超出数据范围 
		p=(char *)malloc(len+1);
		//把输入的字符串复制到申请的动态空间中 
		strcpy(p,s);
		*(email+i)=p;
	}
	qsort(email,n,sizeof(char*),cmp);
	for(i=0;i<n;i++)
	{
		p=email[i];
		free(p);
	}
	free(email);
	return 0; 
}
