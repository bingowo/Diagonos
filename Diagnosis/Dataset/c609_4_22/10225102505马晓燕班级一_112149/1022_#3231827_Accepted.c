#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp1(const void* a,const void *b)
{
	char *x =*((char **)a),*y =*((char **)b);
	char *domain_1, *domain_2;
	int i = 0;
	while(*(x+i)!='@')   i++;    	//查找字符@的位置 
	domain_1 = x + i + 1;              //domain1指向第一个邮件地址的主机域名
	i = 0;
	while(*(y+i)!='@')   i++;
	domain_2 = y + i + 1;           //domain2指向第二个邮件地址的主机域名

	if(strcmp(domain_1,domain_2) == 0)//主机域名相同
	{
		return strcmp(y,x); //用户名的字典序降序排序
	}else
		return strcmp(domain_1,domain_2);//主机域名的字典序升序排序
}

int main()
{
	int n,i,len;
	char  **email;
	scanf("%d",&n);
	email=(char **)malloc(n*sizeof(char *));   //动态分配指针数组空间
	char s[1000001],*p;
	for(i=0;i<n;i++)     
	{
		scanf("%s",s);
		len=strlen(s);
		p=(char *)malloc(len+1);        //动态分配邮件地址存储空间
		strcpy(p,s);
		*(email+i)=p;
	}

	qsort(email,n,sizeof(char*),cmp1);
	for(int i=0;i<n;i++)
	{
		printf("%s\n",email[i]);
	}
	for(i=0;i<n;i++)
	{ 
		p=email[i];  
		free(p);
	}
	free(email);
	
	return 0;
}